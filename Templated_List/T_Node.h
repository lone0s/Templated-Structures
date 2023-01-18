//
// Created by ohno on 1/18/2023.
//
#pragma once
#include <iostream>
#define BASE_SIZE 5


template <typename T>
class T_Node {
private:
    //Représente la taille du tableau accesible à l'utilisateur
    size_t size;
    //Représente la taille réelle du tableau
    size_t capacity;
    T* data;
    //Gestion de l'allocation "dynamique"
    void reallocMore();
    void reallocLess();

public:
    //Constructeurs
    T_Node() : size(0), capacity(BASE_SIZE), data(new T[capacity]) {};
    explicit T_Node(const T& elem) : size(1), capacity(BASE_SIZE), data(new T[capacity]{elem}) {};
    T_Node(const T_Node<T>& node) : size(node.size), capacity(node.capacity), data(new T[capacity]) {
        std::move(node.data,node.data + size,data);
    }
    //Destructeur
    ~T_Node() {
        if(data)
            delete[] data;
    }
    //Operations
    T get(size_t i);
    T* getData() {return this -> data;};
    void add(const T& elem);
    void add(const T_Node<T>& node);
    void remove(size_t index);
    inline size_t length() const {return this -> size;} ;
};

/*********************************************************************************************************************/
/********************************************* PRIVATE FUNCTIONS *****************************************************/
/*********************************************************************************************************************/

template<typename T>
void T_Node<T>::reallocMore() {
    T* temp = new T[capacity * 2];
    std::move(data,data + size,temp);
    delete[] data;
    data = temp;
    capacity *= 2;
}

template<typename T>
void T_Node<T>::reallocLess() {
    size_t newSize = capacity / 2;
    if(newSize < BASE_SIZE)
        newSize = BASE_SIZE;
    T* temp = new T[newSize];
    std::move(data,data + size,temp);
    delete[] data;
    data = temp;
    capacity /= 2;
}

/*********************************************************************************************************************/
/********************************************** PUBLIC FUNCTIONS *****************************************************/
/*********************************************************************************************************************/

template<typename T>
T T_Node<T>::get(const size_t i) {
    if (i >= 0 && i < size)
        return data[i];
    throw std::invalid_argument("List indices go from 0 to " + std::to_string(this->size));
}

template<typename T>
void T_Node<T>::add(const T &elem) {
    if (this -> size == this -> capacity)
        reallocMore();
    data[size++] = elem;
}

template<typename T>
void T_Node<T>::add(const T_Node<T> &node) {
    while (this -> size + node.size > this -> capacity)
        reallocMore();
    std::move(node.data,node.data + node.size,data + size);
    size += node.size;
}

template<typename T>
void T_Node<T>::remove(size_t index) {
    if (index >= 0 && index < size) {
        std::move(data + index + 1,data + size,data + index);
        size--;
        if(size < capacity / 2)
            reallocLess();
    }
    else
        throw std::invalid_argument("List indices go from 0 to " + std::to_string(this->size));
}

