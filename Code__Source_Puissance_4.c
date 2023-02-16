/**
 * @file Code_Source_Yanis_Fouad_1B2.c
 * @author Yanis Fouad 1B2
 * @brief Programme Puissance 4 en langage C
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define L 6
#define C 7

typedef char tab[L][C];

const char PION_A ='X';
const char PION_B ='O';
const int LMAX = 6;
const int CMAX = 7;
const int COLONNE_DEBUT = 3;
const char VIDE = '*';
const char NON_GAGNANT = 'N';


void regles();
void continuer();
void fonctionnement();
void initGrille(tab grille);
void afficher(tab grille, char pion,int colonne);
void jouer(tab grille, char pion, int *ligne, int *colonne);
void finDePartie (char vainqueur);

int choisirColonne(tab grille, char pion, int colonne);
int trouverLigne(tab grille, int colonne);
bool estVainqueur (tab grille,int ligne,int colonne, char pion);
bool grillePleine (tab grille);

int main(){
    system("clear");
    int i;
    tab grille;
    char joueur1[30];
    char joueur2[30];
    char pion;
    char vainqueur= NON_GAGNANT;
    int colonne = COLONNE_DEBUT;
    int ligne = 0;

    regles();
    continuer();
    printf("Voici la grille de puissance 4 sur laquelle vous allez jouer :\n\n");
    initGrille(grille);
    fonctionnement();
    continuer();
    printf("Joueur 1, veuillez entrer votre prénom : ");
    scanf("%s", joueur1);
    printf("\n%s, vous jouerez avec les pions en forme de %c\n\n",joueur1,PION_A);
    
    printf("Joueur 2, veuillez entrer votre prénom : ");
    scanf("%s", joueur2);
    printf("\n%s, vous jouerez avec les pions en forme de %c\n",joueur2,PION_B);
    continuer();

    while ((vainqueur== NON_GAGNANT) && (grillePleine(grille)==false))
    {
        pion = PION_A;
        printf("%s, à toi de jouer !\nVous jouez avec les pions en forme de %c\n\n",joueur1,pion);
        afficher(grille,pion,colonne);
        jouer(grille,pion,&ligne,&colonne);
        grille[ligne][colonne]= pion;
        system("clear");
        if (estVainqueur(grille,ligne,colonne,pion)==true)
        {
            vainqueur = PION_A;
        }
        else if(grillePleine(grille)==false)
        {
            pion = PION_B;
            printf("%s, à toi de jouer !\nVous jouez avec les pions en forme de %c\n\n",joueur2,pion);
            afficher(grille,pion,colonne);
            jouer(grille,pion,&ligne,&colonne);
            grille[ligne][colonne]= pion;
            system("clear");
            if(estVainqueur(grille,ligne,colonne,pion)==true){
               vainqueur = PION_B;
            }
        }
    }
    system("clear");
    afficher(grille,pion,colonne);
    if(vainqueur==PION_A){
        printf("\n\nBravo %s, vous êtes un vrai champion du puissance 4, vous avez gagné la partie !\n",joueur1);
    }
    else if(vainqueur==PION_B){
        printf("\n\nBravo %s, vous êtes un vrai champion du puissance 4, vous avez gagné la partie !\n",joueur2);
    }
    else
        printf("\n\nMalheureusement aucun joueur n’a su prendre le dessus sur l’autre, la partie se finie avec une égalité\n");
    
    return EXIT_SUCCESS;
}
/**
 * @brief Affiche les règles du puissance 4.
 * 
 */
void regles()
{
    printf("Les règles sont simples :\n\n");
    printf("Le but du jeu est d'aligner 4 pions sur une grille comptant 6 lignes et 7 colonnes.\nDeux joueurs jouent alternativement en laissant tomber un de ses jetons du haut d’une\ndes colonnes. Ce jeton remplit donc la plus basse case inoccupée de la colonne.\nLe vainqueur est le premier à obtenir un alignement de 4 jetons (horizontalement,\n verticalement ou en diagonale) de sa forme. Si, alors que toutes les cases de la grille de\njeu sont remplies, aucun des deux joueurs n'a réalisé un tel alignement, la partie est déclarée nulle.\n");
}
/**
 * @brief Oblige l'utilisateur à appuier sur 1 pour pouvoir continuer le programme.
 * 
 */
void continuer(){
    int n;
    printf("\n\n\nVeuiller appuier sur 1 pour continuer...\n\n");
    scanf("%d",&n);
    if(n != 1)
    {
        while(n != 1)
        {
            printf("\n\n\nVeuiller appuier sur 1 pour continuer...\n\n");
            scanf("%d",&n);
        }
    }
    system("clear");

}
/**
 * @brief Affiche comment uriliser le programme.
 * 
 */
void fonctionnement(){
    printf("Explication du fonctionnement :\n\n");
    printf("Chacun votre tour, vous devrez sélectionner la colonne en vous servant de la touche \"q\" pour aller à gauche, la touche \"d\" \npour aller à droite et la touche \"espace\" pour sélectionner la colonne où vous voulez jouer.");
}

/**
 * @brief Assigne la valeur de la constante VIDE à toutes les valeurs de grille et les affiches tout en respectant une mise en forme
 * 
 * @param grille Le tableau à remplir avec la constante VIDE.
 */
void initGrille(tab grille){
    int lig;
    int col;
    int i;
    
    for(i=1; i<8;i++){
            printf("\t%d\t",i);
        }
    printf("\n");
    
    for(i=1; i<114;i++)
        {
            printf("-");
        }
    printf("\n"); 
    i=0;
    printf("|");
    
    for(lig=0; lig<LMAX; lig++){
        for(col=0; col<CMAX; col++){
            grille[lig][col]= VIDE;
        }
    }
    
    for(lig=0; lig<LMAX; lig++){
        for(col=0; col<CMAX; col++){
            printf ("\t%c\t",grille[lig][col]);
            i=i+1;
            if(i==7){
                printf("|");
                printf("\n");
            }
            if(i==14){
                printf("|");
               printf("\n");
           }
            if(i==21){
                printf("|");
               printf("\n");
           }
            if(i==28){
                printf("|");
               printf("\n");
           }
            if(i==35){
                printf("|");
               printf("\n");
           }
           printf("|");
        }
    }
    printf("\n");
    for(i=1; i<114;i++)
        {
            printf("-");
        }
    printf("\n\n");
}

/**
 * @brief Affiche grille ainsi que le pion du joueur qui doit jouer au-dessus de la colonne où le dernier coup a été joué
 * 
 * @param grille Le tableau qui doit être affiché.
 * @param pion Charactère correspondant au pion du joueur qui doit jouer.
 * @param colonne Numéro de la colonne où le dernier coup a été joué.
 */
void afficher(tab grille, char pion,int colonne){
    int lig;
    int col;
    int i;
    
    for(i=1; i<8;i++){
            printf("\t%d\t",i);
        }
    printf("\n\n\t");
    
    for(i=0; i<CMAX ; i++){
        if(colonne == i){
            printf("%c",pion);
        }
        printf("\t\t");
    }
    printf("\n");

    for(i=1; i<114;i++)
        {
            printf("-");
        }
    printf("\n"); 
    i=0;
    printf("|");
    
    for(lig=0; lig<LMAX; lig++){
        for(col=0; col<CMAX; col++){
            printf ("\t%c\t",grille[lig][col]);
            i=i+1;
            if(i==7){
                printf("|");
                printf("\n");
            }
            if(i==14){
                printf("|");
               printf("\n");
           }
            if(i==21){
                printf("|");
               printf("\n");
           }
            if(i==28){
                printf("|");
               printf("\n");
           }
            if(i==35){
                printf("|");
               printf("\n");
           }
           printf("|");
        }
    }
    printf("\n");
    for(i=1; i<114;i++)
        {
            printf("-");
        }
    printf("\n\n");
}

/**
 * @brief Permet au joueur de sélectioner où il veut placer son pion en appelant les fonctions choisirColonne et trouverLigne.
 * 
 * @param grille Tableau où doit être placé le pion.
 * @param pion Charactère correspondant au pion du joueur qui doit jouer.
 * @param ligne Retourne en sortie la valeur de la ligne où a été placé le pion.
 * @param colonne Retourne en sortie la valeur de la colonne où a été placé le pion. On sait donc là où a été joué le dernier coup.
 */
void jouer(tab grille, char pion, int *ligne, int *colonne){
    int col = *colonne;
    *colonne = choisirColonne(grille,pion,col);
    *ligne = trouverLigne(grille,*colonne);    
}

/**
 * @brief Permet au joueur de déplacer son pion au dessus du tableau en allant de colonne en colonne grâce à "q" pour aller à gauche et "d" pour aller à droite jusqu'à ce qu'il appuie sur "espace" pour sélectionner la colonne. Le terminal est réinitialisé à chaque saisie pour réafficher grille avec le pion placé au bon endroit.
 * 
 * @param grille Tableau qui est affiché.
 * @param pion Charactère correspondant au pion du joueur qui doit jouer.
 * @param colonne Numéro de la colonne au-dessus de laquelle doit être affiché le pion.
 * @return Entier représentant le numéro de la colonne choisie par le joueur.
 */
int choisirColonne(tab grille, char pion, int colonne){
    char choix;
    int col = colonne;

    while(choix != ' '){
        scanf("%c",&choix);
        
        if(choix == 'q'){
            system("clear");
            col = col - 1;
            if(col < 0){
                col = 0;
            }
            afficher(grille,pion,col);
        }
        if(choix == 'd'){
            system("clear");
            col = col + 1;
            if(col > 6){
                col = 6;
            }
            afficher(grille,pion,col);
        }
    }
    return col;
    
}

/**
 * @brief Vérifie si le joueur peut placer un pion dans la colonne sélectionner. Dans le cas où cela est possible, le pion est placé dans la ligne la plus basse possible de la colonne? dans le cas contraire le pion n'est pas placé.
 * 
 * @param grille Tableau à vérifier.
 * @param colonne Numéro de la colonne à vérifier.
 * @return Entier représentant le numéro de la ligne où le pion peut être placé. Retourne -1 dans le cas où le pion ne peut pas être placé car la colonne est pleine. 
 */
int trouverLigne(tab grille, int colonne){
    int i,indice;
    if (grille[0][colonne] != VIDE){
        indice = -1;
    }
    for(i=0; i < LMAX; i++){
        if(grille[i][colonne] == '*' ){
            indice = i;
        }
    }
    return indice;
}

/**
 * @brief Vérifie si la grille est pleine ou non en vérifiant si la première ligne est remplie ou non.
 * 
 * @param grille 
 * @return true Dans le cas où la première ligne est pleine.
 * @return false Dans le cas où une des valeurs de la prmière ligne est égale à la constante VIDE.
 */
bool grillePleine (tab grille){
    int j;
    bool plein;
    plein = true;

        for(j = 0; j <CMAX; j++){
            if(grille[0][j] == VIDE){
                plein= false;
        }
    }
    return plein;
}

/**
 * @brief Compte le nombre d'occurence successive du pion du joueur qui vient de jouer, verticalement, horizontalement et diagonalement.
 * 
 * @param grille tableau à vérifier
 * @param ligne Numéro de la ligne où le joueur vient de jouer.
 * @param colonne Numéro de la colonne où le joueur vient de jouer. 
 * @param pion Charactère correspondant au pion du joueur qui vient jouer.
 * @return true Dans le cas où le nombre d'occurence est supérieur à 3.
 * @return false Dans le cas où le nombre d'occurence est inférieur à 3.
 */
bool estVainqueur(tab grille,int ligne,int colonne,char pion){
    bool res=false;
    int i=1;
            /**
             * @brief Compte le nombre d'occurence successive du pion du joueur sur 3 valeurs en partant de la valeur de ligne-1 et colonne avec un pas de -1 (Pas de besoin de vérifier les coordonées de départ). Test Horizontale en allant vers la gauche.
             * 
             */
            if (grille[ligne-1][colonne] == pion){
                i=i+1;
                if(grille[ligne-2][colonne] == pion){
                    i=i+1;
                    if (grille[ligne-3][colonne] == pion){
                        i=i+1;
                    }
                }
            }
            /**
             * @brief Compte le nombre d'occurence successive du pion du joueur sur 3 valeurs en partant de la valeur de ligne+1 et colonne avec un pas de 1. Test Horizontale en allant vers la droite.
             * 
             */
            if (grille[ligne+1][colonne] == pion){
                i=i+1;
                if(grille[ligne+2][colonne] == pion){
                    i=i+1;
                    if (grille[ligne+3][colonne] == pion){
                        i=i+1;
                    }
                }
            }
            
            if(i>=4){
                res=true;
            }

            i=1;
            /**
             * @brief Test Diagonale descendante en allant vers la droite :\nCompte le nombre d'occurence successive du pion du joueur sur 3 valeurs en partant de la valeur de ligne+1 et colonne+1 avec un pas de +1 pour ligne et colonne. 
             * 
             */
            if(grille[ligne+1][colonne+1] == pion){
                i=i+1;
                if(grille[ligne+2][colonne+2] == pion){
                    i=i+1;
                    if(grille[ligne+3][colonne+3] == pion){
                        i=i+1;
                    }
                }
            }
            /**
             * @brief Test Diagonale ascendante en allant vers la gauche :\nCompte le nombre d'occurence successive du pion du joueur sur 3 valeurs en partant de la valeur de ligne-1 et colonne-1 avec un pas de -1 pour ligne et colonne. 
             * 
             */
            if(grille[ligne-1][colonne-1] == pion){
                i=i+1;
                if(grille[ligne-2][colonne-2] == pion){
                    i=i+1;
                    if(grille[ligne-3][colonne-3] == pion){
                        i=i+1;
                    }
                }
            }

            if(i>=4){
                res=true;
            }

            i=1;
            /**
             * @brief Test Diagonale descendante en allant vers la gauche : Compte le nombre d'occurence successive du pion du joueur sur 3 valeurs en partant de la valeur de ligne-1 et colonne+1 avec un pas de -1 pour ligne et +1 pour colonne. 
             * 
             */
            if(grille[ligne-1][colonne+1] == pion){
                i=i+1;
                if(grille[ligne-2][colonne+2] == pion){
                    i=i+1;
                    if(grille[ligne-3][colonne+3] == pion){
                        i=i+1;
                    }
                }
            }
            /**
             * @brief Test Diagonale ascendante en allant vers la droite : \nCompte le nombre d'occurence successive du pion du joueur sur 3 valeurs en partant de la valeur de ligne+1 et colonne-1 avec un pas de +1 pour ligne et -1 pour colonne. 
             * 
             */
            if(grille[ligne+1][colonne-1] == pion){
                i=i+1;
                if(grille[ligne+2][colonne-2] == pion){
                    i=i+1;
                    if(grille[ligne+2][colonne-3] == pion){
                        i=i+1;
                    }
                }
            }

            if(i>=4){
                res=true;
            }

            i=1;
            /**
             * @brief Compte le nombre d'occurence successive du pion du joueur sur 3 valeurs en partant de la valeur de ligne-1 et colonne-1 avec un pas de -1. Test Verticale en allant vers le haut.
             * 
             */
            if(grille[ligne][colonne-1] == pion){
                i=i+1;
                if(grille[ligne][colonne-2] == pion){
                    i=i+1;
                    if(grille[ligne][colonne-3] == pion){
                        i=i+1;
                    }
                }
            }

            /**
             * @brief Compte le nombre d'occurence successive du pion du joueur sur 3 valeurs en partant de la valeur de ligne+1 et colonne+1 avec un pas de 1. Test Verticale en allant vers le bas.
             * 
             */
            if(grille[ligne][colonne+1] == pion){
                i=i+1;
                if(grille[ligne][colonne+2] == pion){
                    i=i+1;
                    if(grille[ligne][colonne+3] == pion){
                        i=i+1;
                    }
                }
            }

            if(i>=4){
                res=true;
            }
    return res;
}