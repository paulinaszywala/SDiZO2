//
// Created by pauli on 20.05.2022.
//
#include "Graph.h"

class Matrix {

private:

    int v;  //liczba wierzchołków macierzy
    int k;  //liczba krawędzi macierzy

    signed int ** tab;

public:
    void matrixFromGraph(Graph graph);

    void displayMatrix();
    void deleteMatrix();

};

