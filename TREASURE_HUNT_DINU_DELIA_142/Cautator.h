#ifndef CAUTATOR_H
#define CAUTATOR_H
#include "Harta.h"
#include <iostream>

using namespace std;


class Cautator                                            // clasa abstracta
{
protected:
    int stare_cautator;
    int castigator;
    int x,y;                                               // coordonatele pozitiei curente ale jucatorului
public:
    Cautator();                                            // connstructor fara parametri
    ~Cautator();                                           // destructor
    virtual void deplasare_stanga(Harta &my_harta)=0;      //metoda care pentru fiecare tip de cautator va pune o anumita cifra si culoare pe harta
    virtual  void deplasare_dreapta(Harta &my_harta)=0;
    virtual void deplasare_sus(Harta &my_harta)=0;
    virtual void deplasare_jos(Harta &my_harta)=0;
    int verificare_deplasare_stanga(Harta &my_harta);      //metoda care verifica daca jucatorul se poate deplasa intr-o anumita directie
    int verificare_deplasare_dreapta(Harta &my_harta);
    int verificare_deplasare_sus(Harta &my_harta);
    int verificare_deplasare_jos(Harta &my_harta);
    int GetStare();                                        // metoda care returneaza daca jucatorul mai poate face deplasari sau nu
    int GetCastigator();                                   // metoda care returneaza daca jucatorul a gasit o comoara
    void SetStare(int);                                    // metoda care schimba starea jucatorului
    void SetCastigator(int);                               // metoda care face jucatorul castigator
    int GetLinieCautator();                                // metoda care returneaza linia pe care se plaseaza jucatorul
    int GetColoanaCautator();                              // metoda care returneaza coloana pe care se plaseaza jucatorul


};


class Cautator1: public Cautator                         // cele patru tipuri de cautatori derivati din clasa Cautator
{


public:
    Cautator1() : Cautator()
    {
        x = 0;                                            // coordonatele initiale ale cautatorului 1
        y = 0;
    }
    ~Cautator1() {};
void deplasare_jos(Harta &my_harta)
{
        x++;                                              // schimb coordonatele pozitiei curente ale cautatorului
        my_harta.GetTabla()[x][y]=1;                      // pun pe harta de joc cifra corespunzatoare jucatorului
        my_harta.GetColors()[x][y]=14;                    // schimb culoare pentru coordonatele pozitiei curente  pe matricea de culoare
}

void deplasare_sus(Harta &my_harta)
{
    x--;
    my_harta.GetTabla()[x][y]=1;
    my_harta.GetColors()[x][y]=14;
}
void deplasare_dreapta(Harta &my_harta)
{
    y++;
    my_harta.GetTabla()[x][y]=1;
    my_harta.GetColors()[x][y]=14;
}

void deplasare_stanga(Harta &my_harta)
{
    y--;
    my_harta.GetTabla()[x][y]=1;
    my_harta.GetColors()[x][y]=14;
}
};

class Cautator2: public Cautator
{

public:

    Cautator2() : Cautator()
    {

        x = 0;
        y = 14;

    }
    ~Cautator2() {};

void deplasare_jos(Harta &my_harta)
{
        x++;
        my_harta.GetTabla()[x][y]=2;
        my_harta.GetColors()[x][y]=13;
}

void deplasare_sus(Harta &my_harta)
{
    x--;
    my_harta.GetTabla()[x][y]=2;
    my_harta.GetColors()[x][y]=13;
}
void deplasare_dreapta(Harta &my_harta)
{
    y++;
    my_harta.GetTabla()[x][y]=2;
    my_harta.GetColors()[x][y]=13;
}

void deplasare_stanga(Harta &my_harta)
{
    y--;
    my_harta.GetTabla()[x][y]=2;
    my_harta.GetColors()[x][y]=13;
}
};

class Cautator3: public Cautator
{
public:

    Cautator3() : Cautator()
    {

        x = 14;
        y = 0;
    }
    ~Cautator3() {};
void deplasare_jos(Harta &my_harta)
{
        x++;
        my_harta.GetTabla()[x][y]=3;
        my_harta.GetColors()[x][y]=10;
}

void deplasare_sus(Harta &my_harta)
{
    x--;
    my_harta.GetTabla()[x][y]=3;
    my_harta.GetColors()[x][y]=10;
}
void deplasare_dreapta(Harta &my_harta)
{
    y++;
    my_harta.GetTabla()[x][y]=3;
    my_harta.GetColors()[x][y]=10;
}

void deplasare_stanga(Harta &my_harta)
{
    y--;
    my_harta.GetTabla()[x][y]=3;
    my_harta.GetColors()[x][y]=10;
}
};

class Cautator4: public Cautator
{


public:

    Cautator4()
    {

        x = 14;
        y = 14;
    }
    ~Cautator4() {};
void deplasare_jos(Harta &my_harta)
{
        x++;
        my_harta.GetTabla()[x][y]=4;
        my_harta.GetColors()[x][y]=11;
}

void deplasare_sus(Harta &my_harta)
{
    x--;
    my_harta.GetTabla()[x][y]=4;
    my_harta.GetColors()[x][y]=11;
}
void deplasare_dreapta(Harta &my_harta)
{
    y++;
    my_harta.GetTabla()[x][y]=4;
    my_harta.GetColors()[x][y]=11;
}

void deplasare_stanga(Harta &my_harta)
{
    y--;
    my_harta.GetTabla()[x][y]=4;
    my_harta.GetColors()[x][y]=11;
}
};

#endif // CAUTATOR_H
