//
// Created by Piotrek on 21.05.2022.
//

#include <fstream>
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
