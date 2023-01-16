//
// Created by ohno on 1/16/2023.
//

#pragma once
#include "Sommet.h"



class Graph{
    T_List<Sommet> sommets;
public:
    Graph() : sommets() {};
    Graph(size_t size, Sommet sommets[]) : sommets(size,sommets) {};
    ~Graph() = default;
    void add(const Sommet& sommet) {sommets.add(sommet);};
    void addSommets(size_t size, Sommet sommets[]) {
        if(this -> sommets.length() == 0)
            this -> sommets = T_List<Sommet>(size,sommets);
    }
    void addSommets(const T_List<Sommet>& sommets) {
        Sommet* arr = new Sommet[sommets.length()];
        // On copie toutes les données d'un coup
        for (size_t i =0; i < sommets.length() ; ++i)
            arr[i] = sommets.get(i);
        // On les ajoute en bloc
        this -> sommets.add(sommets.length(),arr);
    }

    friend std::ostream& operator << (std::ostream& ostream, const Graph& graph) {
        std::cout << "{\n";
        for (size_t i = 0; i < graph.sommets.length() ; ++i)
            std::cout << graph.sommets.get(i);
        std::cout << "}\n" ;
        return ostream;
    }
};
