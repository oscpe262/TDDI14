/*
 * uppgift1.cc
 *
 * Namn, pnr:
 */
#include <iostream>
using namespace std;

// Definiera klasserna här.

void print(const Washing_Equipment* p)
{
   // Skapa en kopia av objektet som p pekar på.

   // Skriv ut data för kopian, i enlighet följande:
   //
   //   WE1486WM, tvättmaskin: 8 kg, 1400 rpm, energiklass A+
   //   WE6756CD, kondenstorkare: 7.5 kg, energiklass B
   //   WE1809TD, torktumlare: energiklass C
   //   WE6570DW, diskmakin: 12 kuvert, 47 dB, energiklass A

   // Destruera kopian.
}

int main()
{
   // Deklarera en pekare för varje konkret typ och skapa ett motsvarande
   // objekt dynamisk (new). Använd följande data för att initiera objekten:
   //
   // Washing_Machine: modellkod WE1486WM, energiklass A+, kapacitet 8.0 kg, varvtal 1400 rpm
   // Condenser_Dryer: modellkod WE6756CD, energiklass B, kapacitet 7.5 kg
   // Tumble_Dryer...: modellkod WE1809TD, energiklass C
   // Dish_Washer....: modellkod WE6570DW, energiklass A, kapacitet 12 kuvert, ljudnivå 47 dB

   // Anopa print() för varje pekare/objekt.

   // Destruera alla objekt.

   return 0;
}
