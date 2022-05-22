//
// Created by Piotrek on 21.05.2022.
//
#ifndef SDIZO2_GRAPH_H
#define SDIZO2_GRAPH_H

#include <random>
class Graph {
public:
    explicit Graph(int k);
    struct edge {
        int x, y, z;
    };
    edge * edgeTab;

    int size; //liczba krawędzi z grafie
    int v{}; //liczba wierzchołków
    static int Random(int min, int max);           //Funkcja do generowania wartości losowych z przedziału <min, max>
    void generateRandomGraph(int vert);
    void readFromFile();
    //delete graph
};
#endif


