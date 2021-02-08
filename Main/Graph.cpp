/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : $06/02/2021$
    copyright            : (C) $2021$ par $De Roover Trubert$
    e-mail               : $ $
*************************************************************************/

//---------- Réalisation de la classe <Graph> (fichier Graph.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <algorithm> // remove(), erase() 

//------------------------------------------------------ Include personnel
#include "Graph.h"
using namespace std;

//-------------------------------------------- Constructeurs - destructeur
Graph::Graph ( const Graph & unGraph )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graph>" << endl;
#endif
} //----- Fin de Graph (constructeur de copie)

Graph::Graph ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Graph>" << endl;
#endif
} //----- Fin de Graph

Graph::~Graph ( )
{

#ifdef MAP
    cout << "Appel au destructeur de <Graph>" << endl;
#endif
map<string, Noeud*>::const_iterator iterator;
for(iterator = arcs.begin(); iterator != arcs.end(); ++iterator){
    delete iterator->second;
}


} //----- Fin de ~Graph


void Graph::AjouterLien(string cible, string reference){

    //inserer un nouvel élélement dans le noeud 

    if(arcs.find(cible) == arcs.end()){
        //document jamais recherche encore
        Noeud * nouveauNoeud = new Noeud(reference);
        arcs.insert(make_pair(cible, nouveauNoeud));
    }
    else{
        //document deja recherche
        if(arcs.find(cible)->second->lienReference.find(reference) == arcs.find(cible)->second->lienReference.end()){
            //reference inconnue
            arcs.find(cible)->second->AjouterLien(reference);
        }
        else{
            //reference connue
            arcs.find(cible)->second->IncrementerLien(reference);
        }
    }
}

void Graph::AfficherGraph() const {

    map<string, Noeud*>::const_iterator iterator = arcs.begin();
    while(iterator != arcs.end()){
        cout << iterator->first << " : " << endl;
        map<string, int>::const_iterator iterator2 = iterator->second->lienReference.begin();
        while(iterator2 != iterator->second->lienReference.end()){
            cout << " - " << iterator2->first << " -> " << iterator2->second << endl;
            iterator2++;
        }
        iterator ++;
    }
}

void Graph::ConserverLien(set<string> top10){
    map<string, Noeud*>::const_iterator iterator = arcs.begin();

    map <string, Noeud*> tmp;
    set<string>::iterator it;
    for(it = top10.begin(); it != top10.end(); ++it){

        for(iterator = arcs.begin(); iterator != arcs.end(); ++iterator){
            if(*it == iterator->first){
                Noeud * n = new Noeud( *iterator->second);
                tmp.insert(make_pair(iterator->first, n));
            }
        }
    }
    for(iterator = arcs.begin(); iterator != arcs.end(); ++iterator){
        delete iterator->second;
    }
    arcs = tmp;

}


void Graph::genererGraph(ofstream & flux) const{

    flux << "digraph{" << endl;

    map<string, Noeud*>::const_iterator iterator = arcs.begin();
    int i =0;
    string link;
    bool insertion;
    map<string, int> lienNoeud;

    
    for(iterator = arcs.begin(); iterator != arcs.end(); ++iterator){
        flux << "node"<< i << " [label=\"" << iterator->first << "\"];" << endl;
        lienNoeud.insert(make_pair(iterator->first, i));
        map<string, int>::const_iterator iterator2;
        i++;
    }

    for(iterator = arcs.begin(); iterator != arcs.end(); ++iterator){
        map<string, int>::const_iterator iterator2;
        for(iterator2 = iterator->second->lienReference.begin(); iterator2 != iterator->second->lienReference.end(); ++iterator2){
            
            insertion = true;
            map<string, Noeud*>::const_iterator iterator3;
            for(iterator3 = arcs.begin(); iterator3 != arcs.end(); ++iterator3){
                string str = "\"" + iterator3->first + "\"";
                if(str == iterator2->first){
                    insertion = false;
                }
            }

            if(insertion){
                flux << "node"<< i << " [label=" << iterator2->first << "];" << endl;
                lienNoeud.insert(make_pair(iterator2->first, i));
                i++;

            }

        }
    }


    for(iterator = arcs.begin(); iterator != arcs.end(); ++iterator){
        map<string, int>::const_iterator iterator2;

        for(iterator2 = iterator->second->lienReference.begin(); iterator2 != iterator->second->lienReference.end(); ++iterator2){
            

            string t = iterator2->first.substr( iterator2->first.find_first_not_of( '\"' ) ); 
           t.erase(remove( t.begin(), t.end(), '\"'), t.end() );  

            if(lienNoeud.find(t) != lienNoeud.end()){
                flux << "node"<< lienNoeud.find(t)->second << " -> node" << lienNoeud.find(iterator->first)->second << " [label=" << iterator2->second << "];" << endl;
            }else{
                t = "\"" + t +  "\"" ;
                if(lienNoeud.find(t) != lienNoeud.end()){
                    flux << "node"<< lienNoeud.find(t)->second << " -> node" << lienNoeud.find(iterator->first)->second << " [label=" << iterator2->second << "];" << endl;
                }
            }

        }
    }
    

    flux << "}" << endl;
    flux.close();


}


