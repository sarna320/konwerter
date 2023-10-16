#ifndef INTERFEJS_H
#define INTERFEJS_H

#include <iostream>
#include "../header/check.h"
#include "../header/obliczenia.h"

using namespace std;

char wyborSystemu();
string wyborLiczby();
void konwertB(string liczba, char nowySystemLiczby);
void konwertD(string liczba, char nowySystemLiczby);
void konwertO(string liczba, char nowySystemLiczby);
void konwertH(string liczba, char nowySystemLiczby);
void interfejs();

#endif // INTERFEJSC_H