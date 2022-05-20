//
// Created by pauli on 20.05.2022.
//

#include "AdList.h"
#include <fstream>
#include <iostream>
#include <iomanip>


void AdList::readFromFile()
{
    int i,j;

    int v1; //wierzchołek początkowy
    int v2; //wierzchołek końcowy
    int k;  //krawędź - waga

    std::ifstream file("Data.txt");


    if(file.is_open()){

        file >> m;                      //wczytujemy rozmiar macierzy z pliku
        file >> n;

        tab = new stList * [n];          //tworzymy tablicę wskaźników do przechowywania listy sąsiedztwa

        for(i = 0; i < n; i++)
        {
            tab [i] = NULL;         // Tablicę wypełniamy zerami
        }

        for( i = 0; i < m; i++ )
        {
            file >> v1;         //wczytujemy z pliku kolejno wiechołek początkowy, końcowy jak i wagę
            file >> v2;
            file >> k;

            p = new stList;    // Tworzymy nowy element
            p->v = v2;          // Numerujemy go jako v2
            p->next = tab [v1]; // Dodajemy go na początek listy A [ v1 ]
            tab [v1] = p;
        }
    }
    file.close();


    std::cout << std::endl;
}

void AdList::displayAdList(){

    int i,j;

    for( i = 0; i < n; i++ )
    {
        std::cout << "tab [ " << i << " ] =";
        p = tab [ i ];

        while( p )
        {
            std::cout << std::setw ( 3 ) << p->v;
            p = p->next;
        }
        std::cout << std::endl;
    }

}




void AdList::deleteList(){

    int i;

    for( i = 0; i < n; i++ )
    {
        p = tab [ i ];

        while( p )
        {
            r = p;
            p = p->next;
            delete r;
        }
    }

    delete [ ] tab;

}
