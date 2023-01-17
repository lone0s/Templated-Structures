//
// Created by ohno on 1/16/2023.
//
#include <iostream>
#pragma once

template <typename T>
class T_Node {
    size_t size;
    T* data;

public:
    T_Node() : size(0),data(nullptr) {};
    explicit T_Node(const T elem) : size(1), data(new T[1]{elem}) {};
    T_Node(const size_t localSize,const T array[]) : size(localSize), data(new T[localSize]) {
        for (size_t i = 0 ; i < localSize ; ++i) {
            this -> data[i] = array[i];
        }
    };
    T_Node(const T_Node<T>& node) : size(node.size), data(new T[node.size])  {
        for (size_t i = 0 ; i < node.size ; ++i)
            this -> data[i] = node.data[i];
    }
    // Array's Dynamic Property is defined here
    void add(const T& elem);
    void add(size_t sze, const T elem[]);
    void add(const T_Node<T>& node);

    ~T_Node() {
        if(data)
            delete[] data;
    }
    inline size_t length() const {return this -> size;} ;
    inline T get(size_t i) const {
        if(i >= 0 && i < size)
            return data[i];
        else
            throw std::invalid_argument("Indice incorrect par rapport a la taille de la liste\n");
    }

    inline T& get(size_t i) {
        if(i >= 0 && i < size)
            return data[i];
        else
            throw std::invalid_argument("Indice incorrect par rapport a la taille de la liste\n");
    }

    inline T* getData() const {
        return data;
    }

    void remove(size_t index);

};

/*!!!!!!!!!! Fonction qui coute cher !!!!!!!!!!*/
template <typename T>
void T_Node<T>::add(const T& elem) {
    size_t newSize = this -> size + 1;
    T* newArr = new T[newSize];
    for(size_t i = 0 ; i < this -> size ; ++i) {
        newArr[i] = data[i];
    }
    newArr[newSize - 1] = elem;
    if (data) {
        delete[] data;
    }
    this -> data = newArr;
    this -> size = newSize;
}

/*!!!!!!!!!! Fonction qui coute cher !!!!!!!!!!*/
template <typename T>
void T_Node<T>::add(const size_t sze, const T elem[]) {
    // On instancie un tableau qui contiendra les nouvelles données
    size_t newSize = this -> size + sze;
    T* newArr = new T[newSize];
    // On le remplie avec les éléments de l'existante liste
    for(size_t i = 0 ; i < this->size ; ++i)
        newArr[i] = this ->get(i);
    // On le complete du nouveau tableau
    for(size_t i = this -> size; i < this-> size + sze ; ++i)
        newArr[i] = elem[i - this -> size];
    if (data)
        //On supprime l'ancien
        delete[] data;
    //On le retourne a la liste
    this -> data = newArr;
    this -> size = newSize;
}

/*!!!!!!!!!! Fonction qui coute cher !!!!!!!!!!*/
template<typename T>
void T_Node<T>::add(const T_Node<T> &node) {
    size_t newSize = this -> size + node.size;
    T* newArr = new T[newSize];
    for(size_t i = 0 ; i < this->size ; ++i)
        newArr[i] = this ->get(i);
    for(size_t i = this -> size; i < this-> newSize ; ++i)
        newArr[i] = node[i - this -> size];
    if (data)
        //On supprime l'ancien
        delete[] data;
    //On le retourne a la liste
    this -> data = newArr;
    this -> size = newSize;
}

template<typename T>
void T_Node<T>::remove(size_t i){
    if(i >= 0 && i < size){
        size_t newSize = this -> size - 1;
        T* newArr = new T[newSize];
        for(size_t j = 0 ; j < i ; ++j)
            newArr[j] = this ->get(j);
        for(size_t j = i ; j < newSize ; ++j)
            newArr[j] = this ->get(j+1);
        if (data)
            //On supprime l'ancien
            delete[] data;
        //On le retourne a la liste
        this -> data = newArr;
        this -> size = newSize;
    }
    else
        throw std::invalid_argument("Indice incorrect par rapport a la taille de la liste\n");
}
