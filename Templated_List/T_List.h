//
// Created by ohno on 1/16/2023.
//

#pragma once
#include "T_Node.h"

template <typename T>
class T_List {
    private:
        T_Node<T>* start;
    public:
        //Constructeurs
        T_List() : start(nullptr) {};
        explicit T_List(const T& elem) : start(new T_Node<T>(elem)) {};
        T_List(const T_List<T>& list) : start(new T_Node<T>(*list.start)) {};
        //Destructeur
        ~T_List() {
            if (this -> start)
                delete start;
        }
        //Operations
        inline size_t length() const {return (start ? start->length() : 0);} ;
        inline bool isEmpty() const {return this -> start;};
        inline T get(size_t i) const;
        void add(const T& elem);
        void add(const T_List<T>& list);
        void remove(size_t index);
        //Operateurs
        T_List<T>& operator= (const T_List<T>& list);
        template<typename U>
        friend std::ostream& operator <<(std::ostream& ostream,const T_List<U>& list);
};

/*********************************************************************************************************************/
/******************************************* SURCHARGE OPERATEUR *****************************************************/
/*********************************************************************************************************************/

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
T_List<T> &T_List<T>::operator=(const T_List<T> &list) {
    if (this != &list){
        delete start;
        this -> start = new T_Node<T>(*list.start);
    }
    return *this;
}

/*********************************************************************************************************************/
/********************************************** PUBLIC FUNCTIONS *****************************************************/
/*********************************************************************************************************************/

template<typename T>
void T_List<T>::add(const T &elem) {
    if (!this -> start)
        this -> start = new T_Node<T>(elem);
    else
        this -> start->add(elem);
}

template<typename T>
void T_List<T>::add(const T_List<T>& list) {
    if(!this -> start)
        this -> start = new T_Node<T>(*list.start);
    else
        this -> start->add(*list.start);
}

template<typename T>
void T_List<T>::remove(size_t index) {
    if (this -> start)
        this -> start->remove(index);
}

template<typename T>
T T_List<T>::get(size_t i) const {
    return this -> start->get(i);
}


