#include <stdio.h>
#include <stdlib.h>

#define LIGNE 6
#define COLONNE 7

typedef int t_grille[LIGNE][COLONNE];

int main(int argc, char** argv);
void chargerGrille(char** argv, t_grille grille);
int chercherLigne(t_grille grille, int col);

const int VIDE = 0;
const int JOUEUR = 1;
const int ADVERSAIRE = 2;

/*
* VOTRE STRATEGIE
*/
int maStrategie(t_grille grille)
{
    int i, id_col, val_col;
    id_col=0;
    for ( i = 0; i < COLONNE; i++)
    {
        val_col=chercherLigne(grille,i);
        if (val_col>(chercherLigne(grille,id_col)))
        {
            id_col=i;
        }
        
    }
    return id_col;
}

// La fonction principale reçoit la grille du tour et retourne le coup choisi
// Vous n'avez pas à modifier cette fonction
int main(int argc, char** argv) 
{
    t_grille grille;

    chargerGrille(argv, grille);

    return maStrategie(grille);
}

// Charge la grille du tour actuel
// Vous n'avez pas à modifier cette fonction
void chargerGrille(char** argv, t_grille grille) 
{
    for(int i = 0; i < LIGNE; i++)
        for(int j = 0; j < COLONNE; j++)
            grille[i][j] = atoi(argv[i * COLONNE + j + 1]);
}

int chercherLigne(t_grille grille, int col){
    int ligne = -1;

    while (ligne<LIGNE-1 && grille[ligne+1][col]==VIDE){
        ligne++;
    }
    return ligne;
}