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

const string Calculator::valid_command_("?HUBPTQILNRA");

/**
 * run() är huvudfunktionen för kalkylatorn. Skriver först ut hur man använder
 * kalkylatorn och läser sedan sedan in ett kommando i taget och utför det.
 */
void
Calculator::
run()
{
   cout << "Välkommen till Kalkylatorn!\n\n";
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
      // Undantag som inte tillhör exception avbryter programkörningen!
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
   cout << "  B     Beräkna aktuellt uttryck\n";
   cout << "  B n   Beräkna uttryck n i historiken\n";
   cout << "  I     Visa aktuellt uttryck som infix\n";
   cout << "  I n   Visa uttryck n som infix\n";
   cout << "  L     Lista alla uttryck som infix\n";
   cout << "  P     Visa aktuellt uttryck som postfix\n";
   cout << "  P n   Via uttryck n som postfix\n";
   cout << "  T     Visa aktuellt uttryck som träd\n";
   cout << "  T n   Visa uttryck n som träd\n";
   cout << "  N     Visa antal lagrade uttryck\n";
   cout << "  A     Gör uttryck n till aktuellt uttryck\n";
   cout << "  R     Radera aktuellt uttryck\n";
   cout << "  R n   Radera uttryck n\n";
   cout << "  V     Lista alla variabler\n";
   cout << "  X     Radera alla variabler\n";
   cout << "  Q     Avsluta kalkylatorn\n";
}

/**
 * get_command() läser ett kommando (ett tecken), gör om till versal och lagrar
 * kommandot i medlemmen command_ för vidare behandling av andra operationer. 
 * Ingen kontroll görs om det skrivits mer, i så fall skräp, på kommandoraden.
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
 * tillhör den tillåtna kommandorepertoraren och returnerar antingen true
 * (giltigt kommando) eller false (ogiltigt kommando).
 */
bool
Calculator::
valid_command() const
{
   if (valid_command_.find(command_) == string::npos)
   {
      cout << "Otillåtet kommando: " << command_ << "\n";
      return false;
   }
   return true;
}

/**
 * execute_command() utför kommandot som finns i medlemmen command_. Kommandot
 * förutsätts ha kontrollerats med valid_command() och alltså är ett giltigt 
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
   else if (command_ == 'B')     
     cout << exp_history_.at(c_arg_).evaluate() << "\n";
   else if (command_ == 'I')
     cout << exp_history_.at(c_arg_).get_infix() << "\n";
   else if (command_ == 'L') {
       int i {1};
       for( Expression expr : exp_history_ )
	 { cout << i++ << ": "<< expr.get_infix() << "\n"; }
   }
   else if (command_ == 'P')
     cout << exp_history_.at(c_arg_).get_postfix() << "\n";
   else if (command_ == 'T')
     exp_history_.at(c_arg_).print_tree(cout);
   else if (command_ == 'N')
     cout << exp_history_.size() << "\n";
   else if (command_ == 'A') {
     exp_history_.push_front (exp_history_.at(c_arg_));
     exp_history_.erase (exp_history_.begin()+c_arg_+1); // Om vi vill ta bort det ur historiken
   }
   else if (command_ == 'R')
     exp_history_.erase (exp_history_.begin()+c_arg_);
   else if (command_ == 'Q') 
     cout << "Kalkylatorn avlutas, välkommen åter!\n";
   else
     cout << "Detta ska inte hända!\n";
}

/**
 * read_expression() läser ett infixuttryck från inströmmen is och ger detta 
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
