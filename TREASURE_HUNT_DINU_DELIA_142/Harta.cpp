#include "Harta.h"
#include <iostream>
#include <windows.h>
using namespace std;

Harta::Harta()
{
    int i,j;

    tabla=new int*[15];
    for(i=0;i<15;i++)
        tabla[i]=new int[15];                    // aloc memorie pentru matricea tablei de joc


    for(i=0;i<15;i++)
        for(j=0;j<15;j++)
        tabla[i][j]=0;                         // initializez tabla de joc cu 0

    tabla[0][0]=1;                             // pun pozitiile principale ale cautatorilor
    tabla[0][14]=2;
    tabla[14][0]=3;
    tabla[14][14]=4;

    colors=new int*[15];
    for(i=0;i<15;i++)
        colors[i]=new int[15];                // aloc memorie pentru matricea de culoare

    for(i=0;i<15;i++)
        for(j=0;j<15;j++)
            colors[i][j]=8;                  // initializez matricea de culoare


    colors[0][0]=14;                         // pun culoare corespunzatoare fiecarui jucator pe pozitia principala
    colors[0][14]=13;
    colors[14][0]=10;
    colors[14][14]=11;

}

Harta::~Harta()
{
    for(int i=0;i<15;i++)
        delete [] tabla[i];
    delete tabla;                            // dezaloc memoria

        for(int i=0;i<15;i++)
        delete [] colors[i];
    delete colors;

}

void Harta::afisare()
{
    int i, j;

    for(i=0; i<15; i++)
       {
        for(j=0; j<15; j++)
          {
              HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

              SetConsoleTextAttribute(hConsole, colors[i][j]);         // resetez culoarea care este salvata in matricea de culoare inainte de a afisa
              cout << tabla[i][j] << " ";

          }
      cout<<endl;
       }

}
