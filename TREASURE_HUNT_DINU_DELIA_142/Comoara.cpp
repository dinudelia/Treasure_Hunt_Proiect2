#include "Comoara.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

Comoara::Comoara(Harta &my_harta)
{

   x = rand()%15;                                                       // generare de pozitii random
   y = rand()%15;
   while((x==0&&y==0)||(x==0&&y==14)||(x==14&&y==0)||(x==14&&y==14))    // se genereaza in continuare pozitii random daca acestea au picat prima data in colturile tablei de joc
   {
       x=rand()%15;
       y=rand()%15;
   }

   my_harta.GetTabla()[x][y] = 10;                                     // marchez pe tabla de joc 10 pentru fiecare comoara
   my_harta.GetColors()[x][y] = 12;                                    // setez culoarea comorii si pe matricea de culoare
   stare_comoara = 0;
}

Comoara::~Comoara()
{

}

int Comoara:: GetStareComoara()
{
    return stare_comoara;
}

int Comoara:: GetLinieComoara()
{
    return x;
}

int Comoara:: GetColoanaComoara()
{
    return y;
}

void Comoara::SetStareComoara(int x)
{
    stare_comoara=x;
}
