#include <iostream>
#include "fileAttente.h"
#include "pile.h"

using namespace std;

///////////////////////////////// File d'attente /////////////////////////////////

//Procedure qui affiche le menu
void menu(int &choix) {
    cout << endl << "0 - Ajouter une personne en queue" << endl;
    cout << "1 - Retirer la personne en tete" << endl;
    cout << "2 - Consulter la personne en tete de file" << endl;
    cout << "3 - Calculer la longueur de la file d'attente" << endl;
    cout << "4 - Quitter" << endl;

    cout << "Choisissez une option :" << endl;
    cin >> choix;
}

//Procedure qui permet d'initiaiser la file d'attente
//Para-Sortie : fda
//Post-Cond : Que la file d'attente soit vide
void init(FileAttente *fda) {
    fda->tete = nullptr;
    fda->queue = nullptr;
}

//procedure qui désinitialise la file d'attente
//Para-Entrée : fda
//Para-Sortie : fda
//La file d'attente est vide
void desinit(FileAttente *fda) {
    free(fda->tete);
    free(fda->queue);
}

//Procedure permettant d'ajouter une personne en queue de file
//Para-entrée : fda, num
//Para-sortie : fda
// Post-Cond : la file d'attente avec une nouvelle personne en queue
void ajoutPersonneQueue(FileAttente *fda, char *nom) {

    Maillon *np;
    np = (Maillon *) malloc(sizeof(Maillon));
    np->nom = nom;
    np->suivant = nullptr;

    if (fda->tete == nullptr) {
        fda->tete = fda->queue = np;
    } else {
        fda->queue->suivant = np;
        fda->queue = np;
    }

    cout << "La persone ";
    int i = 0;
    while (i < 30 && nom[i] != '\0') {
        cout << nom[i];
        i++;
    }
    cout << " a bien ete ajoute a la file d'attente." << endl;

}

//Procedure permettant de consulter la personne en tete de file
//Para-Entrée : fda
void persTeteListe(FileAttente *fda) {
    if (fda->tete == nullptr) {
        cout << "La file est vide !" << endl;
    } else {
        cout << "La personne au debut de la file est " << fda->tete->nom << "." << endl;
    }
}

//Procedure permettant de supprimer la personne en tete
//Para-Entrée : fda
//Post-Cond : la file d'attente avec un élément en moins au début
void suppEnTete(FileAttente *fda) {

    if (fda->tete == nullptr) {
        cout << "File d'attente vide !" << endl;
    } else {
        Maillon *temp = (Maillon *) malloc(sizeof(Maillon));
        temp = fda->tete;
        fda->tete = fda->tete->suivant;
        free(temp);
        cout << "Personne supprimer ! " << endl;
    }
}

//Procedure permettant de calculer la longueur de la file d'attente
//Para-Entrée : fda
//Post-Cond : la longueur de la file d'attente
void calculLongFda(FileAttente *fda) {

    if (fda->tete == nullptr) {
        cout << "La file d'attente est vide !" << endl;
    } else {

        int compt;
        Maillon *cursor;

        cursor = fda->tete;
        compt = 1;

        while (cursor->suivant != nullptr) {
            cursor = cursor->suivant;
            compt++;
        }

        cout << "La file d'attente est de " << compt << " personne(s) !" << endl;
    }

}

//////////////////////////////////////// Pile //////////////////////////////////////////

//Procedure qui duplique une file d'attente
//Para-Entrée : fda, fdaCp
//Post-Cond : La file d'attente a etait copier dans la nouvelle file d'attente
void dupliquer(FileAttente *fda, FileAttente *fdaCp) {
    Maillon *np;
    np = (Maillon *) malloc(sizeof(Maillon));

    np = fda->tete;
    while (np != nullptr) {
        ajoutPersonneQueue(fdaCp, (*np).nom);
        np = np->suivant;
    }
    fdaCp->queue = np;
}

//Procedure qui empile le fda sur la pile
//Para-Entrée : la copie de la file d'attente
//Para-Sortie : la pile avec un nouvel element
void empiler(Pile &pile, FileAttente *fdaCp) {
    Maillon2 *np;
    np = (Maillon2 *) malloc(sizeof(Maillon2));

    np->suivant = pile;
    pile = np;
    pile->fdaEnre = fdaCp;
}

FileAttente *sommet(Pile pile) {

    if (pile->fdaEnre == nullptr) {
        cout << "La pile est vide !" << endl;
    }else{
       return pile->fdaEnre;
    }

}

void depiler(Pile &pile, FileAttente *fdaCp){
    Maillon2 *np;
    np = (Maillon2 *) malloc(sizeof(Maillon2));
}