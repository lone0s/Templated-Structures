#include <iostream>

#include "T_List.h"
#include "Sommet.h"
#include "Graph.h"

using namespace Dijkstra_Successor;
using namespace std;
int main() {
    int arr[5] {1,2,3,4,5};
    int* arrptr = arr;
    int arr2[5] {5,4,3,2,1};
//    int* x = new int[3];
    int abab[5];
    T_Node<int> test(5,arr);
    T_List<int>list(5,arr);
//    cout << test;
    cout << list;
    list = T_List<int>(5,arr2);
    cout << list;
//    int x = 5;
    list.add(7);
    list.add(5,arr);
    cout << list;
    list.add(11);
    list.add(18);
    cout << list ;
    T_List<Successor> listeSuccesseur;
    T_List<Successor> listeSuccesseur2;
    listeSuccesseur2.add(*new Successor(5,5));
    listeSuccesseur2.add(*new Successor(6,6));
    listeSuccesseur2.add(*new Successor(3,3));
    listeSuccesseur.add(*new Successor(1,1));
    listeSuccesseur.add(*new Successor(1,7));
    Sommet sommet(1);
    Sommet sommet2(2);
    sommet2.addSuccesseurs(listeSuccesseur2);
    sommet.addSuccesseurs(listeSuccesseur);
    cout << listeSuccesseur;
    cout << sommet;
    Graph graph;
    cout << graph;
    graph.add(sommet);
    cout << graph;
    T_List<Sommet> listeSommet;
    listeSommet.add(sommet);
    listeSommet.add(sommet2);
    graph.addSommets(listeSommet);
    cout << graph;
    return 0;

}
