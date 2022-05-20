//
// Created by pauli on 20.05.2022.
//

#ifndef SDIZO2_KRUSKAL_H
#define SDIZO2_KRUSKAL_H


class Kruskal {

private:

    int n;
    int fathers[6];//maksymalna ilosc wierzchołków
    int m;

public:

    int find(int x);
    void unite(int x, int y);
    void Kruskal();


};


#endif //SDIZO2_KRUSKAL_H
