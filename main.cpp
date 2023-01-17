#include <iostream>

#include "T_List.h"
#include "Sommet.h"
#include "Graph.h"

template <typename T>
void heapify(T array[], size_t i, size_t n ) {
    size_t left = i * 2 + 1;
    size_t right = i * 2 + 2;
    size_t largest = i;
    if (left < n && array[left] > array[largest])
        largest = left;
    if (right < n && array[right] > array[largest])
        largest = right;
    if (largest != i) {
        std::swap(array[i],array[largest]);
        heapify(array, n, largest);
    }
}

template<typename T>
void heapSort(T array[], size_t n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(array, i, n);
    for (int i = n - 1; i >= 0; --i) {
        std::swap(array[0],array[i]);
        heapify(array, 0, i);
    }
}

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
    graph.addSommets(listeSommet);*/
    int arr[5] {1,2,3,4,5};
    int arrInv[5] {5,4,3,2,1};
    T_List<int> list(5,arrInv);
    cout << "Data before heap sort: " << list  << endl;
    heapSort(arrInv,5);
    T_List<int> listbis(5,arrInv);
    cout << "Data after heap sort: " << listbis << endl;
    return 0;

}
