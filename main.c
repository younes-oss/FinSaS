#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TACHES 100

typedef struct {
    int jour;
    int mois;
    int annee;
} dateDecheance;

typedef struct {
    char titre[25];
    char description[30];
    char priorite[20];
    dateDecheance date;
} tache;

void creer(tache *t, int *n) {
    int nombreNouvellesTaches;
    printf("Combien de taches voulez-vous creer ? ");
    scanf("%d", &nombreNouvellesTaches);

    if (nombreNouvellesTaches + *n > MAX_TACHES || nombreNouvellesTaches < 0) {
        printf("Vous ne pouvez pas creer plus de %d tâches ou un nombre négatif\n", MAX_TACHES);
        return;
    }

    for (int i = *n; i < *n + nombreNouvellesTaches; i++) {
        printf("Saisir le titre : ");
        scanf(" %[^\n]", t[i].titre);
        printf("Saisir la description : ");
        scanf(" %[^\n]", t[i].description);
        printf("Saisir la priorité : ");
        scanf(" %[^\n]", t[i].priorite);
        printf("Saisir le jour : ");
        scanf("%d", &t[i].date.jour);
        printf("Saisir le mois : ");
        scanf("%d", &t[i].date.mois);
        printf("Saisir l'année : ");
        scanf("%d", &t[i].date.annee);
        printf("----------------------------\n");
    }


    *n += nombreNouvellesTaches;
}


void afficher(tache *t, int n) {
    if (n == 0) {
        printf("Aucune tache a afficher\n");
        printf("---------------------\n");
        return;
    }

    printf("Voici l'affichage des taches : \n");
    for (int i = 0; i < n; i++) {
        printf("Tache %d:\n", i + 1);
        printf("Titre : %s\n", t[i].titre);
        printf("Description : %s\n", t[i].description);
        printf("Priorite : %s\n", t[i].priorite);
        printf("Date : %02d/%02d/%04d\n", t[i].date.jour, t[i].date.mois, t[i].date.annee);
        printf("---------------------\n");
    }
}

void modifier(tache *t , int n){
    if (n == 0) {
        printf("Aucune tache a afficher\n");
        printf("---------------------\n");
        return;
    }
    int index;
    printf("quel est le numero du tache que vous souaithez de modifier : %d",index);
    scanf("%d",&index);

    if (index < 1 || index > n) {
        printf("Numéro de tâche invalide.\n");
        return;
    }

        index--;

        printf("Saisir le titre : ");
        scanf(" %[^\n]", t[index].titre);
        printf("Saisir la description  : ");
        scanf(" %[^\n]", t[index].description);
        printf("Saisir la priorite  : ");
        scanf(" %[^\n]", t[index].priorite);

        printf("Saisir le jour : ");
        scanf("%d", &t[index].date.jour);
        printf("Saisir le mois : ");
        scanf("%d", &t[index].date.mois);
        printf("Saisir l'année : ");
        scanf("%d", &t[index].date.annee);


}

int main() {
    int n = 0;
    tache t[MAX_TACHES];

    _Bool running = 1;
    do {
        int choix;
        printf("Que voulez-vous choisir ?\n");
        printf("1. Creer une tache  \n2. Afficher les taches \n3.modifier une tache \n4. Quitter\n");
        printf("ecrire le numero : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creer(t, &n);
                break;
            case 2:
                afficher(t, n);
                break;
            case 3:
                modifier(t,n);
                break;
            case 4:
                running = 0;
                break;
            default:
                printf("Choix invalide\n");
                break;
        }

    } while (running);

    return 0;
}
