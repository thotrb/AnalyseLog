/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Graph> (fichier Graph.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graph.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Graph::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// Algorithme :
//
//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Graph::Graph ( const Graph & unGraph )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graph>" << endl;
#endif
} //----- Fin de Graph (constructeur de copie)


Graph::Graph ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graph>" << endl;
#endif
} //----- Fin de Graph


Graph::~Graph ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graph>" << endl;
#endif
} //----- Fin de ~Graph

void Graph::AjouterLien(string cible, string reference){

    //inserer un nouvel élélement dans le noeud 


    if(arcs.find(cible) == arcs.end()){
        //document jamais recherche encore
        Noeud nouveauNoeud(reference);
        arcs.insert(make_pair(cible, nouveauNoeud));


    }else{

        //document deja recherche
        if(arcs.find(cible)->second.lienReference.find(reference) == arcs.find(cible)->second.lienReference.end()){
            //reference inconnue
            arcs.find(cible)->second.AjouterLien(reference);


        }else{
            //reference connue
            arcs.find(cible)->second.IncrementerLien(reference);
        }

    }


}

void Graph::AfficherGraph() const {

    map<string, Noeud>::const_iterator iterator = arcs.begin();
    while(iterator != arcs.end()){
        cout << iterator->first << " : " << endl;
        map<string, int>::const_iterator iterator2 = iterator->second.lienReference.begin();
        while(iterator2 != iterator->second.lienReference.end()){
            cout << " - " << iterator2->first << " -> " << iterator2->second << endl;
            iterator2++;
        }

        iterator ++;
    }

}

void Graph::ConserverLien(set<string> top10){

    //set<string>::const_iterator it = top10.begin();
    /**while(it != top10.end()){
        cout << " K : " << *it << " "  << endl;
        it++;
    }
**/
    map<string, Noeud>::const_iterator iterator = arcs.begin();

    for(; iterator!=arcs.end(); ){
        
        if( top10.find(iterator->first) == top10.end() ){
            arcs.erase(iterator++);
            //cout << "Suppression : " << iterator->first << endl;
        }else{
            //cout << "OK : " << iterator->first << " "  << endl;
            ++iterator;
        }
    }
}

void Graph::genererGraph(ofstream & flux) const{


    flux << "digraph{" << endl;

    map<string, Noeud>::const_iterator iterator = arcs.begin();
    int i =0;
    int j=arcs.size();
    string link;
    while(iterator != arcs.end()){
        flux << "node"<< i << " [label=\"" << iterator->first << "\"];" << endl;
        map<string, int>::const_iterator iterator2 = iterator->second.lienReference.begin();
        while(iterator2 != iterator->second.lienReference.end()){
            flux << "node"<< j << " [label=" << iterator2->first << "];" << endl;
            iterator2++;
            j++;
        }
        i++;
        iterator ++;
    }


    i =0;   
    j=arcs.size();
    iterator = arcs.begin();
    while(iterator != arcs.end()){
         map<string, int>::const_iterator iterator2 = iterator->second.lienReference.begin();
        while(iterator2 != iterator->second.lienReference.end()){
            flux << "node"<< j << " -> node" << i << " [label=" << iterator2->second << "];" << endl;
            iterator2++;
            j++;
        }

        iterator ++;
        i++;
    }


    flux << "}" << endl;

    flux.close();


}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

