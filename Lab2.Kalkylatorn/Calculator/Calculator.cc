/*
 * Calculator.cc
 */
#include "Expression_Tree.h"
#include "Expression.h"
#include "Calculator.h"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

const string Calculator::valid_command_("?HUBPTQ");

/**
 * run() �r huvudfunktionen f�r kalkylatorn. Skriver f�rst ut hur man anv�nder
 * kalkylatorn och l�ser sedan sedan in ett kommando i taget och utf�r det.
 */
void
Calculator::
run()
{
   cout << "V�lkommen till Kalkylatorn!\n\n";
   print_help();

   do 
   {
      try 
      {
	 get_command();
	 if (valid_command())
	   execute_command();
      }
      catch (const exception& e) 
      {
	 cout << e.what() << '\n';
      }
      // Undantag som inte tillh�r exception avbryter programk�rningen!
   }
   while (command_ != 'Q');
}

/**
 * print_help() skriver ut kommandorepertoaren.
 */
void
Calculator::
print_help() const
{
   cout << "  H, ?  Skriv ut denna information\n";
   cout << "  U     Mata in ett nytt uttryck\n";
   cout << "  B     Ber�kna aktuellt uttryck\n";
   cout << "  P     Visa aktuellt uttryck som postfix\n";
   cout << "  T     Visa aktuellt uttryck som tr�d\n";
   cout << "  Q     Avsluta kalkylatorn\n";
}

/**
 * get_command() l�ser ett kommando (ett tecken), g�r om till versal och lagrar
 * kommandot i medlemmen command_ f�r vidare behandling av andra operationer. 
 * Ingen kontroll g�rs om det skrivits mer, i s� fall skr�p, p� kommandoraden.
 */
void
Calculator::
get_command()
{
   cout << ">> ";

   cin >> command_;
   command_ = toupper(command_); 

   string temp;
   getline ( cin, temp, '\n');
   istringstream iss {temp};

   if( iss >> c_arg_ >> ws && iss.eof()) // Argument och kommando funna
     {
       if (c_arg_ > ( exp_history_.size()+1 ) ) // Argument in range?
	 {
	   // THROW EXCEPTION
	 }       
       c_arg_ -= 1;
     }
   else if ( iss.eof() )
     {
       c_arg_ = 0; // Hittade ej argument, giltigt kommando, set c_arg_ to default  
     }
   else
     {
       // THROW EXCEPTION
     }
   
}

/**
 * valid_command() kontrollerar om kommandot som finns i medlemmen command_
 * tillh�r den till�tna kommandorepertoraren och returnerar antingen true
 * (giltigt kommando) eller false (ogiltigt kommando).
 */
bool
Calculator::
valid_command() const
{
   if (valid_command_.find(command_) == string::npos)
   {
      cout << "Otill�tet kommando: " << command_ << "\n";
      return false;
   }
   return true;
}

/**
 * execute_command() utf�r kommandot som finns i medlemmen command_. Kommandot
 * f�ruts�tts ha kontrollerats med valid_command() och allts� �r ett giltigt 
 * kommando.
 */
void
Calculator::
execute_command()
{
   if (command_ == 'H' || command_ == '?')
     print_help();
   else if (command_ == 'U')
     read_expression(cin);
   else if (command_ == 'B') {    
     cout << exp_history_.at(c_arg_).evaluate() << "\n";
   }
   else if (command_ == 'P')
     cout << exp_history_.at(c_arg_).get_postfix() << "\n";
   else if (command_ == 'T')
     exp_history_.at(c_arg_).print_tree(cout);
   else if (command_ == 'Q') 
     cout << "Kalkylatorn avlutas, v�lkommen �ter!\n";
   else
     cout << "Detta ska inte h�nda!\n";
}

/**
 * read_expression() l�ser ett infixuttryck fr�n instr�mmen is och ger detta 
 * till funktionen make_expression() som returnerar ett objekt av typen 
 * Expression, vilket lagras som "aktuellt uttryck" i current_expression_.
 */
void
Calculator::
read_expression(istream& is)
{
   string infix;

   is >> ws;

   if (getline(is, infix))
   {
      current_expression_ = make_expression(infix);
      exp_history_.push_front(current_expression_);
   }
   else
   {
      cout << "Felaktig inmatning!\n";
   }
}
