#include "AdList.h"
#include <iostream>
#include <iomanip>
#include <random>


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


int AdList::getV() {
    return v;
}

stList * AdList::getList(int i) {
    return  tab[i];
}



//void AdList::dijkstry()
//{
//    //DIJKSTRY
//
//    const int MAXINT = 2147483647; //nieskończoność tak jakby
//    int *S, *d, *pr;
//    bool *QS;                       //zbiory Q i S
//    int sptr;                       //wskaźnik stosu
//    stList *pw, *rw;
//    int i,j,u;
//
//    d = new int [v];    //tablica kosztow dojścia
//    pr = new int [v];   //tablica poprzedników
//
//    QS = new bool[v];
//    S = new int[v];     //stos
//    sptr = 0;
//
//
//
//    //Inicjalizacja tablic
//
//    for(int i = 0; i < v; i++)
//    {
//        d[i] = MAXINT;   //"nieskończoność"
//        pr[i] = -1;      //nieistniejący numer wierzchołka
//        QS[i] = false;
//        //listę sąsiedztwa mamy już wypełnioną zerami
//    }
//
//    d[v0] = 0;          //koszt dojścia do wierzchołka startowego jest zerowy
//
//
//    //Wyznaczamy ścieżki
//
//    for(i = 0; i < v; i++ )
//    {
//        for(j = 0; QS [j]; j++ );     //Szukamy wierzchołka z Q o najmniejszym koszcie d
//
//        for(u = j++; j < v; j++ )
//        {
//            if (!QS[j] && (d[j] < d[u])) {
//                u = j;
//            }
//        }
//
//        // Znaleziony wierzchołek przenosimy do S
//
//        QS [ u ] = true;
//
//        // Modyfikujemy odpowiednio wszystkich sąsiadów x, którzy są z Q
//
//        for( pw = tab [u]; pw; pw = pw->next ) {
//            if (!QS[pw->index] && (d[pw->index] > d[u] + pw->weight)) {
//                d[pw->index] = d[u] + pw->weight;
//                pr[pw->index] = u;
//            }
//        }
//    }
//
//
//
//    //WYŚWIETLENIE WYNIKÓW
//
//    for( i = 0; i < v; i++ )
//    {
//        std::cout << i << ": ";
//
//        //Ścieżkę przechodzimy z odrotnej kolejności (koniec - > początek), kolejne wierzchołki zapisujemy na stosie
//
//
//        for(int j = i; j > -1; j = pr [ j ] )
//        {
//            S [ sptr++ ] = j;
//        }
//
//        // Wyświetlamy ścieżkę, pobierając wierzchołki ze stosu
//
//        while( sptr ){
//
//            std::cout << S [ --sptr ] << " ";
//        }
//
//        // Na końcu ścieżki wypisujemy jej koszt
//
//        std::cout << "$" << d [ i ] << std::endl;
//    }
//
//    delete [] d;
//    delete [] pr;
//    delete [] QS;
//    delete [] S;
//
//}


void AdList::readFromGraph(Graph graph) {
    v = graph.v;
    k = graph.size;
    tab = new stList * [v];
    for(int i = 0; i < v; i++)
    {
        tab [i] = NULL;         // Tablicę wypełniamy zerami
    }
    for(int i = 0; i < k; i++ )
    {
        p = new stList;
        p->index = graph.edgeTab[i].y;
        p->next = tab [graph.edgeTab[i].x ];
        p->weight = graph.edgeTab[i].z;
        tab [graph.edgeTab[i].x ] = p;
    }
    v0 = graph.edgeTab[0].x;
}



