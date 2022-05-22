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
    edge * edgeTab, * spanList;

    int size; //liczba krawędzi z grafie
    int v{}; //liczba wierzchołków
    int sizeofspan{};
    static int Random(int min, int max);           //Funkcja do generowania wartości losowych z przedziału <min, max>
    void generateRandomGraph(int vert);
    void readFromFile();
    //Kruskal
    Graph Kruskal();
    int find(int belongs[], int vertexno);
    void applyUnion(int belongs[], int c1, int c2);
    void sort();
    void print();
    //delete graph
};
#endif


