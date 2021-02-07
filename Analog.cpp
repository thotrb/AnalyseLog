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
delete graph;
delete lectureLog;
#ifdef MAP
    cout << "Appel au destructeur de <Analog>" << endl;
#endif
} //----- Fin de ~Analog


int Analog::lireFichier(string & fichier, int * optionHeure = nullptr) {

    fstream file(fichier);
    Log l;
    string line;
    map<string, int> classementRecherches;

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

    bool insertion = true;


    multimap<int, string, greater <int> > multimp;

    int nbOccurence = 0;
    if(file.good()) {
        while(getline(file, line)) {
            
            insertion = true;
            l = lectureLog->lireLigne(line);
            nbOccurence = 1;
            
            /**
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
                **/
                if(optionE){
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

                    if(extensionsNonAutorisees.find(extensionFichier) != extensionsNonAutorisees.end()){

                        insertion = false;

                    }
                }

                if(optionT){
                    int heure = l.temps.heure;
                    if(heure!=*optionHeure ){
                        insertion = false;
                    }
                    
                }


                if(insertion){
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
                graph->AjouterLien(l.documentRecherche, l.referer);

        }
/**
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
**/

        //Conserve uniquement les 10 premiers éléments recherchés
        set<string> top10; 
        multimap<int, string>::iterator iterator = multimp.begin();
        int nbElement = 0;
        while(iterator != multimp.end() && nbElement < 10) {
                
            if(top10.find(iterator->second) == top10.end()) {
                top10.insert(iterator->second);
                cout << iterator->second << " (" << iterator->first<< " hits)" << endl;
                nbElement ++;
            }
            iterator++;
        }

        if(optionG){
            graph->ConserverLien(top10);
        }


        return 0;

    }else{
        cerr << "Invalid filename : " << fichier << endl;
        return 1;
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

int Analog::genererGraph(string nomFichierSortie) const{
    

        ofstream stream(nomFichierSortie);
        if(stream){
            graph->genererGraph(stream);
            return 0;
        }
        else{
            cerr << "ERROR: Opening stream failed " << nomFichierSortie << endl;
            return 1;
        }
    
    
}

int Analog::verifierExtensionFichierDot(string nomFichier) const {
    string delimiter = ".";
    string token;
    size_t pos = 0;
    string extensionFichier;
    while ((pos = nomFichier.find(delimiter)) != string::npos) {
        token = nomFichier.substr(0, pos);
        nomFichier.erase(0, pos + delimiter.length());
    }
    token = nomFichier.substr(0, pos);
    extensionFichier = token;
    if(extensionFichier != "dot"){
        cerr << "ERROR: Wrong extension .dot expected" << endl;
        return 1;
    }else{
        return 0;
    }
}


int main(int argc, char* argv[]){

    Analog * analog(new Analog());
    string nomFichier, option, option2, option3, nomFichierGraphe;
    int optionHeure = 0;
    int * ptHeure = &optionHeure;

    switch (argc){

        case 2 :  //cas où on n'a que le nom du fichier
            nomFichier = argv[1];
            if(analog->lireFichier(nomFichier, ptHeure) != 0){
                return 1;
            }
            break;
             
        case 3 : //options : -e
            option = argv[1];
            nomFichier = argv[2];

            if(option == "-e"){
                analog->setOption(option);
            }else{
                cerr<<"Illegal option : " << option <<endl;
                return 1;
            }
            if(analog->lireFichier(nomFichier, ptHeure) != 0){
                return 1;
            }
    
        break;
            
        case 4 : //options : (-g nomFichier.dot ou -t heure) + nomFichier
            option = argv[1];
            nomFichier = argv[3];
            
            if(option == "-t"){

                analog->setOption(option);
                optionHeure = stoi(argv[2]);

                if (optionHeure<24 && optionHeure>0){
                    ptHeure = &optionHeure;
                }
                else{
                    cerr<<"Illegal value : " << optionHeure <<endl;
                    return 1;
                }
                if(analog->lireFichier(nomFichier, ptHeure) != 0){
                    return 1;
                }
                
            }
            else if(option == "-g"){

                nomFichierGraphe = argv[2];
                analog->setOption(option);
                if(analog->verifierExtensionFichierDot(nomFichierGraphe) != 0){
                    return 1;
                }else{
                    if(analog->lireFichier(nomFichier, ptHeure) != 0)  
                        return 1;
                }
                if(analog->genererGraph(nomFichierGraphe) != 0) {
                    return 1;
                }
            }
            else{
                cerr<<"Illegal option : " << option <<endl;
                return 1;
            }
            
            break;
        
        case 5 : 
            //options : -e + (-g nomFichier.dot ou -t heure) + nomFichier
            //options : (-g nomFichier.dot ou -t heure) + -e + nomFichier
            option = argv[1];
            nomFichier = argv[4];

            if(option == "-e"){
                analog->setOption(option);

                option2 = argv[2];
                if(option2 == "-g"){

                    analog->setOption(option2);

                    nomFichierGraphe = argv[3];
                    if(analog->verifierExtensionFichierDot(nomFichierGraphe) != 0){
                        return 1;
                    }else{
                        if(analog->lireFichier(nomFichier, ptHeure) != 0){ 
                            delete analog;
                            return 1;
                        } 
                    }
                    if(analog->genererGraph(nomFichierGraphe) != 0) {
                        delete analog;
                        return 1;
                    }

                }else if (option2 == "-t"){
                    
                    analog->setOption(option2);
                    optionHeure = stoi(argv[3]);

                    if (optionHeure<24 && optionHeure>0){
                        ptHeure = &optionHeure;
                    }
                    else{
                        cerr<<"Illegal value : " << optionHeure <<endl;
                        delete analog;
                        return 1;
                    }
                   
                    if(analog->lireFichier(nomFichier, ptHeure) != 0){
                        delete analog;
                        return 1;
                    }
                }else{
                    delete analog;
                    cerr<<"Illegal option : " << option2 <<endl;
                    return 1;
                }

            }else if (option == "-g"){

                nomFichierGraphe = argv[2];
                analog->setOption(option);
                option2 = argv[3];

                if(option2 == "-e"){

                    analog->setOption(option2);
                    if(analog->verifierExtensionFichierDot(nomFichierGraphe) != 0){
                        return 1;
                    }else{
                        if(analog->lireFichier(nomFichier, ptHeure) != 0){ 
                            delete analog;
                            return 1;
                        } 
                    }
                    if(analog->genererGraph(nomFichierGraphe) != 0) {
                        delete analog;
                        return 1;
                    }

                }else{
                    cerr<<"Illegal option : " << option2 <<endl;
                    delete analog;
                    return 1;
                }



            }else if (option == "-t"){
                
                analog->setOption(option);
                optionHeure = stoi(argv[2]);
                if (optionHeure<24 && optionHeure>0){
                    ptHeure = &optionHeure;
                    option2 = argv[3];
                    
                    if(option2 == "-e"){
                        analog->setOption(option2);
                        if(analog->lireFichier(nomFichier, ptHeure) != 0){
                            delete analog;
                            return 1;
                        }
                        if(analog->genererGraph(nomFichierGraphe) != 0) {
                            delete analog;
                            return 1;
                        }

                    }else{
                        cerr<<"Illegal option : " << option2 <<endl;
                        return 1;
                    }

                }
                else{
                    cerr<<"Illegal value : " << optionHeure <<endl;
                    return 1;
                }
        
            }            
            break;




        case 6 : 
            //options : (-t heure) + (-g nomFichier.dot) + nomFichier
            //options : (-g nomFichier.dot) + (-t heure) + nomFichier  

            option = argv[1];
            nomFichier = argv[5];
            if(option == "-g"){
                nomFichierGraphe = argv[2];
                option2 = argv[3];
                analog->setOption(option);
                if(option2 == "-t"){
                    analog->setOption(option2);
                    optionHeure = stoi(argv[4]);
                    if (optionHeure<24 && optionHeure>0){
                        ptHeure = &optionHeure;
                        option3 = argv[5];
                        if(option3 == "-e"){
                            analog->setOption(option3);
                            if(analog->verifierExtensionFichierDot(nomFichierGraphe) != 0){
                                delete analog;
                                return 1;
                            }else{
                                if(analog->lireFichier(nomFichier, ptHeure) != 0){ 
                                    delete analog;
                                    return 1;
                                } 
                            }
                        }else{
                            cerr<<"Illegal option : " << option3 <<endl;
                            delete analog;
                            return 1;
                        }
                        
                    }else{
                        cerr<<"Illegal value : " << optionHeure <<endl;
                        delete analog;
                        return 1;
                    }
                    
                }else{
                    cerr<<"Illegal option : " << option2 <<endl;
                    delete analog;
                    return 1;
                }

            }else if (option == "-t"){
                    analog->setOption(option);
                    optionHeure = stoi(argv[2]);
                    if (optionHeure<24 && optionHeure>0){
                        ptHeure = &optionHeure;
                        
                        option2 = argv[3];
                        if(option2 == "-g"){ 
                            analog->setOption(option2);
                            nomFichierGraphe = argv[4];
                            option3 = argv[5];
                            if(option3 == "-e"){
                                analog->setOption(option3);
                                if(analog->verifierExtensionFichierDot(nomFichierGraphe) != 0){
                                    delete analog;
                                    return 1;
                                }else{
                                    if(analog->lireFichier(nomFichier, ptHeure) != 0){ 
                                        delete analog;
                                        return 1;
                                    } 
                                }
                            }else{
                                cerr<<"Illegal option : " << option3 <<endl;
                                delete analog;
                                return 1;
                            }
                            
                        }else{
                            cerr<<"Illegal option : " << option2 <<endl;
                            delete analog;
                            return 1;   
                        }
                    }else{
                        cerr<<"Illegal value : " << optionHeure <<endl;
                        delete analog;
                        return 1;
                    }
                    
            }else{
                cerr<<"Illegal option : " << option2 <<endl;
                delete analog;
                return 1;
            } 
            break;
        
        case 7 : 
            //options : (-g nomFichier.dot) + (-t heure) + -e + nomFichier
            //options : (-t heure) + (-g nomFichier.dot) + -e + nomFichier

            option = argv[1];
            nomFichier = argv[6];

            if(option == "-g"){
                nomFichierGraphe = argv[2];
                option2 = argv[3];
                analog->setOption(option);
                if(option2 == "-t"){
                    analog->setOption(option2);
                    optionHeure = stoi(argv[4]);
                    if (optionHeure<24 && optionHeure>0){
                        ptHeure = &optionHeure;
                        if(analog->verifierExtensionFichierDot(nomFichierGraphe) != 0){
                                delete analog;
                                return 1;
                            }else{
                                if(analog->lireFichier(nomFichier, ptHeure) != 0){ 
                                    delete analog;
                                    return 1;
                                } 
                            }
                    }else{
                        cerr<<"Illegal value : " << optionHeure <<endl;
                        delete analog;
                        return 1;
                    }
                    
                }else{
                    cerr<<"Illegal option : " << option2 <<endl;
                    delete analog;
                    return 1;
                }

            }else if (option == "-t"){
                    analog->setOption(option);
                    optionHeure = stoi(argv[2]);
                    if (optionHeure<24 && optionHeure>0){
                        ptHeure = &optionHeure;
                        
                        option2 = argv[3];
                        if(option2 == "-g"){ 
                            analog->setOption(option2);
                            nomFichierGraphe = argv[4];
                            if(analog->verifierExtensionFichierDot(nomFichierGraphe) != 0){
                                delete analog;
                                return 1;
                            }else{
                                if(analog->lireFichier(nomFichier, ptHeure) != 0){ 
                                    delete analog;
                                    return 1;
                                } 
                            }
                        }else{
                            cerr<<"Illegal option : " << option2 <<endl;
                            delete analog;
                            return 1;   
                        }
                    }else{
                        cerr<<"Illegal value : " << optionHeure <<endl;
                        delete analog;
                        return 1;
                    }
            }else{
                cerr<<"Illegal option : " << option2 <<endl;
                delete analog;
                return 1;
            } 
            break;

        default :
            cerr<<"Illegal number of option : " << option <<endl;
            delete analog;
            return 1; 

    }

    delete analog;
    return 0;


}

