//
// Created by Antoine on 10/10/2018.
//

#ifndef TP4_UNDO_PILE_H
#define TP4_UNDO_PILE_H

#include "fileAttente.h"

typedef struct Maillon2{
    FileAttente *fdaEnre;
    Maillon2 *suivant;
} Maillon2;

typedef Maillon2 *Pile;

void dupliquer(FileAttente *fda, FileAttente *fdaCp);

void empiler(Pile &pile, FileAttente *fdaCp);

FileAttente *sommet(Pile pile);

#endif //TP4_UNDO_PILE_H

