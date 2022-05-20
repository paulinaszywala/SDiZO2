
#include <iostream>

struct stList
{

    stList * next;
    int index;
    int weight;
//    stList& operator=(stList other)
//    {
//        std::swap(next, other.next);
//        std::swap(index, other.index);
//        std::swap(weight, other.weight);
//        return *this;
//    }
};

class AdList {

private:

    int v;  //liczba wierzchołków grafu
    int k;  //liczba krawędzi grafu

    stList ** tab, **L, **T;
    stList *p, *temp;


public:

    stList * getList(int i);
    int getV();
    void readFromFile();
    void displayAdList();
    void deleteList();
    void kruskal();

};
