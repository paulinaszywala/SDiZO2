//
// Created by pauli on 20.05.2022.
//

struct stList
{
    stList * next;
    int v;
};

class AdList {

private:

    int n;  //liczba wierzchołków grafu
    int m;  //liczba krawędzi grafu


    stList ** tab;
    stList *p, *r;

public:

    void readFromFile();
    void displayAdList();
    void deleteList();

};
