//
// Created by jeune on 17/01/2023.
//
#pragma once

#include "T_Node.h"

template <typename T>

class T_PriorityQueue {
private:
    T_Node<T> *start; //Code modulaire lol
    /*** Methodes implémentant le tri par tas ***/
    void heapify(size_t indexMin, size_t indexMax);
    void heapSort(size_t index);
public:
    T_PriorityQueue() : start(nullptr) {};
    explicit T_PriorityQueue(const T& elem) : start(new T_Node<T>(elem)) {};

    ~T_PriorityQueue() {
        if (this -> start)
            delete start;
    }

    inline void add(const T& elem) {
        if (start) {
            start->add(elem);
            heapSort(start->length());
        }
        else
            start = new T_Node<T>(elem);
    };

    inline size_t length() const {
        if (start)
            return start -> length();
        else
            return 0;
    } ;

    inline T pop() {
        if (start){
            T elem = start->get(0);
            start->remove(0);
            return elem;
        }
        throw std::runtime_error("Queue is empty");
    };

    template<typename U>
    friend std::ostream& operator <<(std::ostream& ostream,const T_PriorityQueue<U>& list);
};


template <typename T>
void T_PriorityQueue<T>::heapify(size_t indexMin, size_t indexMax) {
    size_t left = indexMin*2 + 1;
    size_t right = indexMin*2 + 2;
    size_t largest = indexMin;
    if (left < indexMax && this -> start->getData()[left] > this -> start->getData()[largest])
        largest = left;
    if (right < indexMax && this -> start->getData()[right] > this -> start->getData()[largest])
        largest = right;
    if (largest != indexMin) {
        std::swap(this -> start->getData()[indexMin],this -> start->getData()[largest]);
        heapify(indexMax, largest);
    }
}

template<typename T>
void T_PriorityQueue<T>::heapSort(size_t index) {
    for (int i = index / 2 - 1; i >= 0; --i)
        heapify(i, index);
    for (int i = index - 1; i >= 0; --i) {
        std::swap(this -> start->getData()[0],this -> start->getData()[i]);
        heapify(0, i);
    }
}

template<typename T>
std::ostream& operator << (std::ostream& ostream, const T_PriorityQueue<T>& pQueue) {
    std::cout << "[";
    for (size_t i = 0; i < pQueue.length(); ++i) {
        std::cout << pQueue.start->get(i);
        if (i != pQueue.length() - 1)
            std::cout << "; ";
    }
    std::cout << "]\n";
    return ostream;
}