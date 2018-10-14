//
// Created by Antoine on 10/10/2018.
//

#ifndef TP4_UNDO_PILE_H
#define TP4_UNDO_PILE_H

#include "fileAttente.h"

enum Action {
    SUPPRESSION_TETE, AJOUT_QUEUE
};

typedef struct Historique {
    Maillon *derniereModif;
    Action derniereAction;
    Historique *suivant;
}Historique;

typedef struct Plie {
    Historique *tete;
}Pile;

void initPile(Pile *pile);

#endif //TP4_UNDO_PILE_H

