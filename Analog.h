
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
using namespace std;

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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Analog ( const Analog & unAnalog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Analog ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Analog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void lireFichier(string & fichier);

    string split(string & src, string delim);

    void setOption(string option);

    void genererGraph(string nomFichierSortie) const;
    int main(int argc, char* argv[]);



    


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

