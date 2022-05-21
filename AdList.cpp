//
// Created by pauli on 20.05.2022.
//

#include "AdList.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <random>


void AdList::readFromFile()
{

    int v1; //wierzchołek początkowy
    int v2; //wierzchołek końcowy
    int w;  //krawędź - waga

    std::ifstream file("Data.txt");


    if(file.is_open()){

        file >> k;                      //wczytujemy rozmiar macierzy z pliku
        file >> v;

        tab = new stList * [v];          //tworzymy tablicę wskaźników do przechowywania listy sąsiedztwa

        for(int i = 0; i < v; i++)
        {
            tab [i] = NULL;         // Tablicę wypełniamy zerami
        }

        for(int i = 0; i < k; i++ )
        {
            file >> v1;         //wczytujemy z pliku kolejno wiechołek początkowy, końcowy jak i wagę
            file >> v2;
            file >> w;

            if(i == 0)
            {
                v0 = v1;
            }

            p = new stList;         // Tworzymy nowy element
            p->index = v2;          // Numerujemy go jako v2
            p->next = tab [v1];     // Dodajemy go na początek listy A [ v1 ]
            p->weight = w;
            tab [v1] = p;
        }
    }
    file.close();
    std::cout << std::endl;
}

void AdList::displayAdList(){
    for(int i = 0; i < v; i++ )
    {
        std::cout << "tab [ " << i << " ] =";
        p = tab [ i ];

        while( p )
        {
            std::cout << std::setw ( 3 ) << p->index <<  " : " << p->weight;
            p = p->next;
        }
        std::cout << std::endl;
    }
}


void AdList::deleteList(){
    for(int i = 0; i < v; i++ )
    {
        p = tab [ i ];

        while( p )
        {
            temp = p;
            p = p->next;
            delete temp;
        }
    }

    delete [ ] tab;

}

void AdList::randomGraph(int v, float d, int k, int * tabv1, int * tabv2, int * tabw)
{

    int v1; //wierzchołek początkowy
    int v2; //wierzchołek końcowy
    int w;  //krawędź - waga

    tab = new stList * [v];          //tworzymy tablicę wskaźników do przechowywania listy sąsiedztwa

        for(int i = 0; i < v; i++)
        {
            tab [i] = NULL;         // Tablicę wypełniamy zerami
        }

        for(int i = 0; i < k; i++ )
        {
            v1 = tabv1[i];
            v2 = tabv2[i];
            w = tabw[i];

            p = new stList;         // Tworzymy nowy element
            p->index = v2;          // Numerujemy go jako v2
            p->next = tab [v1];     // Dodajemy go na początek listy A [ v1 ]
            p->weight = w;
            tab [v1] = p;
        }

//    //disp
//    for(int i = 0; i < v; i++ )
//    {
//        std::cout << "tab [ " << i << " ] =";
//        p = tab [ i ];
//
//        while( p )
//        {
//            std::cout << std::setw ( 3 ) << p->index <<  " : " << p->weight;
//            p = p->next;
//        }
//        std::cout << std::endl;
//    }
//    //disp

}

int AdList::getV() {
    return v;
}

stList * AdList::getList(int i) {
    return  tab[i];
}

void AdList::kruskal() {
    L = new stList * [v];
    for(int i = 0; i < v; i++)
    {
        L [i] = tab [i];
    }



}

void AdList::dijkstry()
{
    //DIJKSTRY

    const int MAXINT = 2147483647; //nieksończonosć tak jakby
    int *S, *d, *pr;
    bool *QS;                       //zbiory Q i S
    int sptr;                       //wskaźnik stosu
    stList *pw, *rw;
    int i,j,u;

    d = new int [v];    //tablica kosztow dojścia
    pr = new int [v];   //tablica poprzedników

    QS = new bool[v];
    S = new int[v];     //stos
    sptr = 0;



    //Inicjalizacja tablic

    for(int i = 0; i < v; i++)
    {
        d[i] = MAXINT;   //"nieskończoność"
        pr[i] = -1;      //nieistniejący numer wierzchołka
        QS[i] = false;
        //listę sąsiedztwa mamy już wypełnioną zerami
    }

    d[v0] = 0;          //koszt dojścia do wierzchołka startowego jest zerowy


    //Wyznaczamy ścieżki

    for(i = 0; i < v; i++ )
    {
        for(j = 0; QS [j]; j++ );     //Szukamy wierzchołka w Q o najmniejszym koszcie d

        for(u = j++; j < v; j++ )
        {
            if (!QS[j] && (d[j] < d[u])) {
                u = j;
            }
        }

        // Znaleziony wierzchołek przenosimy do S

        QS [ u ] = true;

        // Modyfikujemy odpowiednio wszystkich sąsiadów u, którzy są w Q

        for( pw = tab [u]; pw; pw = pw->next ) {
            if (!QS[pw->index] && (d[pw->index] > d[u] + pw->weight)) {
                d[pw->index] = d[u] + pw->weight;
                pr[pw->index] = u;
            }
        }
    }



    //WYŚWIETLENIE WYNIKÓW

    for( i = 0; i < v; i++ )
    {
        std::cout << i << ": ";

        //Ścieżkę przechodzimy w odrotnej kolejności (koniec - > początek), kolejne wierzchołki zapisujemy na stosie


        for(int j = i; j > -1; j = pr [ j ] )
        {
            S [ sptr++ ] = j;
        }

        // Wyświetlamy ścieżkę, pobierając wierzchołki ze stosu

        while( sptr ){

            std::cout << S [ --sptr ] << " ";
        }

        // Na końcu ścieżki wypisujemy jej koszt

        std::cout << "$" << d [ i ] << std::endl;
    }

    delete [] d;
    delete [] pr;
    delete [] QS;
    delete [] S;

}


