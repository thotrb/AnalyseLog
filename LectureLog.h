
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

//--------------------------------------------------- Interfaces utilisées
#include <cstring>

//------------------------------------------------------------------ Types
struct Date{
    unsigned int seconde;
    unsigned int minute;
    unsigned int heure;
    unsigned int jour;
    std::string mois;
    unsigned int annee;
};

struct Log {
 	Date temps;
	std::string heure;
	std::string decallageHoraire;
	std::string typeRequete;
	std::string documentRecherche;
	std::string codeRetour;
	std::string protocole;
	std::string quantiteDonnee;
	std::string referer;
	std::string navigateur;
};

//------------------------------------------------------------------------
/*Rôle de la classe <LectureLog>
Catalogue possède un attribut de type Log. Ce type définit par la struct ci-dessus contient les informations
nécessaires d'une ligne d'un fichier .log
*/
//------------------------------------------------------------------------

class LectureLog 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
   
    std::string Extraire(std::string delimiter, std::string * aExtraire);
    /* Mode d'emploi :
    Cette méthode permet d'extraire une chaine de caractères de la chaine pointée passée en paramètres. 
    La chaine située avant la chaine de délimitaion passé en paramètres est extraite */


//-------------------------------------------- Constructeurs - destructeur
    LectureLog ( const LectureLog & unLectureLog );
    // Mode d'emploi (constructeur de copie) :
    // Construit un LectureLog par copie d'un LectureLog
    
    LectureLog ( );
    // Mode d'emploi (constructeur) :
    // Construit un LectureLog en lui créeant son attribut de type Log

    ~LectureLog ( );
    // Mode d'emploi (destructeur) :
    // aucune mémoire n'est allouée pour un LectureLog donc ce destructeur ne fait rien

	const Log & lireLigne(std::string & ligneLog);

	bool lireFichier(const std::string & nomFichier);



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégées
Log m_dernierLog;

};

#endif // LectureLog_H





