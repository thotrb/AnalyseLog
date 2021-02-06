
/*************************************************************************
                           Analog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Analog> (fichier Analog.h) ----------------
#if ! defined ( Analogue_H )
#define Analogue_H

//--------------------------------------------------- Interfaces utilisées

#include "LectureLog.h"
#include "Graph.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Analog>
//
//
//------------------------------------------------------------------------

class Analog 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

void lireFichier(std::string & fichier, int * optionHeure);

void setOption(std::string option);

void genererGraph(std::string nomFichierSortie) const;



    
//-------------------------------------------- Constructeurs - destructeur
    
    Analog ( const Analog & unAnalog );
    // Mode d'emploi (constructeur de copie) :
    // Construit un Analog par copie d'un Analog

    Analog ();
    // Mode d'emploi (constructeur) :
    // Construit un LectureLog en lui allouant la mémoire nécessaire pour ces deux pointeurs

    virtual ~Analog ( );
    // Mode d'emploi (destructeur) :
    // Libére la mémoire allouée aux deux pointeurs


//------------------------------------------------------------------ PRIVE
private : 

protected:
    LectureLog * lectureLog;
    Graph * graph;
    bool optionE ;
    bool optionG ;
    bool optionT ;
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Analog>

#endif // Analog_H

