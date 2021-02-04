/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Noeud.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Noeud::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//Noeud & Noeud::operator = ( const Noeud & unNoeud )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Noeud::Noeud ( const Noeud & unNoeud )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Noeud>" << endl;
#endif
} //----- Fin de Noeud (constructeur de copie)


Noeud::Noeud(const string reference){
    lienReference.insert(make_pair(reference, 1));
}

void Noeud::AjouterLien(string reference){
    lienReference.insert(make_pair(reference, 1));
}

void Noeud::IncrementerLien(string reference){
    lienReference.find(reference)->second += 1;
}


Noeud::~Noeud ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Noeud>" << endl;
#endif
} //----- Fin de ~Noeud




//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

