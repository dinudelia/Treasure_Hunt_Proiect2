#ifndef HARTA_H
#define HARTA_H
#include <iostream>

using namespace std;


class Harta
{
    int **tabla;                                    // matricea pe care se va desfasura jocul
    int **colors;                                   // matricea in care se vor pastra culorile pentru fiecare element de pe tabla
    public:
        Harta();                                    // constructor pentru harta fara parametri
       ~Harta();
       void afisare();                             // metoda care afiseaza tabla de joc
       int** GetTabla() {return tabla;}            // metoda care returneaza matricea cu tabla de joc
       int** GetColors() {return colors;}          // metoda care returneaza matricea cu culori
};

#endif // HARTA_H
