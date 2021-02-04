/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Graph> (fichier Graph.h) ----------------
#if ! defined ( Graph_H )
#define Graph_H
#include <iostream>
#include <cstring>
#include <map>
#include <set>

using namespace std;
//--------------------------------------------------- Interfaces utilisées

#include "Noeud.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graph>
//
//
//------------------------------------------------------------------------

class Graph 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //Graph & operator = ( const Graph & unGraph );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Graph ( const Graph & unGraph );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Graph ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graph ( );
    // Mode d'emploi :
    //
    // Contrat :
    //


    void AjouterLien(string cible, string reference);

    void genererGraph(ofstream & flux) const;

    void AfficherGraph()const;

    void ConserverLien(set<string> top10); 


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
int nbNoeuds = 0;
map <string, Noeud> arcs;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Graph>

#endif // Graph_H

