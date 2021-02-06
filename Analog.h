
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
/*Rôle de la classe <Analog>
Cette classe est la clase centrale, c'est elle qui gère le déroulement de la lecture du fichier log.
Analog possède 3 Booléens qui correspondent aux 3 options pouvant être demandées. Elle possède aussi un pointeur sur un attribut de type Graph
et un pointeur sur attribut de type LectureLog. 
*/
//------------------------------------------------------------------------

class Analog 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void lireFichier(std::string & fichier, int * optionHeure);
    /* Mode d'emploi :
    Cette méthode permet de lire un fichier en s'appuyant de la méthode lireLigne de LectureLog. Cette méthode permet de
    réaliser la liste des 10 documents les plus consultés par ordre décroissant de popularité en prenant en compte 3 choix d'options
    */

    void setOption(std::string option);
    /* Mode d'emploi :
    Permet de mettre à true le booleen correspondant à l'option demandée
    */

    void genererGraph(std::string nomFichierSortie) const;



    
//-------------------------------------------- Constructeurs - destructeur
    
    Analog ( const Analog & unAnalog );
    // Mode d'emploi (constructeur de copie) :
    // Construit un Analog par copie d'un Analog

    Analog ();
    // Mode d'emploi (constructeur) :
    // Construit un Analog en lui allouant la mémoire nécessaire pour ces deux pointeurs

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

#endif // Analog_H

