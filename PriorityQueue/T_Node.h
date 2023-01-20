//
// Created by ohno on 1/18/2023.
//
#pragma once
#include <iostream>
#define BASE_SIZE 5

template <typename T>
class T_Node {
    private:
        //Représente la taille du tableau indiquée et accessible à l'utilisateur
        size_t size;
        //Représente la taille réelle du tableau
        size_t capacity;
        //Tableau de données
        T* data;
        //Gestion de l'allocation "dynamique"
        void reallocMore();
        void reallocLess();
        //Gestion foreach loop
        typedef T* iterator;
        typedef const T* const_iterator;

    public:
        //Constructeurs
        T_Node() : size(0), capacity(BASE_SIZE), data(new T[capacity]) {};
        explicit T_Node(const T& elem) : size(1), capacity(BASE_SIZE), data(new T[capacity]{elem}) {};
        explicit T_Node(size_t size) : size(0), capacity(size), data(new T[capacity]) {
            #undef BASE_SIZE        //On enlève la définition de BASE_SIZE
            #define BASE_SIZE size  // On la réintroduit avec pour nouvelle valeur, celle fournie par l'utilisateur
        };                      // Permet ainsi de redéfinir le tableau suivant une taille fournie par l'utilisateur

        //Destructeur
        ~T_Node() {
            if(data)
                delete[] data;
        }

        //Operations
        T get(size_t i);                                      // Retourne l'element à la position i
        T* getData() {return this -> data;};                  // Retourne le tableau de données
        void add(const T& elem);                              // Ajoute un element à la fin du tableau
        void add(const T_Node<T>& node);                      // Ajoute les elements d'un noeud à la fin du tableau
        void remove(size_t index);                            // Supprime l'element à la position i
        inline size_t length() const {return this -> size;} ; // Retourne la taille accessible à du tableau

        //Iterateurs
        iterator begin() {return &data[0];}                   // Retourne un pointeur vers le premier element
        const_iterator begin() const {return &data[0];}       // Retourne un pointeur constant vers le premier element
        iterator end() {return &data[size];}                  // Retourne un pointeur vers le dernier element
        const_iterator end() const {return &data[size];}      // Retourne un pointeur constant vers le dernier element
};

/********************************************* PRIVATE FUNCTIONS *****************************************************/

/**
 * @brief Augmente la taille du tableau de données
 * @tparam T type determiné à la compilation
 */
template<typename T>
void T_Node<T>::reallocMore() {
    T* temp = new T[capacity * 2];
    std::move(data,data + size,temp);
    delete[] data;
    data = temp;
    capacity *= 2;
}
/**
 * @brief Diminue la taille du tableau de données
 * @tparam T type determiné à la compilation
 */
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

/********************************************** PUBLIC FUNCTIONS *****************************************************/

/**
 * @brief Retourne l'element à la position i
 * @tparam T type determiné à la compilation
 * @param i position de l'element
 * @return T element à la position i
 */

template<typename T>
T T_Node<T>::get(const size_t i) {
    if (i >= 0 && i < size)
        return data[i];
    throw std::invalid_argument("List indices go from 0 to " + std::to_string(this->size));
}

/**
 * @brief Ajoute un element à la fin du tableau
 * @tparam T type determiné à la compilation
 * @param elem element à ajouter
 */
template<typename T>
void T_Node<T>::add(const T &elem) {
    if (this -> size == this -> capacity)
        reallocMore();
    data[size++] = elem; // Incrémente par la même occasion l'attribut size
}

/**
 * @brief Ajoute les elements d'un noeud à la fin du tableau
 * @tparam T type determiné à la compilation
 * @param node noeud à ajouter
 */
template<typename T>
void T_Node<T>::add(const T_Node<T> &node) {
    while (this -> size + node.size > this -> capacity)     // On verifie si le tableau est assez grand
        reallocMore();                                      // Si non, on augmente sa taille
    std::move(node.data,node.data + node.size,data + size);
    size += node.size;
}

/**
 * @brief Supprime l'element à la position i et diminue la taille du tableau manipulé par la liste si necessaire
 * @tparam T type determiné à la compilation
 * @param index position de l'element à supprimer
 */
template<typename T>
void T_Node<T>::remove(size_t index) {
    if (index >= 0 && index < size) {
        std::move(data + index + 1, data + size, data + index);
        size--;
        if (size <= capacity / 2)    //Si la capacité du tableau est trop grande par rapport aux données qu'il contient
            reallocLess();          //On diminue sa taille
        }
    else
        throw std::invalid_argument("List indices go from 0 to " + std::to_string(this->size));
}