/*
 * uppgift1.cc
 *
 * Namn, pnr:
 */
#include <iostream>
using namespace std;

// Definiera klasserna h�r.

void print(const Washing_Equipment* p)
{
   // Skapa en kopia av objektet som p pekar p�.

   // Skriv ut data f�r kopian, i enlighet f�ljande:
   //
   //   WE1486WM, tv�ttmaskin: 8 kg, 1400 rpm, energiklass A+
   //   WE6756CD, kondenstorkare: 7.5 kg, energiklass B
   //   WE1809TD, torktumlare: energiklass C
   //   WE6570DW, diskmakin: 12 kuvert, 47 dB, energiklass A

   // Destruera kopian.
}

int main()
{
   // Deklarera en pekare f�r varje konkret typ och skapa ett motsvarande
   // objekt dynamisk (new). Anv�nd f�ljande data f�r att initiera objekten:
   //
   // Washing_Machine: modellkod WE1486WM, energiklass A+, kapacitet 8.0 kg, varvtal 1400 rpm
   // Condenser_Dryer: modellkod WE6756CD, energiklass B, kapacitet 7.5 kg
   // Tumble_Dryer...: modellkod WE1809TD, energiklass C
   // Dish_Washer....: modellkod WE6570DW, energiklass A, kapacitet 12 kuvert, ljudniv� 47 dB

   // Anopa print() f�r varje pekare/objekt.

   // Destruera alla objekt.

   return 0;
}
