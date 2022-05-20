////
//// Created by pauli on 20.05.2022.
////
//
//#include "Kruskal.h"
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
////Struktura zbiorów rozłącznych (Disjont set union) - w celu przechowywania dwóch rozłącznych zbiorów
//
//
//
//int find(int x)  //wyznacza, w którym zbiorze jest dany element
//{
//
//    if(fathers[x] == x)
//    {
//        return x;
//    }
//    return find(fathers[x]);
//}
//
//void unite(int x, int y) //łączy dwa zbiory w jeden
//{
//
//    int fx = find(x);
//    int fy = find(y);
//    fathers[fx] = fy;
//}
//
//void Kruskal()
//{
//    int i;
//    int v1;
//    int k;
//
//    std::vector < std::pair <int,int> > edges;
//
//    for(i = 0; i < 6; i++)
//    {
//        fathers[i] = i;         //inicjalizacja tablicy "ojcow", którą używamy w strukturze zbiorów rozłącznych
//    }
//
//    for(i = 0; i < m; i++)
//    {
//        //tu te dane musza byc wczytane jakos
//        edges.push_back(std::make_pair(k,v1));      //loaading the input
//    }
//
////ALGORYTM KRUSKALA
//
//    //zmienne potrzebne do MST
//
//    int mst_weight = 0;
//    int mst_edges = 0;
//    int mst_ni = 0; //next index
//
//    //sortowanie listy krawędzi:
//
//    sort(edges.begin(), edges.end()); //sortujemy po k, czyli wadze
//
//    while((mst_edges < n-1) || (mst_ni < m))
//    {
//        v1 = edges[mst_ni].second;  //drugie z pary
//        k = edges[mst_ni].first;  //pierwsze z pary
//    }
//
//}
//
//
//
