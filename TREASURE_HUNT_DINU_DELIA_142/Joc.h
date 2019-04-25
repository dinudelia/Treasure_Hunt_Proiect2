#ifndef JOC_H
#define JOC_H
#include "Cautator.h"
#include "Harta.h"
#include "Comoara.h"
#include <iostream>
#include <vector>
using namespace std;

class Joc
{
    Harta harta;
    vector <Cautator*> cautatori;                // vector de cautatori
    Comoara comoara1, comoara2, comoara3;

    public:
        Joc();
        ~Joc();
        void start_joc();                       // metoda prin care se desfasoara jocul

};

#endif // JOC_H
