/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : $06/02/2021$
    copyright            : (C) $2021$ par $De Roover Trubert$
    e-mail               : $ $
*************************************************************************/

//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Noeud.h"
using namespace std;

//-------------------------------------------- Constructeurs - destructeur
Noeud::Noeud ( const Noeud & unNoeud )
{
map<string, int>::const_iterator iterator;
 for(iterator = unNoeud.lienReference.begin(); iterator != unNoeud.lienReference.end(); ++iterator){
     lienReference.insert(make_pair(iterator->first, iterator->second));
}

#ifdef MAP
    cout << "Appel au constructeur de copie de <Noeud>" << endl;
#endif
} //----- Fin de Noeud (constructeur de copie)

Noeud::~Noeud ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Noeud>" << endl;
#endif
} //----- Fin de ~Noeud

Noeud::Noeud(const string reference){
#ifdef MAP
    cout << "Appel au constructeur de <Noeud>" << endl;
#endif
    lienReference.insert(make_pair(reference, 1));
}

void Noeud::AjouterLien(string reference){
    lienReference.insert(make_pair(reference, 1));
}

void Noeud::IncrementerLien(string reference){
    lienReference.find(reference)->second += 1;
}