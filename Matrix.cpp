//
// Created by pauli on 20.05.2022.
//

#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void Matrix::readFromFile()
{

    int v1; //wierzchołek początkowy
    int v2; //wierzchołek końcowy
    int w;  //krawędź - waga

    int i,j;

    std::ifstream file("Data.txt");


    if(file.is_open()){

        file >> k;                                  //wczytujemy rozmiar macierzy z pliku
        file >> v;

        tab = new signed char * [v];                  //tworzymy tablicę wskaźników do przechowywania macierzy incydencji

        for(i = 0; i < v; i++)
        {
            tab [i] = new signed char [k];         // Tworzymy wiersze macierzy
        }

        for( i = 0; i < v; i++ )
        {
            for( j = 0; j < k; j++ )
            {
                tab[ i ][ j ] = 0;                      // Macierz wypełniamy zerami, zanim uzupełnimy ją 1 i -1
            }
        }

        for( i = 0; i < k; i++ )
        {
            file >> v1;         //wczytujemy z pliku kolejno wiechołek początkowy, końcowy jak i wagę
            file >> v2;
            file >> w;
            tab[v2][i] = -w;    // Wierzchołek końcowy
            tab[v1][i] = w;     // Wierzchołek startowy

        }
    }
    file.close();


    std::cout << "   ";
}


void Matrix::displayMatrix()
{

    int i,j;
    std:: cout <<"   ";
    for( i = 0; i < k; i++ )
    {
        std::cout << std::setw ( 3 ) << i;        //numeracja kolumn
    }

    std::cout << std::endl;

    for( i = 0; i < v; i++ )
    {

        std::cout << std::setw ( 3 ) << i;        //numeracja wierszy

        for( j = 0; j < k; j++ )
        {
            std::cout << std::setw ( 3 ) << ( int ) tab [i][j];
        }

        std::cout << std::endl;
    }
}

void Matrix::deleteMatrix()
{
    int i,j;

    for(i = 0; i < v; i++)
    {
        delete [ ] tab [i];
    }

    delete [ ] tab;
}