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
    int k;  //krawędź - waga

    int i,j;

    std::ifstream file("C:/Users/pauli/ClionProjects/SDiZO2/Data.txt");


    if(file.is_open()){

        file >> m;                                  //wczytujemy rozmiar macierzy z pliku
        file >> n;

        tab = new signed char * [n];                  //tworzymy tablicę wskaźników do przechowywania macierzy incydencji

        for(i = 0; i < n; i++)
        {
            tab [i] = new signed char [m];         // Tworzymy wiersze macierzy
        }

        for( i = 0; i < n; i++ )
        {
            for( j = 0; j < m; j++ )
            {
                tab[ i ][ j ] = 0;                      // Macierz wypełniamy zerami, zanim uzupełnimy ją 1 i -1
            }
        }

        for( i = 0; i < m; i++ )
        {
            file >> v1;         //wczytujemy z pliku kolejno wiechołek początkowy, końcowy jak i wagę
            file >> v2;
            file >> k;
            tab[v1][k] = 1;     // Wierzchołek startowy
            tab[v2][k] = -1;    // Wierzchołek końcowy
        }
    }
    file.close();


    std::cout << "   ";
}


void Matrix::displayMatrix()
{

    int i,j;

    for( i = 0; i < m; i++ )
    {
        std::cout << std::setw ( 3 ) << i;        //numeracja wierszy
    }

    std::cout << std::endl;

    for( i = 0; i < n; i++ )
    {

        std::cout << std::setw ( 3 ) << i;        //numeracja kolumn

        for( j = 0; j < m; j++ )
        {
            std::cout << std::setw ( 3 ) << ( int ) tab [i][j];
        }

        std::cout << std::endl;
    }
}

void Matrix::deleteMatrix()
{
    int i,j;

    for(i = 0; i < n; i++)
    {
        delete [ ] tab [i];
    }

    delete [ ] tab;
}