/*
 * uppgift1.cc
 */
#include <vector>
using namespace std;

// Definiera Grill-klasserna h�r!

void print(const Grill* p)
{
   // Skriv ut data f�r Grill-objektet som p pekar p�, enligt f�ljande exempel:
   //   Grill C-1900
   //   Grill LPG-4702, 2 br�nnare, Propan
   //   Grill LPGS-4704, 4+1 br�nnare, Butan
}

int main()
{
   // Skapa ett objekt av respektive konkret typ dynamiskt, och respektive pekare
   // i vectorn grills nedan. Initiera objekten enligt f�ljande:
   //   Grill_Charcoal: modell C-1900
   //   Grill_LPG: modell LPG-4702, 2 br�nnare
   //   Grill_LPG_Sideburner: modell LPGS-4704, 4 br�nnare (sidobr�nnare or�knad), Butan

   vector<Grill*> grills;

   // Stega igenom vectorn grills och g�r f�ljande f�r varje element:
   // - Anropa funktionen print() f�r att skriva ut data f�r grilltypen ifr�ga.
   // - Destruera objektet ifr�ga.
   // - S�tt motsvarande element i vectorn till nullptr.
   
   return 0;
}
