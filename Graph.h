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

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include "Noeud.h"

//------------------------------------------------------------------------
// Rôle de la classe <Graph>
/*

*/
//------------------------------------------------------------------------

class Graph 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
   void AjouterLien(std::string cible, std::string reference);
   /* Mode d'emploi :
    Cette méthode permet d'insérer un nouvel élément dans la Map
    */

    void genererGraph(std::ofstream & flux) const;
    /* Mode d'emploi :
    Cette méthode permet de remplir le flux passé en paramètre avec le code
    correspondant nécessaire à la génération d'un graphique.

    */

    void AfficherGraph()const;
    /* Mode d'emploi :
    Cette méthode permet d'afficher dans la console tous les éléments du graph
    pour le débuggage
    */

    void ConserverLien(std::set<std::string> top10);
    /* Mode d'emploi :
    Cette méthode permet de conserver dans la Map uniquement les éléments
    correspondant au top 10 des documents recherchés, ie uniquement ceux qui nous intéressent.
    Elle supprimer tous les autres éléments.
    */ 


//-------------------------------------------- Constructeurs - destructeur
    Graph ( const Graph & unGraph );
    // Mode d'emploi (constructeur de copie) :
    // Construit un Graph par copie d'un Graph
    
    Graph ( );
    // Mode d'emploi (constructeur) :
    // créé un nouveau Graph
    
    virtual ~Graph ( );
    // Mode d'emploi (destructeur) :
    // Libére la mémoire allouée

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégées
int nbNoeuds = 0;
std::map <std::string, Noeud> arcs;

};

#endif // Graph_H

