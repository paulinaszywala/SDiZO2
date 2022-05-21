
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



    void readFromFile();
    void displayAdList();
    void deleteList();
    void randomGraph(int v, float d, int k, int * tabv1, int * tabv2, int * tabw);
    int getV();
    stList * getList(int i);
    void kruskal();
};