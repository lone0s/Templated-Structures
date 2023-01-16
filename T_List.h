//
// Created by ohno on 1/16/2023.
//

#pragma once
#include "T_Node.h"

template <typename T>
class T_List {
    T_Node<T>* start;

public:
    T_List() : start(nullptr) {};
    T_List(const size_t numberElems,const T array[]) : start(new T_Node<T>(numberElems,array)) {};
    ~T_List() {
        if (this -> start)
            delete start;
    }
    T_List(const T_List<T>& list) {
        this -> start = new T_Node<T>(list.length(), list.start->getData());
    }

    T_List<T>& operator= (const T_List<T>& list) {
        if (this != &list){
            delete start;
            this -> start = new T_Node<T>(list.length(),list.start -> getData());
        }
        return *this;
    }

    inline bool isEmpty() const {return this -> start;};
    inline T get(size_t i) {
        try {
            return start->get(i);
        }
        catch (std::exception& e){
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    inline T get(size_t i) const {
        try {
            return start->get(i);
        }
        catch (std::exception& e){
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    inline size_t length() const {
        if (start)
            return start -> length();
        else
            return 0;
    } ;

    void add(const T& elem);
    void add(const size_t sze, const T elem[]);
    void add(const T_List<T>& list);

    template<typename U>
    friend std::ostream& operator <<(std::ostream& ostream,const T_List<U>& list);

};

template<typename T>
std::ostream& operator << (std::ostream& ostream, const T_List<T>& list) {
    std::cout << "[";
    for (size_t i = 0; i < list.length(); ++i) {
        std::cout << list.get(i);
        if (i != list.length() -1)
            std::cout << "; ";
    }
    std::cout << "]\n";
    return ostream;
}

template<typename T>
void T_List<T>::add(const T &elem) {
    if (!this -> start)
        this -> start = new T_Node<T>(elem);
    else
        this -> start->add(elem);
}

template<typename T>
void T_List<T>::add(const size_t sze, const T elem[]) {
    if (!this -> start)
        this -> start = new T_Node<T>(sze,elem);
    else
        this -> start ->add(sze,elem);
}

template<typename T>
void T_List<T>::add(const T_List<T> list) {
    if(!this -> start)
        this -> start = new T_Node<>
}


