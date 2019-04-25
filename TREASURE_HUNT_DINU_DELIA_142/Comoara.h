#ifndef COMOARA_H
#define COMOARA_H
#include "Harta.h"
#include <iostream>

using namespace std;



class Comoara
{

int x;                                   // coordonatele comorii
int y;
int stare_comoara;                       // variabila care arata daca comoara a fost gasita sau nu

public:
    Comoara(Harta &my_harta);            // constructor care are ca parametru harta pe care va fi plasata
    ~Comoara();                          // destructor
    int GetStareComoara();               // metoda care returneaza daca comoara a fost gasita sau nu
    int GetLinieComoara();               // metoda care returneaza daca comoara a fost gasita sau nu
    int GetColoanaComoara();
    void SetStareComoara(int x);          // metoda care modifica starea comorii

};

#endif // COMOARA_H
