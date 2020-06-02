

/*******************************************/
/*                                         */
/*   Charger des entiers en m�moire        */
/*  centrale depuis un fichier texte       */
/*        et les afficher.                 */
/*                                         */
/*******************************************/



#include <stdio.h>
#include <stdlib.h> // pour utiliser la fonction exit

#define NB_ELEM_MAX 100
 //chemin vers fichier absolu
#define MON_FICHIER "/home/komo/ownCloud2/documents/afpi/bts/sn_ir/cours/\
S4. Développement logiciel/s4.4 Programmation procedurale/C/9-fichiers/\
ressources/fichierLecture.txt"
 //chemin vers fichier relitif
#define MON_FICHIER_ABS "fichierLecture.txt"


int ChargeFichier(char[]);
void Affiche(char[], int);

int main(){
    char tab[NB_ELEM_MAX];
    int n;
    n = ChargeFichier(tab);
    Affiche(tab, n);
    return 0;
}



int ChargeFichier(char tableau[NB_ELEM_MAX]){
    FILE *fp;
    int i = 0;
    /*ouverture deu fichier */
    fp = fopen(MON_FICHIER, "r");

    /* gestion des erreurs */
    if(fp == NULL){
        puts("Erreur d'ouverture de fichier :");
        puts("Fichier inexistant ou permissions insuffisantes");
        exit(1); // termine le programme avec code d'erreur
    }

    /* on peut mettre des appels de fonctions comme fscanf dans
        une condition. Ici, fscanf retourne 1 en cas de succ�s */
    while(i < NB_ELEM_MAX && fscanf(fp, "%c", &tableau[i]) == 1)  i++;
    //while(i < NB_ELEM_MAX && fscanf(fp, "%d", tableau +i) == 1)  i++; autre écriture
    fclose(fp); // fermeture du fichier
    return (i - 1); // on retourne le nombre d'�l�ments lus
}

void Affiche(char tableau[], int n){
    int i;
    for(i = 0; i < n ; i++) printf("tableau[%d] = %c\n", i, tableau[i]);
}
