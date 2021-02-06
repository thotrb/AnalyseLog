/*************************************************************************
                           Analog  -  description
                             -------------------
    début                : $06/02/2021$
    copyright            : (C) $2021$ par $De Roover Trubert$
    e-mail               : $ $
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

//------------------------------------------------------ Include personnel
#include "Analog.h"
using namespace std;

//-------------------------------------------- Constructeurs - destructeur
Analog::Analog ( const Analog & unAnalog )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analog>" << endl;
#endif
} //----- Fin de Analog (constructeur de copie)


Analog::Analog ( ) : lectureLog(new LectureLog), graph(new Graph())
{
#ifdef MAP
    cout << "Appel au constructeur de <Analog>" << endl;
#endif
} //----- Fin de Analog


Analog::~Analog ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Analog>" << endl;
#endif
} //----- Fin de ~Analog


void Analog::lireFichier(string & fichier, int * optionHeure) {

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

            else if(optionE && !optionT){

                string delimiter = ".";
                string token;
                size_t pos = 0;
                string extensionFichier, document = l.documentRecherche;

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

            else if(optionT && !optionE) {
                
                int heure = l.temps.heure;
                if(*optionHeure!=23 && (heure==*optionHeure || heure==*optionHeure+1) ){
                    if(classementRecherches.find(l.documentRecherche) == classementRecherches.end()){
                        classementRecherches.insert(make_pair(l.documentRecherche, nbOccurence));
                    }else{
                        nbOccurence = classementRecherches.find(l.documentRecherche)->second;
                        nbOccurence ++;
                        classementRecherches.find(l.documentRecherche)->second += 1;
                    }
                    multimp.insert(make_pair(nbOccurence, l.documentRecherche));
                }
                else if(*optionHeure==23 && (heure==*optionHeure || heure==0) ){
                    if(classementRecherches.find(l.documentRecherche) == classementRecherches.end()){
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

        }//fin du while lisant les lignes du 

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

    }
    else{
        cerr << "Nom de fichier invalide" << endl;
    }
}



void Analog::setOption(string option){

    if(option == "-e"){
        optionE = true;
    }

    else if(option == "-t"){
        optionT = true;
    }
    
    else if(option == "-g"){
        optionG = true;
    }
}

void Analog::genererGraph(string nomFichierSortie) const{

    ofstream stream(nomFichierSortie);
    if(stream){
        graph->genererGraph(stream);
    }
    else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}


int main(int argc, char* argv[]){

    Analog * analog(new Analog());
    string nomFichier, option, nomFichierGraphe;
    int optionHeure = 0;
    int * ptHeure = &optionHeure;

    switch (argc){

        case 2 :  //cas où on n'a que le nom du fichier
            nomFichier = argv[1];
            analog->lireFichier(nomFichier, ptHeure);
            break;
             
        case 3 : //options : -e
            option = argv[1];
            nomFichier = argv[2];

            if(option == "-e"){
                analog->setOption(option);
            }

            else{
                cout<<"L'option n'est pas proposée, cas par défault : "<<endl;
            }
            analog->lireFichier(nomFichier, ptHeure);

        
        break;
            
        case 4 : //options : (-g nomFichier.pdf ou -t heure) + nomFichier
            option = argv[1];
            nomFichier = argv[3];
            
            if(option == "-t"){
                optionHeure = stoi(argv[2]);
                if (optionHeure<24 && optionHeure>0){
                    analog->setOption(option);
                    ptHeure = &optionHeure;
                }
                else{
                    cout<<"L'heure saisie n'est pas correct, l'option -t doit être accompagnée d'un nombre entre 0 et 23 "<<endl;
                    cout<<"Cas sans options par défault : "<<endl;
                }
                
            }
            else if(option == "-g"){
                nomFichierGraphe = argv[2];
                analog->setOption(option);
                analog->genererGraph(nomFichierGraphe);
            }

            else{
                cout<<"L'option n'est pas proposée, nous considérons le cas sans options : "<<endl;
            }
            analog->lireFichier(nomFichier, ptHeure);
        break;
    }
}

