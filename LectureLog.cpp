/*************************************************************************
                           LectureLog  -  description
                             -------------------
    début                : $06/02/2021$
    copyright            : (C) $2021$ par $De Roover Trubert$
    e-mail               : $ $
*************************************************************************/

//---------- Réalisation de la classe <LectureLog> (fichier LectureLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LectureLog.h"
using namespace std;

//------------------------------------------------------------- Constantes
#define SIZE 50

//-------------------------------------------- Constructeurs - destructeur
LectureLog::LectureLog ( const LectureLog & unLectureLog )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LectureLog>" << endl;
#endif
} //----- Fin de LectureLog (constructeur de copie)

LectureLog::LectureLog ( ) : m_dernierLog(){
#ifdef MAP
    cout << "Appel au constructeur de <LectureLog>" << endl;
#endif
} //----- Fin de Analog

LectureLog::~LectureLog ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <LectureLog>" << endl;
#endif
} //----- Fin de ~LectureLog


//----------------------------------------------------- Méthodes publiques

string LectureLog::Extraire(string delimiter, string * ptBlocTemps){
    string morceauLigne;
    int positionDelimiter = (*ptBlocTemps).find(delimiter);
    morceauLigne = (*ptBlocTemps).substr(0, positionDelimiter);
    (*ptBlocTemps).erase(0, positionDelimiter + delimiter.length());
    return morceauLigne;
}

const Log & LectureLog::lireLigne(string & ligneLog) {

    string delimiter = " ";
    size_t pos = 0;
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

    informations[3].erase(0, 1); //On efface le [
    string * blocTemps = &informations[3];
    delimiter = "/";
    m_dernierLog.temps.jour = stoi(Extraire(delimiter, blocTemps));
    m_dernierLog.temps.mois = Extraire(delimiter, blocTemps);

    delimiter = ":";
    m_dernierLog.temps.annee = stoi(Extraire(delimiter, blocTemps));
    m_dernierLog.temps.heure = stoi(Extraire(delimiter, blocTemps));
    m_dernierLog.temps.minute = stoi(Extraire(delimiter, blocTemps));
    m_dernierLog.temps.seconde = stoi(informations[3]); 

    m_dernierLog.decallageHoraire = informations[4];
    m_dernierLog.typeRequete = informations[5];
    m_dernierLog.documentRecherche = informations[6];
    m_dernierLog.protocole = informations[7];
    m_dernierLog.codeRetour = informations[8];
    m_dernierLog.quantiteDonnee = informations[9];
    m_dernierLog.referer = informations[10];

    //nettoyer l'url renseigner l'url de base dans le fichier config
    m_dernierLog.navigateur = "";
    for(int i=10; i<SIZE; i++) {
        m_dernierLog.navigateur +=  " " + informations[i];
    }


    return m_dernierLog;   
}