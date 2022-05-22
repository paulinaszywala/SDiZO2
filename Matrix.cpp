//
// Created by pauli on 20.05.2022.
//

#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <random>

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

void Matrix::matrixFromGraph(Graph graph) {
    v = graph.v;
    k = graph.size;
    tab = new int * [v];
    for(int i = 0; i < v; i++)
    {
        tab [i] = new int [k];         // Tworzymy wiersze macierzy
    }
    for(int i = 0; i < v; i++ )
    {
        for(int j = 0; j < k; j++ )
        {
            tab[ i ][ j ] = 0;                      // Macierz wypełniamy zerami, zanim uzupełnimy ją 1 i -1
        }
    }
    for(int i = 0; i < k; i++ )
    {
        tab[graph.edgeTab[i].y][i] = -graph.edgeTab[i].z;    // Wierzchołek końcowy
        tab[graph.edgeTab[i].x][i] = graph.edgeTab[i].z;     // Wierzchołek startowy
    }


}

