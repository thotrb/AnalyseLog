
/*************************************************************************
                           LectureLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LectureLog> (fichier LectureLog.h) ----------------
#if ! defined ( LectureLog_H )
#define LectureLog_H
#include <cstring>
#include <iostream>
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Log {
 	string date;
	string heure;
	string decallageHoraire;
	string typeRequete;
	string documentRecherche;
	string codeRetour;
	string protocole;
	string quantiteDonnee;
	string referer;
	string navigateur;

};

//------------------------------------------------------------------------
// Rôle de la classe <LectureLog>
//
//
//------------------------------------------------------------------------

class LectureLog 
{
//----------------------------------------------------------------- PUBLIC

typedef struct Log Log;

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //LectureLog & operator = ( const LectureLog & unLectureLog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LectureLog ( const LectureLog & unLectureLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LectureLog ( ) : dernierLog(){};
    // Mode d'emploi :
    //
    // Contrat :
    //

    ~LectureLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

	const Log & lireLigne(string & ligneLog);

/**
	Log(string d = "", string h ="" ,string decallageH = "", string typeR = "", string documentR = "", 
		string proto = "", int st = 0, string quantiteD = "", string adressePrec = "", string nav = "") 
		: date(d), heure(h), decallageHoraire(decallageH), typeRequete(typeR), documentRecherche(documentR),
		protocole(proto), statut(st), quantiteDonnee(quantiteD), adressePrecedente(adressePrec), navigateur(nav){}
        friend class Catalogue;
**/
	
	//friend istream & operator >>(istream & is, Log & l );

	bool lireFichier(const string & nomFichier);



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
Log dernierLog;


//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <LectureLog>

#endif // LectureLog_H





