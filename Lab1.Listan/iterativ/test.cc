#include "List.h"
#include <iostream>
#include <utility>

using namespace std;

int main() {
  List lista_1;
  List lista_2(lista_1);
  // kopieringskonstruktorn används
  List lista_3(std::move(lista_1)); // move-konstruktorn används (om den finns)
  lista_1 = std::move(lista_2);
  List lista{1,2,3,4,5};
}
