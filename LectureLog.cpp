/*************************************************************************
                           LectureLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LectureLog> (fichier LectureLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "LectureLog.h"

//------------------------------------------------------------- Constantes
#define SIZE 50
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LectureLog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//LectureLog & LectureLog::operator = ( const LectureLog & unLectureLog )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LectureLog::LectureLog ( const LectureLog & unLectureLog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LectureLog>" << endl;
#endif
} //----- Fin de LectureLog (constructeur de copie)


LectureLog::~LectureLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LectureLog>" << endl;
#endif
} //----- Fin de ~LectureLog


const Log & LectureLog::lireLigne(string & ligneLog) {

    string delimiter = " ";
    int pos = 0;
    string token;
    string informations[SIZE];
    int i=0;
    while ((pos = ligneLog.find(delimiter)) != string::npos) {
        token = ligneLog.substr(0, pos);
        informations[i] = token;
        ligneLog.erase(0, pos + delimiter.length());
        i++;
    }
    informations[i] = ligneLog;

    dernierLog.date = informations[3];
    dernierLog.heure = informations[3];
    dernierLog.decallageHoraire = informations[4];
    dernierLog.typeRequete = informations[5];
    dernierLog.documentRecherche = informations[6];
    dernierLog.protocole = informations[7];
    dernierLog.codeRetour = informations[8];
    dernierLog.quantiteDonnee = informations[9];
    dernierLog.referer = informations[10];

/**
    delimiter = "/";
    while ((pos = dernierLog.documentRecherche.find(delimiter)) != string::npos) {
        token = dernierLog.documentRecherche.substr(0, pos);
        dernierLog.documentRecherche.erase(0, pos + delimiter.length());
    }
    dernierLog.referer = token;

**/

    //nettoyer l'url renseigner l'url de base dans le fichier config

    dernierLog.navigateur = "";

    for(int i=10; i<SIZE; i++) {
        dernierLog.navigateur +=  " " + informations[i];
    }




    return dernierLog;   
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

