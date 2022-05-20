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
    int w;  //krawędź - waga

    std::ifstream file("Data.txt");


    if(file.is_open()){

        file >> k;                      //wczytujemy rozmiar macierzy z pliku
        file >> v;

        tab = new stList * [v];          //tworzymy tablicę wskaźników do przechowywania listy sąsiedztwa

        for(i = 0; i < v; i++)
        {
            tab [i] = NULL;         // Tablicę wypełniamy zerami
        }

        for( i = 0; i < k; i++ )
        {
            file >> v1;         //wczytujemy z pliku kolejno wiechołek początkowy, końcowy jak i wagę
            file >> v2;
            file >> w;

            p = new stList;    // Tworzymy nowy element
            p->index = v2;          // Numerujemy go jako v2
            p->next = tab [v1]; // Dodajemy go na początek listy A [ v1 ]
            p->weight = w;
            tab [v1] = p;
        }
    }
    file.close();


    std::cout << std::endl;
}

void AdList::displayAdList(){

    int i,j;

    for( i = 0; i < v; i++ )
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

    int i;

    for( i = 0; i < v; i++ )
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
