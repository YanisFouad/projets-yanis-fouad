// Version amélioré stratégie puissance 4 Yanis Fouad
// Réalisé par Yanis FOUAD et Margaux BISQUAY 1B2
// BUT Informatique Lannion

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIGNE 6
#define COLONNE 7

typedef int t_grille[LIGNE][COLONNE];

int main(int argc, char **argv);
void chargerGrille(char **argv, t_grille grille);
int choisirColonneOrdi(t_grille grille, int pion);
bool estVainqueur(t_grille grille, int lig, int col);
bool estVainqueur3(t_grille grille, int lig, int col);
bool estPerdant(t_grille grille, int col, int pionAdversaire);
int chercherLigne(t_grille grille, int col);

const int VIDE = 0;
const int JOUEUR = 1;
const int ADVERSAIRE = 2;
const int PION_A = 1;
const int PION_B = 2;

/*
 * VOTRE STRATEGIE
 */
int maStrategie(t_grille grille, int ligne, int colonne)
{
    int i, j, k;
    int cpt = 0;
    int res;
    int pion = PION_A;
    k = 0;

    // On compte le nombre de pions du Joueur adverse presents dans la grille
    for (i = 0; i < LIGNE; i++)
    {
        for (j = 0; j < COLONNE; j++)
        {
            if (grille[i][j] == PION_B)
            {
                cpt = cpt + 1;
            }
        }
    }

    // Si il n'y a pas de pion cela veut dire que l'ordinateur commence
    if (cpt == 0)
    {
        // L'ordinateur place un pion a milieu de la grille
        return res = COLONNE / 2;
    }
    // Pour les deux premiers coups du joueur adverse l'ordinateur va chercher à le bloquer
    else if ((cpt == 1) || (cpt == 2))
    {
        // On cherche l'endroit ou le joueur a joué
        while (k < COLONNE)
        {
            if (grille[LIGNE - 1][k] == PION_B)
            {
                // Si la case à droite du pion est vide on y joue
                if ((grille[LIGNE - 1][k + 1] == VIDE) && (k + 1 <= COLONNE - 1))
                {
                    return res = k + 1;
                }
                // Sinon si la case à gauche du pion est vide on y joue
                else if ((grille[LIGNE - 1][k - 1] == VIDE) && (k - 1 >= 0))
                {
                    return res = k - 1;
                }
            }
            k++;
        }
    }
    else
        return res = choisirColonneOrdi(grille, pion);
}
int choisirColonneOrdi(t_grille grille, int pion)
{
    srand(time(0)); // Initialisation du générateur de nombre avec l'horloge système afin d'avoir des nombres plus aléatoires.
    int lig, col;
    // On vérifie si l'ordinateur peut aligner 4 pions
    for (col = 0; col < COLONNE; col++)
    {
        for (lig = LIGNE - 1; lig >= 0; lig--)
        {
            if (grille[lig][col] == VIDE)
            {
                // On place un pion de l'ordinateur dans la colonne en cours de vérification
                grille[lig][col] = pion;
                // On vérifie si, avec ce pion, l'ordinateur peut aligner 4 pions
                if (estVainqueur(grille, lig, col))
                {
                    // Si oui, on retourne cette colonne
                    grille[lig][col] = VIDE;
                    return col;
                }
                else
                {
                    // Si non, on replace la case vide
                    grille[lig][col] = VIDE;
                }
            }
        }
    }

    // Si l'ordinateur ne peut pas alligner 4 pions, on vérifie si le joueur peut aligner 4 pions
    for (col = 0; col < COLONNE; col++)
    {
        for (lig = LIGNE - 1; lig >= 0; lig--)
        {
            if (grille[lig][col] == VIDE)
            {
                // On place un pion du joueur dans la colonne en cours de vérification
                grille[lig][col] = PION_B;
                // On vérifie si, avec ce pion, le joueur peut aligner 4 pions
                if (estVainqueur(grille, lig, col))
                {
                    // Si oui, on retourne cette colonne pour bloquer le joueur
                    grille[lig][col] = VIDE;
                    return col;
                }
                else
                {
                    // Si non, on replace la case vide
                    grille[lig][col] = VIDE;
                }
            }
        }
    }

    // Si le joueur ne peut pas alligner 4 pions, on vérifie si l'ordinateur peut alligner 3 pions
    for (col = 0; col < COLONNE; col++)
    {
        for (lig = LIGNE - 1; lig >= 0; lig--)
        {
            if (grille[lig][col] == VIDE)
            {
                // On place un pion de l'ordinateur dans la colonne en cours de vérification
                grille[lig][col] = pion;
                // On vérifie si, avec ce pion, l'ordinateur peut aligner 3 pions
                if ((estVainqueur3(grille, lig, col)) && (!estPerdant(grille, col, PION_B)))
                {
                    // Si oui, on retourne cette colonne
                    grille[lig][col] = VIDE;
                    return col;
                }
                else
                {
                    // Si non, on replace la case vide
                    grille[lig][col] = VIDE;
                }
            }
        }
    }
    // Si aucun des cas au dessus et possible, l'ordinateur joue au hasard
    do
    {
        col = rand() % COLONNE; // Permet de choisir une colonne avec un nombre réelement choisit aléatoirement
    } while ((grille[0][col] != VIDE) && (estPerdant(grille, col, PION_B)));
    return col;
}
// La fonction principale reçoit la grille du tour et retourne le coup choisi
// Vous n'avez pas à modifier cette fonction
int main(int argc, char **argv)
{
    t_grille grille;
    int ligne, colonne;

    chargerGrille(argv, grille);

    return maStrategie(grille, ligne, colonne);
}

// Charge la grille du tour actuel
// Vous n'avez pas à modifier cette fonction
void chargerGrille(char **argv, t_grille grille)
{
    for (int i = 0; i < LIGNE; i++)
        for (int j = 0; j < COLONNE; j++)
            grille[i][j] = atoi(argv[i * COLONNE + j + 1]);
}

bool estVainqueur(t_grille grille, int lig, int col)
{
    // consiste Ã  regarder si une ligne de 4 pions s'est formÃ©e autour du pion qui vient de tomber en (lig, col)
    char lePion = grille[lig][col];
    int cpt, i, j;

    // regarder la verticale, en comptant le nombre de pions au Sud (inutile de regarder au Nord du pion qui vient de tomber)
    i = lig;
    cpt = 0;
    while (i < LIGNE && grille[i][col] == lePion)
    {
        cpt++;
        i++;
    }
    if (cpt >= 4)
    {
        return true;
    }
    // regarder l'horizontale, en comptant le nombre de pions Ã  l'Est et Ã  l'Ouest
    j = col;
    cpt = 0;
    // on regarde Ã  l'est
    while (j >= 0 && grille[lig][j] == lePion)
    {
        cpt++;
        j--;
    }
    j = col + 1;
    // on regarde Ã  l'ouest
    while (j < COLONNE && grille[lig][j] == lePion)
    {
        cpt++;
        j++;
    }
    if (cpt >= 4)
    {
        return true;
    }
    // regarder la diagonale descendante, en comptant le nombre de pions au Nord Ouest et au Sud Est
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Ouest
    while (j >= 0 && i >= 0 && grille[i][j] == lePion)
    {
        cpt++;
        i--;
        j--;
    }
    i = lig + 1;
    j = col + 1;
    // on regarde au Sud Est
    while (i < LIGNE && j < COLONNE && grille[i][j] == lePion)
    {
        cpt++;
        i++;
        j++;
    }
    if (cpt >= 4)
    {
        return true;
    }
    // regarder la diagonale descendante, en comptant le nombre de pions au Nord Est et au Sud Ouest
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Est
    while (j < COLONNE && i >= 0 && grille[i][j] == lePion)
    {
        cpt++;
        i--;
        j++;
    }
    i = lig + 1;
    j = col - 1;
    // on regarde au Sud Ouest
    while (i < LIGNE && j >= 0 && grille[i][j] == lePion)
    {
        cpt++;
        i++;
        j--;
    }
    if (cpt >= 4)
    {
        return true;
    }
    return false;
}

bool estVainqueur3(t_grille grille, int lig, int col)
{
    // consiste Ã  regarder si une ligne de 4 pions s'est formÃ©e autour du pion qui vient de tomber en (lig, col)
    int lePion = grille[lig][col];
    int cpt, i, j;

    // regarder la verticale, en comptant le nombre de pions au Sud (inutile de regarder au Nord du pion qui vient de tomber)
    i = lig;
    cpt = 0;
    while (i < LIGNE && grille[i][col] == lePion)
    {
        cpt++;
        i++;
    }
    if (cpt >= 3)
    {
        return true;
    }
    // regarder l'horizontale, en comptant le nombre de pions Ã  l'Est et Ã  l'Ouest
    j = col;
    cpt = 0;
    // on regarde Ã  l'est
    while (j >= 0 && grille[lig][j] == lePion)
    {
        cpt++;
        j--;
    }
    j = col + 1;
    // on regarde Ã  l'ouest
    while (j < COLONNE && grille[lig][j] == lePion)
    {
        cpt++;
        j++;
    }
    if (cpt >= 3)
    {
        return true;
    }
    // regarder la diagonale descendante, en comptant le nombre de pions au Nord Ouest et au Sud Est
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Ouest
    while (j >= 0 && i >= 0 && grille[i][j] == lePion)
    {
        cpt++;
        i--;
        j--;
    }
    i = lig + 1;
    j = col + 1;
    // on regarde au Sud Est
    while (i < LIGNE && j < COLONNE && grille[i][j] == lePion)
    {
        cpt++;
        i++;
        j++;
    }
    if (cpt >= 3)
    {
        return true;
    }
    // regarder la diagonale descendante, en comptant le nombre de pions au Nord Est et au Sud Ouest
    i = lig;
    j = col;
    cpt = 0;
    // on regarde au Nord Est
    while (j < COLONNE && i >= 0 && grille[i][j] == lePion)
    {
        cpt++;
        i--;
        j++;
    }
    i = lig + 1;
    j = col - 1;
    // on regarde au Sud Ouest
    while (i < LIGNE && j >= 0 && grille[i][j] == lePion)
    {
        cpt++;
        i++;
        j--;
    }
    if (cpt >= 3)
    {
        return true;
    }
    return false;
}

bool estPerdant(t_grille grille, int col, int pionAdversaire)
{
    int lig = chercherLigne(grille, col) - 1;
    // On place un pion de l'adversaire au dessus du pion pion que l'ordinateur veut jouer et vérifie si le joueur peut gagner grâce à cela
    if (lig >= 0)
    {
        grille[lig][col] = pionAdversaire;
        if (estVainqueur(grille, lig, col))
        {
            // Si l'ordinateur joue dans cette colonne cela permet de faire gagner l'adversaire
            grille[lig][col] = pionAdversaire;
            return true;
        }
    }
    else
        // L'ordinateur peut jouer sans faire gagner l'adversaire
        return false;
}
int chercherLigne(t_grille grille, int col)
{
    int ligne = -1;

    while (ligne < LIGNE - 1 && grille[ligne + 1][col] == VIDE)
    {
        ligne++;
    }
    return ligne;
}