//
// Created by ohno on 1/16/2023.
//

#pragma once

#include <ostream>

namespace Dijkstra_Successor {
    /**
     * Permet d'avoir un objet contenant le couple (sommet_successeur,cout)
     */
    class Successor {
    private:
        // Identifie le sommet successeur
        int idVertex;
        // Poids entre le sommet parent et le sommet en question
        int weight;

    public:
        Successor(const int idSuccessor, const int weight) : idVertex(idSuccessor), weight(weight){};
        Successor() : idVertex(-1), weight(-1) {};
        ~Successor() = default;

        inline Successor& operator =(const Successor& successor) {
            if (this != &successor) {
                this->idVertex = successor.idVertex;
                this->weight = successor.weight;
            }
            return *this;
        };

        inline bool operator == (const Successor& successor) const{
            return (this -> idVertex == successor.idVertex && this -> weight == successor.weight);
        }

        inline int getSuccessorId()const {
            return this -> idVertex;
        };

        inline int getSuccessorWeight() const{
            return this -> weight;
        };

        friend std::ostream& operator << (std::ostream& ostream, const Successor successor) {
            ostream << "[successeur : " << successor.getSuccessorId() << " | cout : " << successor.weight << "]";
            return ostream;
        };
    };

}