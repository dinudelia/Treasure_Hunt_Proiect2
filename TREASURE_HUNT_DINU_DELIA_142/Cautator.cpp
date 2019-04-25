#include "Cautator.h"
#include <iostream>

using namespace std;

Cautator::Cautator()
{
    stare_cautator=1;                                                         // initializez stare cautatorului cu 1 la inceputul jocului si 0 pentru castigator
    castigator=0;
}


Cautator::~Cautator()
{

}

int Cautator::GetLinieCautator()
{
    return x;
}

int Cautator::GetColoanaCautator()
{
    return y;
}


int Cautator :: verificare_deplasare_sus(Harta &my_harta){
  if(x-1 >= 0 && x-1 <= 14)
  if(my_harta.GetTabla()[x-1][y]==0 || my_harta.GetTabla()[x-1][y]==10)    // verific daca nu ies din matrice si daca pozitia nu a fost vizitata dejs
       return 1;
  return 0;
}
int Cautator :: verificare_deplasare_jos(Harta &my_harta){
    if(x+1 >= 0 && x+1 <= 14)

  if(my_harta.GetTabla()[x+1][y]==0 || my_harta.GetTabla()[x+1][y]==10)
       return 1;
  return 0;
}
int Cautator :: verificare_deplasare_stanga(Harta &my_harta)
{
    if(y-1 >= 0 && y-1 <= 14)

  if(my_harta.GetTabla()[x][y-1]==0 || my_harta.GetTabla()[x][y-1]==10)
       return 1;
  return 0;
}


int Cautator :: verificare_deplasare_dreapta(Harta &my_harta){
    if(y+1 >= 0 && y+1 <= 14)
        if(my_harta.GetTabla()[x][y+1]==0 || my_harta.GetTabla()[x][y+1]==10 )
            return 1;
  return 0;
}
int Cautator ::GetStare()
{
    return stare_cautator;
}

void Cautator:: SetStare(int x)
{
    stare_cautator=x;
}

void Cautator:: SetCastigator( int x)
{
    castigator=x;
}

int Cautator::GetCastigator()
{
    return castigator;
}
