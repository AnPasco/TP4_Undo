#include <iostream>
#include <iomanip>
#include "pile.h"

using namespace std;

int main() {

    int taille_input = sizeof(char) * 30;
    int choix;
    int nbPers;
    char *nom;
    FileAttente *fda, *fdaCp;
    Pile *pile;

    fda = (FileAttente *) malloc(sizeof(FileAttente));
    pile = (Pile *) malloc(sizeof(Pile));


    cout << "FILE D'ATTENTE";
    menu();
    cout << "Choisissez une option :" << endl;
    cin >> choix;

    init(fda);
    initPile(pile);

    while (choix != 5) {

        switch (choix) {
            case 0 :
                nom = (char *) malloc(static_cast<size_t>(taille_input));
                cout << "Veuillez saisir le nom de la personne dans la file d'attente (30 caracteres max): "
                     << endl;
                cin >> setw(taille_input) >> nom;

                ajoutPersonneQueue(fda, nom, pile);
                break;
            case 1 :
                suppEnTete(fda, pile);
                break;
            case 2 :
                persTeteListe(fda);
                break;
            case 3:
                calculLongFda(fda);
                break;
            case 4:
                undo(fda, pile);
                break;
            default:
                cout << "A plus !";
                return 0;
                break;
        }

        menu();
        cout << "Choisissez une option :" << endl;
        cin >> choix;
    }

    free(nom);
    desinit(fda);
}