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
    Cette méthode permet de 

    */

    void genererGraph(std::ofstream & flux) const;
    /* Mode d'emploi :
    Cette méthode permet de 

    */

    void AfficherGraph()const;
    /* Mode d'emploi :
    Cette méthode permet de 

    */

    void ConserverLien(std::set<std::string> top10);
    /* Mode d'emploi :
    Cette méthode permet de 

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
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégées
int nbNoeuds = 0;
std::map <std::string, Noeud> arcs;

};

#endif // Graph_H

