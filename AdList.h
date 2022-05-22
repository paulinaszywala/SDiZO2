
#include <iostream>
#include "Graph.h"

struct stList
{

    stList * next;
    int index;      //numer węzła docelowego
    int weight;     //waga krawędzi
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
    int ** tablica;
    int k;  //liczba krawędzi grafu
    int v0; //wierzchołek startowy do najkrótszej ścieżki


    //KRUSKAL

    stList ** tab;
    stList *p, *temp;


public:

    void readFromGraph(Graph graph);
    void displayAdList();
    void deleteList();
    int getV();
    stList * getList(int i);

    void dijkstry();
    //Kruskal
    void kruskal();
    int find(int belongs[], int vertexno);
    void applyUnion(int belongs[], int c1, int c2);
    void sort();
    void print();

};
