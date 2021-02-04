/*************************************************************************
                           Affichage  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Affichage> (fichier Affichage.h) ----------------
#if ! defined ( Affichage_H )
#define Affichage_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Affichage>
//
//
//------------------------------------------------------------------------

class Affichage 
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
    //Affichage & operator = ( const Affichage & unAffichage );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Affichage ( const Affichage & unAffichage );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Affichage ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Affichage ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Affichage>

#endif // Affichage_H

