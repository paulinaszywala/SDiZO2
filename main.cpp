#include <iostream>
#include <random>
#include <fstream>
#include "Matrix.h"
#include "AdList.h"
#include "Graph.h"

Matrix m;
AdList list;
int s, v;
float d, k;
bool loop;
using namespace std;

int getSizeFromFile(){
    int size{};
    ifstream file("Data.txt");
    if(file.is_open())
        file >> size;
    file.close();
        return size;

}

void MST(Graph graph){
    loop = true;
    list.readFromGraph(graph);
    m.matrixFromGraph(graph);
    while(loop){
        cout << endl << "Wyswietl graf listowo  - 1 " << endl;
        cout << "Wyswietl graf macierzowo - 2 " << endl;
        cout << "Algorytm Prima - 3" << endl;
        cout << "Algorytm Kruskala - 4 " << endl;
        cout << "Powrot do menu - 5 " << endl;
        cout << "Wybierz pozycje: " << endl;
        cin >> s;
        switch (s) {
            case 1: {
                list.displayAdList();
                break;
            }
            case 2: {
                m.displayMatrix();
                break;
            }
            case 3: {
                graph.Prim();
                break;
            }
            case 4: {
//                graph.Kruskal();
//                graph.print();
                break;
            }
            case 5: {
                loop = false;
                break;
            }
            default: {
                cout << "Niepoprawna opcja!" << endl;
            }
        }
    }
}
void ShortestPath(Graph graph){
    loop = true;
    while(loop){
        cout << endl << "Wyswietl graf listowo  - 1 " << endl;
        cout << "Wyswietl graf macierzowo - 2 " << endl;
        cout << "Algorytm Dijkstry - 3" << endl;
        cout << "Algorytm Forda-Bellmana - 4 " << endl;
        cout << "Powrot do menu - 5 " << endl;
        cout << "Wybierz pozycje: " << endl;
        cin >> s;
        switch (s) {
            case 1: {
                list.readFromGraph(graph);
                list.displayAdList();
                break;
            }
            case 2: {
                m.matrixFromGraph(graph);
                m.displayMatrix();
                break;
            }
            case 3: {
                //tu wywołanie Dijkstry
                list.dijkstry();
                break;
            }
            case 4: {
                //tu wywołanie Forda-Bellmana
                break;
            }
            case 5: {
                loop = false;
                break;
            }
            default: {
                cout << "Niepoprawna opcja!" << endl;
            }
        }
    }
}

int main() {
    //  Główna pętla programu, pozwalająca na wybranie trybu pracy
    while(true) {
        cout << endl << "Wyznaczanie minimalnego drzewa rozpinajacego  - 1 " << endl;
        cout << "Wyznaczanie najkrotszej sciezki z grafie - 2 " << endl;
        cout << "Pomiary - 3" << endl;
        cout << "Wyjscie z programu - 0 " << endl;
        cout << "Wybierz pozycje: " << endl;
        cin >> s;
        switch (s) {
            default: {
                cout << "Niepoprawna opcja!" << endl;
                break;
            }
            //Wyjście z programu
            case 0:
                return 0;
            //Wyznaczanie minimalnego drzewa rozpinającego
            case 1: {
                cout << "Wczytaj z pliku  - 1 " << endl;
                cout << "Wygeneruj losowy graf- 2 " << endl;
                cout << "Wybierz pozycje: " << endl;
                cin >> s;
                switch (s) {
                    //Wczytywanie z pliku
                    case 1: {
                        Graph graph(getSizeFromFile());
                        graph.readFromFile();
                        MST(graph);
                        m.deleteMatrix();
                        list.deleteList();
                        break;
                    }
                    //Losowanie grafu
                    case 2: {
                        cout << "Podaj liczbe wierzcholkow: ";
                        cin >> v;
                        cout << "Podaj gestosc grafu: ";
                        cin >> d;
                        k = floor((d * v * (v - 1)) / 2);
                        Graph graph(k);
                        graph.generateRandomGraph(v);
                        MST(graph);
                        m.deleteMatrix();
                        list.deleteList();
                        break;
                    }
                    default: {
                        cout << "Niepoprawna opcja!" << endl;
                        break;
                    }
                }
                break;
            }
            //Wyznaczanie najkrótszej ścieżki z grafie
            case 2: {
                cout << "Wczytaj z pliku  - 1 " << endl;
                cout << "Wygeneruj losowy graf- 2 " << endl;
                cout << "Wybierz pozycje: " << endl;
                cin >> s;
                switch (s) {
                    //Wczytywanie z pliku
                    case 1: {
                        Graph graph(getSizeFromFile());
                        graph.readFromFile();
                        ShortestPath(graph);
                        m.deleteMatrix();
                        list.deleteList();
                        break;
                    }
                    //Losowanie grafu
                    case 2: {
                        cout << "Podaj liczbe wierzcholkow: ";
                        cin >> v;
                        cout << "Podaj gestosc grafu: ";
                        cin >> d;
                        k = floor((d * v * (v - 1)) / 2);
                        Graph graph(k);
                        graph.generateRandomGraph(v);
                        ShortestPath(graph);
                        m.deleteMatrix();
                        list.deleteList();
                        break;
                    }
                    default: {
                        cout << "Niepoprawna opcja!" << endl;
                        break;
                    }
                }
                break;
            }
        }
    }

}
