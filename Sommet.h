//
// Created by ohno on 1/16/2023.
//

#pragma once
#include "T_List.h"
#include "Successeur.h"

class Sommet{
    size_t idVertex;
    T_List<Dijkstra_Successor::Successor> successors;

public:
    explicit Sommet(const size_t id) : idVertex(id), successors() {};
    Sommet(): idVertex(-1), successors() {};
    Sommet(const size_t id, const size_t numberSuccessors, const Dijkstra_Successor::Successor succs[]) :
        idVertex(id), successors(numberSuccessors,succs) {};
    ~Sommet() = default;

    friend std::ostream& operator << (std::ostream& ostream, const Sommet& sommet) {
        std::cout << "Sommet: " << sommet.idVertex << " - "<< sommet.successors;
        return ostream;
    }

    inline void addSuccesseur(const Dijkstra_Successor::Successor& successor) {
        this -> successors.add(successor);
    }
    inline void addSuccesseurs(const size_t size,const Dijkstra_Successor::Successor successors[]) {
        this->successors.add(size, successors);
    }

    inline void addSuccesseurs(const T_List<Dijkstra_Successor::Successor>& listSuccesseurs) {
        Dijkstra_Successor::Successor* arr = new Dijkstra_Successor::Successor[listSuccesseurs.length()];
        // On copie toutes les données d'un coup
        for (size_t i =0; i < listSuccesseurs.length() ; ++i)
            arr[i] = listSuccesseurs.get(i);
        // On les ajoute en bloc
        this -> successors.add(listSuccesseurs.length(),arr);
    }
};