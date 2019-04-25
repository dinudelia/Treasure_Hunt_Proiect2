#include "Joc.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

Joc::Joc() :comoara1(harta),comoara2(harta),comoara3(harta)
{

    Cautator *x= new Cautator1();                               // introduc in vectorul de cautatori cate un cautator de fiecare tip
    cautatori.push_back(x);

    x= new Cautator2();
    cautatori.push_back(x);

    x= new Cautator3();
    cautatori.push_back(x);

    x= new Cautator4();
    cautatori.push_back(x);
}

Joc::~Joc()
{

}


void Joc:: start_joc()                                                             // desfasurarea propriu-zisa a jocului
{
    int ok=1, i,verif,x, y=0, locul1=0, locul2=0, locul3=0, k, contor=0, conto2;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    harta.afisare();
    cout<<endl;
    char key;
    while(ok==1)                                                                   // ok este o variabila care isi schimba valoarea atunci cand jocul nu mai poate continua
        for(i=0; i<=3; i++)                                                        // parcurg vectorul de cautatori cat timp ok este inca 1
        {
            y=0;                                                                   // y este o variabila care verifica daca s-a efectuat o deplsare

            if(cautatori[i]->GetStare()!=0 && cautatori[i]->GetCastigator()==0)    // daca cautatorul este inca in joc verific daca poate face o deplasare citita de la tastatura
                                                                                   // voi incerca o deplsare pana i momentul in care gasesc una care poate fi efectuata
              {
                k=0;                                                              // k este o variabila cu care verific daca am incercat toate deplasarile
                SetConsoleTextAttribute(hConsole, 15);
                if(i==0)   cout<<" Deplasare cautator A: ";
           else if(i==1)   cout<<" Deplasare cautator B: ";
           else if(i==2)   cout<<" Deplasare cautator C: ";
           else if(i==3)   cout<<" Deplasare cautator D: ";
                while(y==0)
                {

                    key=getch();
                    int value=key;
                    if (value==KEY_LEFT)
                    {
                        if(cautatori[i]->verificare_deplasare_stanga(harta)==1)
                        {
                            y=1;
                            if((harta.GetTabla())[cautatori[i]->GetLinieCautator()][cautatori[i]->GetColoanaCautator()-1]==10)
                            {
                                cautatori[i]->SetCastigator(1);                  // daca deplsarea poate fi efectuata, verific daca este o comoara pe casuta urmatoare
                                if(locul1==0)                                    // verific pe ce loc se claseaza jucatorul daca a gasit comoara si ii fac starea ib 0 ca sa nu mai poata juca
                                    locul1=i;
                                else if(locul2==0)
                                    locul2=i;
                                else if(locul3==0)
                                    locul3=i;
                            if(i==0)   cout<<endl<<endl<<" Jucatorul A a gasit o comoara "<<endl;
                            if(i==1)   cout<<endl<<endl<<" Jucatorul B a gasit o comoara "<<endl;
                            if(i==2)   cout<<endl<<endl<<" Jucatorul C a gasit o comoara "<<endl;
                            if(i==3)   cout<<endl<<endl<<" Jucatorul D a gasit o comoara "<<endl;
                                contor++;                                       // contor este o variabila cu care contorizez cati jucatori au castigat sau nu mai au deplasari posibile

                            }
                            cautatori[i]->deplasare_stanga(harta);
                            cout<<endl;
                            harta.afisare();
                            cout<<endl<<endl;
                            if(contor==3) {ok=0;break;}
                        }
                        k++;

                    }
                    else if (value==KEY_RIGHT)
                    {
                        if(cautatori[i]->verificare_deplasare_dreapta(harta)==1)
                        {
                            y=1;
                             if(harta.GetTabla()[cautatori[i]->GetLinieCautator()][cautatori[i]->GetColoanaCautator()+1]==10)
                            {
                                cautatori[i]->SetCastigator(1);
                                if(locul1==0)
                                    locul1=i;
                                else if(locul2==0)
                                    locul2=i;
                                else if(locul3==0)
                                    locul3=i;
                                if(i==0)   cout<<endl<<endl<<" Jucatorul A a gasit o comoara "<<endl;
                            if(i==1)   cout<<endl<<endl<<" Jucatorul B a gasit o comoara "<<endl;
                            if(i==2)   cout<<endl<<endl<<" Jucatorul C a gasit o comoara "<<endl;
                            if(i==3)   cout<<endl<<endl<<" Jucatorul D a gasit o comoara "<<endl;
                                contor++;
                            }
                            cautatori[i]->deplasare_dreapta(harta);
                            cout<<endl;
                            harta.afisare();
                            cout<<endl<<endl;
                            if(contor==3) {ok=0;break;}
                        }
                        k++;
                    }

                    else  if (value==KEY_UP)
                    {
                        if(cautatori[i]->verificare_deplasare_sus(harta)==1)
                        {
                            y=1;
                             if(harta.GetTabla()[cautatori[i]->GetLinieCautator()-1][cautatori[i]->GetColoanaCautator()]==10)
                            {
                                cautatori[i]->SetCastigator(1);
                                if(locul1==0)
                                    locul1=i;
                                else if(locul2==0)
                                    locul2=i;
                                else if(locul3==0)
                                    locul3=i;
                            if(i==0)   cout<<endl<<endl<<" Jucatorul A a gasit o comoara "<<endl;
                            if(i==1)   cout<<endl<<endl<<" Jucatorul B a gasit o comoara "<<endl;
                            if(i==2)   cout<<endl<<endl<<" Jucatorul C a gasit o comoara "<<endl;
                            if(i==3)   cout<<endl<<endl<<" Jucatorul D a gasit o comoara "<<endl;
                                contor++;
                            }
                            cautatori[i]->deplasare_sus(harta);
                            cout<<endl;
                            harta.afisare();
                            cout<<endl<<endl;
                            if(contor==3) {ok=0;break;}
                        }
                        k++;
                    }
                    else if(value==KEY_DOWN)
                    {

                        if(cautatori[i]->verificare_deplasare_jos(harta)==1)
                        {
                            y=1;
                             if(harta.GetTabla()[cautatori[i]->GetLinieCautator()+1][cautatori[i]->GetColoanaCautator()]==10)
                            {
                                cautatori[i]->SetCastigator(1);
                                if(locul1==0)
                                    locul1=i;
                                else if(locul2==0)
                                    locul2=i;
                                else if(locul3==0)
                                    locul3=i;

                            if(i==0)   cout<<endl<<endl<<" Jucatorul A a gasit o comoara "<<endl;
                            if(i==1)   cout<<endl<<endl<<" Jucatorul B a gasit o comoara "<<endl;
                            if(i==2)   cout<<endl<<endl<<" Jucatorul C a gasit o comoara "<<endl;
                            if(i==3)   cout<<endl<<endl<<" Jucatorul D a gasit o comoara "<<endl;
                                contor++;
                            }
                            cautatori[i]->deplasare_jos(harta);
                            cout<<endl;
                            harta.afisare();
                            cout<<endl<<endl;
                            if(contor==3) {ok=0;break;}
                        }
                        k++;
                    }
                    if(k==4 && y==0)                                              // daca s-au facut toate deplsarile si niciuna nu a putut fi efectuata
                    {
                        y=1;                                                      // ies din al doilea while
                        cautatori[i]->SetStare(0);                                // setez starea jucatorului curent la 0
                        if(i==0)   cout<<endl<<endl<<" Jucatorul A nu se mai poate deplasa "<<endl;
                        if(i==1)   cout<<endl<<endl<<" Jucatorul B nu se mai poate deplasa "<<endl;
                        if(i==2)   cout<<endl<<endl<<" Jucatorul C nu se mai poate deplasa "<<endl;
                        if(i==3)   cout<<endl<<endl<<" Jucatorul D nu se mai poate deplasa "<<endl;
                            contor++;                                           // cresc numarul de jucatori care sunt inactivi
                        if(contor==3) {ok=0;break;}                             // daca am 3 jucatori care au castigat sau nu mai am jucatori jocul se incheie
                    }
                }
              }

            if(contor==3) {ok=0;break;}
        }
                    SetConsoleTextAttribute(hConsole, 15);
    cout<<endl<<endl<<endl<<"                                GAME OVER                                  ";
    cout<<endl<<endl<<endl<<endl;

    cout<<"LOCUL 1:           ";
                if(locul1==0)
                    cout<<"JUCATORUL A"<<endl;
                 if(locul1==1)
                    cout<<"JUCATORUL B"<<endl;
                if(locul1==2)
                    cout<<"JUCATORUL C"<<endl;
                if(locul1==3)
                    cout<<"JUCATORUL D"<<endl;
    cout<<"LOCUL 2:           ";
                if(locul2==0)
                    cout<<"JUCATORUL A"<<endl;
                 if(locul2==1)
                    cout<<"JUCATORUL B"<<endl;
                if(locul2==2)
                    cout<<"JUCATORUL C"<<endl;
                if(locul2==3)
                    cout<<"JUCATORUL D"<<endl;
    cout<<"LOCUL 3:           ";
                if(locul3==0)
                    cout<<"JUCATORUL A"<<endl;
                 if(locul3==1)
                    cout<<"JUCATORUL B"<<endl;
                if(locul3==2)
                    cout<<"JUCATORUL C"<<endl;
                if(locul3==3)
                    cout<<"JUCATORUL D"<<endl;
    cout<<endl<<endl<<endl<<endl;

}
