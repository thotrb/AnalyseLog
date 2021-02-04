/*************************************************************************
                           Analog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <iterator>
#include <vector>
#include <set>


using namespace std;

//------------------------------------------------------ Include personnel
#include "Analog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// Algorithme :
//
//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Analog::Analog ( const Analog & unAnalog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analog>" << endl;
#endif
} //----- Fin de Analog (constructeur de copie)


Analog::Analog ( ) : lectureLog(new LectureLog), graph(new Graph())
// Algorithme :
//
{


#ifdef MAP
    cout << "Appel au constructeur de <Analog>" << endl;
#endif
} //----- Fin de Analog


Analog::~Analog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analog>" << endl;
#endif
} //----- Fin de ~Analog


void Analog::lireFichier(string & fichier) {



    //faire traitement sur args
    fstream file(fichier);
    Log l;
    string line;
    map<string, int> classementRecherches;


    multimap<int, string, greater <int> > multimp;

    int nbOccurence = 0;
    if(file.good()) {
        while(getline(file, line)) {
            
            l = lectureLog->lireLigne(line);
            nbOccurence = 1;
            
            if(!optionE && !optionT) {
                //dans le cas sans contraintes
                
                if(classementRecherches.find(l.documentRecherche) == classementRecherches.end()){
                    classementRecherches.insert(make_pair(l.documentRecherche, nbOccurence));
                }else{
                    nbOccurence = classementRecherches.find(l.documentRecherche)->second;
                    nbOccurence ++;
                    classementRecherches.find(l.documentRecherche)->second += 1;

                }
                
                multimp.insert(make_pair(nbOccurence, l.documentRecherche));

            }

            if(optionE && !optionT){

                string delimiter = ".";
                string token;
                int pos = 0;
                string extensionFichier, document = l.documentRecherche;

                //vector<string> champs = split(l.documentRecherche, delimiter);
                //vector<string>::iterator iterator = champs.begin();
                //iterator++;
                //string extensionFichier = split(doc , delimiter);


                while ((pos = document.find(delimiter)) != string::npos) {
                    token = document.substr(0, pos);
                    document.erase(0, pos + delimiter.length());
                }

                token = document.substr(0, pos);

                extensionFichier = token;


                set<string> extensionsNonAutorisees;
                extensionsNonAutorisees.insert("bmp");
                extensionsNonAutorisees.insert("ai");
                extensionsNonAutorisees.insert("eps");
                extensionsNonAutorisees.insert("jpg");
                extensionsNonAutorisees.insert("jpeg");
                extensionsNonAutorisees.insert("pdf");
                extensionsNonAutorisees.insert("psd");
                extensionsNonAutorisees.insert("gif");
                extensionsNonAutorisees.insert("tiff");
                extensionsNonAutorisees.insert("png");
                extensionsNonAutorisees.insert("svg");
                extensionsNonAutorisees.insert("css");
                extensionsNonAutorisees.insert("jss");

                if(extensionsNonAutorisees.find(extensionFichier) == extensionsNonAutorisees.end()){
                    if(classementRecherches.find(l.documentRecherche) == classementRecherches.end()){
                        nbOccurence = 1;
                        classementRecherches.insert(make_pair(l.documentRecherche, nbOccurence));
                    }else{
                        nbOccurence = classementRecherches.find(l.documentRecherche)->second;
                        nbOccurence ++;
                        classementRecherches.find(l.documentRecherche)->second += 1;
                        
                    }
                    multimp.insert(make_pair(nbOccurence, l.documentRecherche));

                }
            }
                
            graph->AjouterLien(l.documentRecherche, l.referer);



        }

            set<string> top10; 
            multimap<int, string>::iterator iterator = multimp.begin();
            int nbElement = 0;
            while(iterator != multimp.end() && nbElement < 10) {
                
                if(top10.find(iterator->second) == top10.end()) {
                    top10.insert(iterator->second);
                    cout<<iterator->second << " : " << iterator->first<< endl;
                    nbElement ++;
           
                }
                iterator++;

            }

            graph->ConserverLien(top10);

    }else{
        cerr << "Nom de fichier invalide" << endl;
    }


    //graph->AfficherGraph();
    //passer chaque ligne à LectureLog pour récuperer un Log exploitable

    //passer ce Log à graph pour qu'il puisse remplir ses Map

    //traiter pour faire le classement en fonctions des options rentrées par l'utilisateur
        //créer un map<string : nomFichierRecherche, int : nbOccurence>
        //classer par nbOccurence
}

/**

    string split(string & src, string delim) {
        int pos = 0;
        string token = " ";
        while ((pos = src.find(delim)) != string::npos) {
            token = src.substr(0, pos);
            src.erase(0, pos + delim.length());
        }
        return token;


    }
**/


void Analog::setOption(string option){

    if(option == "-e"){
        optionE = true;
        cout << "E" << endl;
    }

    if(option == "-g"){
        optionG = true;
        cout << "G" << endl;

    }

    
}

void Analog::genererGraph(string nomFichierSortie) const{

    ofstream stream(nomFichierSortie);
    if(stream)    
    {
        graph->genererGraph(stream);
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    
}




int main(int argc, char* argv[]){

    Analog * analog(new Analog());
    string nomFichier, option, nomFichierGraphe;


    switch (argc){

        case 2 :    
            //cas où on n'a que le nom du fichier
            nomFichier = argv[1];
            analog->lireFichier(nomFichier);
            break;
            //options : -e 
        case 3 : 
            option = argv[1];
            nomFichier = argv[2];

            if(option == "-e"){
                analog->setOption(option);
            }

            analog->lireFichier(nomFichier);

        
        break;
            //options : (-g nomFichier.pdf ou -t heure) + nomFichier
        case 4 : 
            option = argv[1];
            nomFichierGraphe = argv[2];
            nomFichier = argv[3];

            if(option == "-g"){
                analog->setOption(option);
                analog->lireFichier(nomFichier);
                analog->genererGraph(nomFichierGraphe);
            }
    }
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

