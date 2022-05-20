//
// Created by pauli on 20.05.2022.
//


class Matrix {

private:

    int n;  //liczba wierzchołków macierzy
    int m;  //liczba krawędzi macierzy

    signed char ** tab;

public:

    void readFromFile();
    void displayMatrix();
    void deleteMatrix();

};

