#include <iostream>
#include <random>
#include "Matrix.h"
#include "AdList.h"
//#include "Kruskal.h"

Matrix m;
AdList list;
int s;
bool loop;
using namespace std;

void readFromFile(){
    m.readFromFile();
    list.readFromFile();
}

int Random(int min, int max)            //Funkcja do generowania wartości losowych z przedziału <min, max>
{
    int i;

    std::random_device crypto_random_generator;
    std::uniform_int_distribution<int> int_distribution(min, max);

    int result = int_distribution(crypto_random_generator);

    return result;
}

void randGenerate(){

    int v,k;
    float d;

    int v1; //wierzchołek początkowy
    int v2; //wierzchołek końcowy
    int w;  //krawędź - waga

    v = Random(4,10);
    d = 0.25;
    k = floor((d * v * (v-1)) / 2);

    int tabv1[v];
    int tabv2[v];
    int tabw[k];

    for(int i = 0; i < v; i++)
    {
        v1 = Random(0, (v-1));
        tabv1[i] = v1;
        v2 = Random(0, (v-1));
        tabv2[i] = v2;
    }
    for(int i = 0; i < k; i++)
    {
        w = Random(0,k);
        tabw[i] = w;
    }

    m.randomGraph(v,d,k,tabv1,tabv2,tabw);
    list.randomGraph(v,d,k,tabv1,tabv2,tabw);
    //tutaj losowanie i generowanie struktur
}
void MST(){
    loop = true;
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
                //tu wywołanie Prima
                break;
            }
            case 4: {
                //tu wywołanie Kruskala
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
void ShortestPath(){
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
                list.displayAdList();
                break;
            }
            case 2: {
                m.displayMatrix();
                break;
            }
            case 3: {
                //tu wywołanie Dijkstry
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
        cout << "Wyznaczanie najkrotszej sciezki w grafie - 2 " << endl;
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
                        readFromFile();
                        MST();
                        m.deleteMatrix();
                        list.deleteList();
                        break;
                    }
                    //Losowanie grafu
                    case 2: {
                        randGenerate();
                        MST();
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
            //Wyznaczanie najkrótszej ścieżki w grafie
            case 2: {
                cout << "Wczytaj z pliku  - 1 " << endl;
                cout << "Wygeneruj losowy graf- 2 " << endl;
                cout << "Wybierz pozycje: " << endl;
                cin >> s;
                switch (s) {
                    //Wczytywanie z pliku
                    case 1: {
                        readFromFile();
                        ShortestPath();
                        break;
                    }
                    //Losowanie grafu
                    case 2: {
                        randGenerate();
                        ShortestPath();
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
