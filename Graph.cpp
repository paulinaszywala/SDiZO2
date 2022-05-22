//
// Created by Piotrek on 21.05.2022.
//

#include <fstream>
#include <iostream>
#include "Graph.h"

void Graph::generateRandomGraph(int vert) {
    v = vert;
    for(int i = 0; i < size; i++)
    {
        edgeTab[i].x = Random(0, v);
        edgeTab[i].y = Random(0, v);
        edgeTab[i].z = Random(1, 10);
    }
}

void Graph::readFromFile() {
    std::ifstream file("Data.txt");
    if(file.is_open()){
        file >> size;
        file >> v;
        for(int i = 0; i < size; i++){
            file >> edgeTab[i].x;
            file >> edgeTab[i].y;
            file >> edgeTab[i].z;
        }
    }
    file.close();
}

Graph::Graph(int k) {
        edgeTab = new edge [k];
        size = k;
}

int Graph::Random(int min, int max) {
    std::random_device crypto_random_generator;
    std::uniform_int_distribution<int> int_distribution(min, max);

    int result = int_distribution(crypto_random_generator);

    return result;
}

Graph Graph::Kruskal() {
    int nGraph[v][v];
    for(int i = 0; i < v; i++ )
        for(int j = 0; j < v; j++)
            nGraph[i][j] = 0;
    for(int i = 0; i < size; i++){
        nGraph[edgeTab[i].x][edgeTab[i].y] = edgeTab[i].z;
        nGraph[edgeTab[i].y][edgeTab[i].x] = edgeTab[i].z;
    }
    int belongs[v], i, j, cno1, cno2;
    int n = 0;
    v = 0;
    for (i = 1; i < v; i++)
        for (j = 0; j < i; j++) {
            if (nGraph[i][j] != 0) {
                edgeTab[v].x = i;
                edgeTab[v].y = j;
                edgeTab[v].z = nGraph[i][j];
                n++;
            }
        }

    sort();

    for (i = 0; i < v; i++)
        belongs[i] = i;

    sizeofspan = 0;

    for (i = 0; i < n; i++) {
        cno1 = find(belongs, edgeTab[i].x);
        cno2 = find(belongs, edgeTab[i].y);

        if (cno1 != cno2) {
            edgeTab[n].x = edgeTab[i].x;
            sizeofspan++;
            applyUnion(belongs, cno1, cno2);
        }
    }
}

int Graph::find(int *belongs, int vertexno) {
    return (belongs[vertexno]);
}
//
void Graph::applyUnion(int *belongs, int c1, int c2) {
    for (int i = 0; i < v; i++)
        if (belongs[i] == c2)
            belongs[i] = c1;
}
//
void Graph::sort() {
    edge temp;
    for (int i = 1; i < v; i++)
        for (int j = 0; j < v - 1; j++)
            if (edgeTab[j].z > edgeTab[j + 1].z) {
                temp = edgeTab[j];
                edgeTab[j] = edgeTab[j + 1];
                edgeTab[j + 1] = temp;
            }
}
void Graph::print() {
    int i, cost = 0;

    for (i = 0; i < sizeofspan; i++) {
        std::cout << spanList[i].x << " - " << spanList[i].y << ": " << spanList[i].z;
        cost = cost + spanList[i].z;
    }

    std::cout << "\nSpanning tree cost: "<<cost;
}


