/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Noeud> (fichier Noeud.h) ----------------
#if ! defined ( Noeud_H )
#define Noeud_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <cstring>
#include <iostream>

//------------------------------------------------------------------------
// Rôle de la classe <Noeud>
/*

*/
//------------------------------------------------------------------------
class Graph;
class Noeud 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterLien(std::string reference);
    /* Mode d'emploi :
    Cette méthode permet de 

    */

    void IncrementerLien(std::string reference);
    /* Mode d'emploi :
    Cette méthode permet de 
    
    */

//-------------------------------------------- Constructeurs - destructeur
    Noeud ( const Noeud & unNoeud );
    // Mode d'emploi (constructeur de copie) :
    // Construit un Noeud par copie d'un Noeud
    
    Noeud(const std::string reference);
    // Mode d'emploi (constructeur) :
    //

    Noeud ( );

    virtual ~Noeud ( );
    // Mode d'emploi (destructeur) :
    //
    
    friend Graph;


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégées
    std::map <std::string, int> lienReference; // contient pour chaque reference, le nombre de hit vers une cible

};

#endif // Noeud_H

