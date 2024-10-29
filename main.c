#include <stdio.h>
#include <stdlib.h>

#define MAX_TACHES 100

typedef struct {
    int jour;
    int mois;
    int annee;
} dateDecheance;

typedef struct {
    char titre[20];
    char description[30];
    char priorite[20];
    dateDecheance date;
} tache;

void creer(tache *t, int *n) {
    printf("Combien de taches voulez-vous creer ? ");
    scanf("%d", n);

    if (*n > MAX_TACHES || *n < 0) {
        printf("Vous ne pouvez pas creer plus de %d taches ou un nombre negatif \n", MAX_TACHES);
        *n = 0;
        return;
    }

    for (int i = 0; i < *n; i++) {
        printf("Saisir le titre : ");
        scanf("%s", t[i].titre);
        printf("Saisir la description  : ");
        scanf("%s", t[i].description);
        printf("Saisir la priorite  : ");
        scanf("%s", t[i].priorite);

        printf("Saisir le jour : ");
        scanf("%d", &t[i].date.jour);
        printf("Saisir le mois : ");
        scanf("%d", &t[i].date.mois);
        printf("Saisir l'année : ");
        scanf("%d", &t[i].date.annee);
        printf("----------------------------\n");
    }
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

int main() {
    int n = 0;
    tache t[MAX_TACHES];

    _Bool running = 1;
    do {
        int choix;
        printf("Que voulez-vous choisir ?\n");
        printf("1. Creer une tachche  \n2. Afficher les taches \n3. Quitter\n");
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
                running = 0;
                break;
            default:
                printf("Choix invalide\n");
                break;
        }

    } while (running);

    return 0;
}
