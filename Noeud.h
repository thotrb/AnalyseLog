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
#include <map>
#include <cstring>
#include <iostream>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Noeud>
//
//
//------------------------------------------------------------------------
class Graph;
class Noeud 
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
    //Noeud & operator = ( const Noeud & unNoeud );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Noeud ( const Noeud & unNoeud );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Noeud(const std::string reference);

    Noeud ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Noeud ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterLien(std::string reference);

    void IncrementerLien(std::string reference);


    friend Graph;


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    std::map <std::string, int> lienReference; // contient pour chaque reference, le nombre de hit vers une cible

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Noeud>

#endif // Noeud_H

