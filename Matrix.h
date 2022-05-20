//
// Created by pauli on 20.05.2022.
//


class Matrix {

private:

    int v;  //liczba wierzchołków macierzy
    int k;  //liczba krawędzi macierzy

    signed char ** tab;

public:

    void readFromFile();
    void displayMatrix();
    void deleteMatrix();

};

