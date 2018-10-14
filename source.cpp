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
void ajoutPersonneQueue(FileAttente *fda, char *nom, Pile *pile) {

    Maillon *np;
    Historique *derniereAction;
    np = (Maillon *) malloc(sizeof(Maillon));
    derniereAction = (Historique *) malloc(sizeof(Historique));

    np->nom = nom;
    np->suivant = nullptr;

    initHistorique(derniereAction, np, AJOUT_QUEUE, pile->tete);
    empilerHistorique(pile, derniereAction);

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
void suppEnTete(FileAttente *fda, Pile *pile) {

    if (fda->tete == nullptr) {
        cout << "File d'attente vide !" << endl;
    } else {
        Maillon *temp = (Maillon *) malloc(sizeof(Maillon));
        Historique *derniereAction;
        derniereAction = (Historique *) malloc(sizeof(Historique));

        initHistorique(derniereAction, fda->tete, AJOUT_QUEUE, pile->tete);
        empilerHistorique(pile, derniereAction);

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

//Procedure qui permet d'initiaiser la pile
//Para-Sortie : pile
//Post-Cond : Que la pile soit vide
void initPile(Pile *pile) {
    pile->tete = nullptr;
}

//Procedure qui permet d'initiaiser l'historique
//Para-Entrée : historique, maillon, action, hisorique suivant
//Para-sortie : historique
//Post-Cond : Que l'historique soit initialisé
void initHistorique(Historique *historique, Maillon *derniereModif, Action derniereAction, Historique *suivant) {
    historique->derniereModif = derniereModif;
    historique->derniereAction = derniereAction;
    historique->suivant = suivant;
}

void empilerHistorique(Pile *pile, Historique *derniereAction){
    pile->tete = derniereAction;
}

void depilerHistorique(Pile *pile){
    pile->tete = pile->tete->suivant;
}