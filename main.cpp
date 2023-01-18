#include <iostream>

#include "Templated_List/T_List.h"
#include "Sommet.h"
#include "Graph.h"
#include "PriorityQueue/T_PriorityQueue.h"
#include "T_Node_dynamic.h"

using namespace Dijkstra_Successor;
using namespace std;
int main() {
    /*int arr[5] {1,2,3,4,5};
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
    graph.add(sommet);
    T_List<Sommet> listeSommet;
    listeSommet.add(sommet);
    listeSommet.add(sommet2);
    graph.addSommets(listeSommet);*//*
    int arr[5] {1,2,3,4,5};
    int arrInv[5] {5,4,3,2,1};
    T_List<int> list(5,arrInv);
    cout << "Data before heap sort: " << list  << endl;
    heapSort(arrInv,5);
    T_List<int> listbis(5,arrInv);
    cout << "Data after heap sort: " << listbis << endl;*/


    T_PriorityQueue<int> queue;
    queue.add(5);
    cout << queue << endl;
    queue.add(3);
    cout << queue << endl;
    queue.add(7);
    cout << queue << endl;

    T_PriorityQueue<Successor> queue2;
    queue2.add(*new Successor(5,5));
    cout << queue2 << endl;
    queue2.add(*new Successor(3,3));
    cout << queue2 << endl;
    queue2.add(*new Successor(3,5));
    cout << queue2 << endl;
    queue2.add(*new Successor(7,7));
    cout << queue2 << endl;
    queue2.add(*new Successor(-1,-1));
    cout << queue2 << endl;
/*    cout << queue2.pop() << endl;
    cout << queue2 << endl;
    cout << queue2.pop() << endl;
    cout << queue2 << endl;
    cout << queue2.pop() << endl;
    cout << queue2 << endl;
    cout << queue2.pop() << endl;
    cout << queue2 << endl;
    try {
        cout << queue2.pop() << endl;
    } catch (exception& e) {
        cout << "Catched this: " << e.what() << endl;
    }*/

    T_Node<int> node(5);
    cout << node.get(0) << endl;
    return 0;
}
