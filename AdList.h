
struct stList
{
    stList * next;
    int index;
    int weight;
};

class AdList {

private:

    int v;  //liczba wierzchołków grafu
    int k;  //liczba krawędzi grafu


    stList ** tab;
    stList *p, *r;

public:

    void readFromFile();
    void displayAdList();
    void deleteList();

};
