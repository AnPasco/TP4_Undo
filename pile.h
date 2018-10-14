//
// Created by Antoine on 10/10/2018.
//

#ifndef TP4_UNDO_PILE_H
#define TP4_UNDO_PILE_H

//////////////////////////////////////// Structure /////////////////////////////////

enum Action {
    SUPPRESSION_TETE, AJOUT_QUEUE
};

typedef struct Maillon {
    char *nom;
    Maillon *suivant;
    Maillon *precedent;
} Maillon;

typedef struct Historique {
    Maillon *derniereModif;
    Action derniereAction;
    Historique *suivant;
} Historique;

typedef struct Plie {
    Historique *tete;
} Pile;

typedef struct FileAttente {
    Maillon *tete;
    Maillon *queue;
} FileAttente;

//////////////////////////////////////// File d'attente /////////////////////////////////

void menu();

void init(FileAttente *fda);

void ajoutPersonneQueue(FileAttente *fda, char *nom, Pile *pile);

void persTeteListe(FileAttente *fda);

void suppEnTete(FileAttente *fda, Pile *pile);

void calculLongFda(FileAttente *fda);

void desinit(FileAttente *fda);

void undo(FileAttente *fda, Pile *pile);

/////////////////////////////// PILE /////////////////////////////////////

void initPile(Pile *pile);

void initHistorique(Historique *historique, Maillon *derniereModif, Action derniereAction, Historique *suivant);

void empilerHistorique(Pile *pile, Historique *derniereAction);

void depilerHistorique(Pile *pile);

void desinitPile(Pile *pile);

#endif //TP4_UNDO_PILE_H

