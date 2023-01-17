//
// Created by jeune on 17/01/2023.
//
#pragma once

#include "T_Node.h"

template <typename T>

//Queue doit permettre trois opérations :
// Récupérer un élément en tête pop
// Ajout d'un élément suivant sa priorité add



class T_PriorityQueue {
    T_Node<T> *start;
    void heapify();
    void heapSort();
public:
    T_PriorityQueue() : start(nullptr) {};
    explicit T_PriorityQueue(const T& elem) : start(new T_Node<T>(elem)) {};

    ~T_PriorityQueue() {
        if (this -> start)
            delete start;
    }

    void add(const T& elem);
    void pop();
};

template<typename T>
void T_PriorityQueue<T>::add(const T &elem) {

}

template <typename T>
void T_PriorityQueue<T>::heapify(size_t n) {
    size_t size = this -> start -> length();
    size_t left =  size * 2 + 1;
    size_t right = size * 2 + 2;
    size_t largest = size;
    if (left < n && array[left] > array[largest])
        largest = left;
    if (right < n && array[right] > array[largest])
        largest = right;
    if (largest != size) {
        std::swap(array[size],array[largest]);
        heapify(array, n, largest);
    }
}

template<typename T>
void heapSort(/*T array[], size_t n*/) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(array, i, n);
    for (int i = n - 1; i >= 0; --i) {
        std::swap(array[0],array[i]);
        heapify(array, 0, i);
    }
}