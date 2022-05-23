//
// Created by Piotrek on 21.05.2022.
//
#include<stdio.h>
#include<stdbool.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Graph.h"

void Graph::generateRandomGraph(int vert) {
    v = vert;
    for(int i = 0; i < size; i++)
    {
        edgeTab[i].x = Random(0, v);
        edgeTab[i].y = Random(0, v);
        edgeTab[i].z = Random(1, 10);
    }
}

void Graph::readFromFile() {
    std::ifstream file("Data.txt");
    if(file.is_open()){
        file >> size;
        file >> v;
        for(int i = 0; i < size; i++){
            file >> edgeTab[i].x;
            file >> edgeTab[i].y;
            file >> edgeTab[i].z;
        }
    }
    file.close();

}

Graph::Graph(int k) {
    edgeTab = new edge [k];
    size = k;
}

int Graph::Random(int min, int max) {
    std::random_device crypto_random_generator;
    std::uniform_int_distribution<int> int_distribution(min, max);

    int result = int_distribution(crypto_random_generator);

    return result;
}

bool Graph::containsv0(int v0)
{
    int i = 0;

    while(i <= size)
    {
        if(edgeTab[i].x == v0)
        {
            return true;
            break;
        }
        else if(i == size){
            return false;
        }
        else
        {
            i++;
        }

    }

}

bool Graph::containsvk(int vk)
{
    int i = 0;

    while(i <= size)
    {
        if(edgeTab[i].y == vk)
        {
            return true;
            break;
        }
        else if(i == size){
            return false;
        }
        else
        {
            i++;
        }

    }
}


//Graph Graph::Kruskal() {
//    int nGraph[v][v];
//    for(int i = 0; i < v; i++ )
//        for(int j = 0; j < v; j++)
//            nGraph[i][j] = 0;
//    for(int i = 0; i < size; i++){
//        nGraph[edgeTab[i].x][edgeTab[i].y] = edgeTab[i].z;
//        nGraph[edgeTab[i].y][edgeTab[i].x] = edgeTab[i].z;
//    }
//    int belongs[v], i, j, cno1, cno2;
//    int n = 0;
//    v = 0;
//    for (i = 1; i < v; i++)
//        for (j = 0; j < i; j++) {
//            if (nGraph[i][j] != 0) {
//                edgeTab[v].x = i;
//                edgeTab[v].y = j;
//                edgeTab[v].z = nGraph[i][j];
//                n++;
//            }
//        }
//
//    sort();
//
//    for (i = 0; i < v; i++)
//        belongs[i] = i;
//
//    sizeofspan = 0;
//
//    for (i = 0; i < n; i++) {
//        cno1 = find(belongs, edgeTab[i].x);
//        cno2 = find(belongs, edgeTab[i].y);
//
//        if (cno1 != cno2) {
//            spanList[sizeofspan].x = edgeTab[i].x;
//            sizeofspan++;
//            applyUnion(belongs, cno1, cno2);
//        }
//    }
//}

//int Graph::find(int *belongs, int vertexno) {
//    return (belongs[vertexno]);
//}
////
//void Graph::applyUnion(int *belongs, int c1, int c2) {
//    for (int i = 0; i < v; i++)
//        if (belongs[i] == c2)
//            belongs[i] = c1;
//}
////
//void Graph::sort() {
//    edge temp;
//    for (int i = 1; i < v; i++)
//        for (int j = 0; j < v - 1; j++)
//            if (edgeTab[j].z > edgeTab[j + 1].z) {
//                temp = edgeTab[j];
//                edgeTab[j] = edgeTab[j + 1];
//                edgeTab[j + 1] = temp;
//            }
//}
//void Graph::print() {
//    int i, cost = 0;
//
//    for (i = 0; i < sizeofspan; i++) {
//        std::cout << spanList[i].x << " - " << spanList[i].y << ": " << spanList[i].z;
//        cost = cost + spanList[i].z;
//    }
//
//    std::cout << "\nSpanning tree cost: "<<cost;
//}

void Graph::Prim() {

#define INF 9999999

   // int primV;

// create a 2d array of size 5x5
//for adjacency matrix to represent graph

    int G[v][v];
    for(int i = 0; i < v; i++ )
        for(int j = 0; j < v; j++)
            G[i][j] = 0;
    for(int i = 0; i < size; i++){
        G[edgeTab[i].x][edgeTab[i].y] = edgeTab[i].z;
        G[edgeTab[i].y][edgeTab[i].x] = edgeTab[i].z;
    }

    //int no_edge;  // number of edge

    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[v];
    for(int i = 0; i < v; i++)
        selected[i] = false;

    int licznik;

    // set number of edge to 0
    size = 0;
    licznik = 0;

    // the number of egde in minimum spanning tree will be
    // always less than (V -1), where V is number of vertices in
    //graph

    // choose 0th vertex and make it true
    selected[0] = true;

    int x;  //  row number
    int y;  //  col number
    int z;

//    // print for edge and weight
//    printf("Edge : Weight\n");



    while (size < v - 1) {
        //For every vertex in the set S, find the all adjacent vertices
        // , calculate the distance from the vertex selected at step 1.
        // if the vertex is already in the set S, discard it otherwise
        //choose another vertex nearest to selected vertex  at step 1.

        int min = INF;
//        x = 0;
            y = 0;


        for (int i = 0; i < v; i++) {
            if (selected[i]) {
                for (int j = 0; j < v; j++) {
                    if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
                        if (min > G[i][j]) {
                            min = G[i][j];

                            x = i;
                            y = j;
                            z = G[x][y];

                            edgeTab[licznik].x = x;
                            edgeTab[licznik].y = y;
                            edgeTab[licznik].z = z;

                        }
                    }
                }

            }
        }

        licznik++;
        std::cout << x << " - " << y << " : " << z << std::endl;
        selected[y] = true;
        size++;
    }


}



void Graph::dijkstry(int v0, int vk)
{

#define INFINITY 9999

    int cost[v][v], distance[v], pred[v];
    int visited[v], count, mindistance, nextnode, i, j;

    int G[v][v];
    for(int i = 0; i < v; i++ )
        for(int j = 0; j < v; j++)
            G[i][j] = 0;
    for(int i = 0; i < size; i++){
        G[edgeTab[i].x][edgeTab[i].y] = edgeTab[i].z;
//        G[edgeTab[i].y][edgeTab[i].x] = edgeTab[i].z;
    }

    // Creating cost matrix
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];

    for (i = 0; i < v; i++) {
        distance[i] = cost[v0][i];
        pred[i] = v0;
        visited[i] = 0;
    }

    distance[v0] = 0;
    visited[v0] = 1;
    count = 1;

    while (count < v - 1) {
        mindistance = INFINITY;

        for (i = 0; i < v; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (i = 0; i < v; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    // Printing the distance
//    for (i = 0; i < v; i++)
//        if (i != v0) {
//            printf("\nDistance from source to %d: %d", i, distance[i]);
//        }

    for (i = 0; i < v; i++)
        if (i == vk) {
            std::cout<<std::endl;
            std::cout<<"Koszt przejscia z "<< v0 << " do "<< i << " to: " << distance[i]<<std::endl<<std::endl;
        }
}





    //stary DIJKSTRY
//
//    const int MAXINT = 2147483647; //nieskończoność tak jakby
//    int *S, *d, *pr;
//    bool *QS;                       //zbiory Q i S
//    int sptr;                       //wskaźnik stosu
//    edge *pw, *rw;
//    int i,j,u;
//    int mind;
//
//    d = new int [v];    //tablica kosztow dojścia
//    pr = new int [v];   //tablica poprzedników
//
//    QS = new bool[v];
//    S = new int[v];     //stos
//
//    int licznik;
//
//    sptr = 0;
//
//
//
//    //Inicjalizacja tablic
//
//    for(int i = 0; i < v; i++)
//    {
//        d[i] = MAXINT;   //"nieskończoność"
//        pr[i] = -1;      //nieistniejący numer wierzchołka
//        QS[i] = false;
//        //listę sąsiedztwa mamy już wypełnioną zerami
//    }
//
//    d[v0] = 0;          //koszt dojścia do wierzchołka startowego jest zerowy
//
//
//    //Wyznaczamy ścieżki
//
//    for(i = 0; i < v; i++ )
//    {
//        for(j = 0; QS [j]; j++ );     //Szukamy wierzchołka z Q o najmniejszym koszcie d
//
//        for(u = j++; j < v; j++ )
//        {
//            if (!QS[j] && (d[j] < d[u])) {
//                u = j;
//                d[u] = d[j];
//            }
//        }
//
//        // Znaleziony wierzchołek przenosimy do S
//
//        QS [ u ] = true;
//
//
//        // Modyfikujemy odpowiednio wszystkich sąsiadów x, którzy są z Q
////
////        for( pw = tab [u]; pw; pw = pw->next ) {
////            if (!QS[pw->index] && (d[pw->index] > d[u] + pw->weight)) {
////                d[pw->index] = d[u] + pw->weight;
////                pr[pw->index] = u;
////            }
////        }
//
//        for(pw = &edgeTab[licznik]; pw; pw = edgeTab[u].x)
//        {
//            if(!QS[pw[u].y] && d[pw[u].y] > d[u] + pw[u].z)
//            {
//                d[pw[u].y] = d[u] + pw[u].z;
//                pr[pw[u].y] = u;
//            }
//        }
//    }
//
//
//
//    //WYŚWIETLENIE WYNIKÓW
//
//    for( i = 0; i < v; i++ )
//    {
//        std::cout << i << ": ";
//
//        //Ścieżkę przechodzimy z odrotnej kolejności (koniec - > początek), kolejne wierzchołki zapisujemy na stosie
//
//
//        for(int j = i; j > -1; j = pr [ j ] )
//        {
//            S [ sptr++ ] = j;
//        }
//
//        // Wyświetlamy ścieżkę, pobierając wierzchołki ze stosu
//
//        while( sptr ){
//
//            std::cout << S [ --sptr ] << " ";
//        }
//
//        // Na końcu ścieżki wypisujemy jej koszt
//
//        std::cout << "$" << d [ i ] << std::endl;
//    }
//
//    delete [] d;
//    delete [] pr;
//    delete [] QS;
//    delete [] S;

