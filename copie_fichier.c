/*******************************************/
/*                                         */
/*   Copie dans un fichier des entiers     */
/*   triple d'entiers contenus dans un  */
/*   fichier                               */
/*                                         */
/*******************************************/



#include <stdio.h>

int TripleFichier(void){
    FILE *fpr, *fpw; /* deux pointeurs pour deux fichiers */
    int n; // pour lire

    /* ouverture des fichiers */
    fpr = fopen("fichierLecture.txt", "r");
    fpw = fopen("fichierEcriture.txt", "w");
    /* gestion des erreurs */
    if(fpr == NULL || fpw == NULL){
        return 1; // code d'erreur retourn� au main
    }

    while(fscanf(fpr, "%d", &n) == 1) // lecture d'un entier
    {
      fprintf(fpw, "%d\n", 3 * n); // �criture du triple
      //fprintf(fpw, "%s\n","" );
    }

    // fermeture des fichiers
    fclose(fpr);
    fclose(fpw);
    return 0; // pas d'erreur
}

int main(){
    int codeErr;
    codeErr = TripleFichier();
   // on r�cu�re le code d'erreur dans le main
   if(codeErr != 0) puts("Erreur d'ouverture de fichier !");
    return 0;
}
