/*
 * uppgift1.cc
 */
#include <vector>
using namespace std;

// Definiera Grill-klasserna här!

void print(const Grill* p)
{
   // Skriv ut data för Grill-objektet som p pekar på, enligt följande exempel:
   //   Grill C-1900
   //   Grill LPG-4702, 2 brännare, Propan
   //   Grill LPGS-4704, 4+1 brännare, Butan
}

int main()
{
   // Skapa ett objekt av respektive konkret typ dynamiskt, och respektive pekare
   // i vectorn grills nedan. Initiera objekten enligt följande:
   //   Grill_Charcoal: modell C-1900
   //   Grill_LPG: modell LPG-4702, 2 brännare
   //   Grill_LPG_Sideburner: modell LPGS-4704, 4 brännare (sidobrännare oräknad), Butan

   vector<Grill*> grills;

   // Stega igenom vectorn grills och gör följande för varje element:
   // - Anropa funktionen print() för att skriva ut data för grilltypen ifråga.
   // - Destruera objektet ifråga.
   // - Sätt motsvarande element i vectorn till nullptr.
   
   return 0;
}
