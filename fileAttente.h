//
// Created by Antoine on 10/10/2018.
//

#ifndef TP4_UNDO_FILEATTENTE_H
#define TP4_UNDO_FILEATTENTE_H

typedef struct Maillon {
    char *nom;
    Maillon *suivant;
} Maillon;

typedef struct FileAttente {
    Maillon *tete;
    Maillon *queue;
} FileAttente;

void menu(int &choix);

void init(FileAttente *fda);

void ajoutPersonneQueue(FileAttente *fda, char *nom);

void persTeteListe(FileAttente *fda);

void suppEnTete(FileAttente *fda);

void calculLongFda(FileAttente *fda);

void desinit(FileAttente *fda);

#endif //TP4_UNDO_FILEATTENTE_H
