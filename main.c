#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    int j = 0;
    printf("Combien de t�ches voulez-vous cr�er ? ");
    scanf("%d", &nombreNouvellesTaches);

    // V�rification de la validit� du nombre de nouvelles t�ches
    if (nombreNouvellesTaches < 0 || nombreNouvellesTaches + *n > MAX_TACHES) {
        printf("Vous ne pouvez pas cr�er plus de %d t�ches ou un nombre n�gatif.\n", MAX_TACHES);
        return;
    }

    for (int i = *n; i < *n + nombreNouvellesTaches; i++) {
        printf("Saisir le titre : ");
        scanf(" %[^\n]", t[i].titre);
        printf("Saisir la description : ");
        scanf(" %[^\n]", t[i].description);

        char priorite[20];
        do {
            printf("Saisir la priorit� (low/high) : ");
            scanf(" %[^\n]", priorite);

            if (strcmp(priorite, "low") != 0 && strcmp(priorite, "high") != 0) {
                printf("Priorit� invalide, veuillez choisir 'low' ou 'high'.\n");
            }
        } while (strcmp(priorite, "low") != 0 && strcmp(priorite, "high") != 0);

        strcpy(t[i].priorite, priorite);

        printf("Saisir le jour : ");
        scanf("%d", &t[i].date.jour);
        printf("Saisir le mois : ");
        scanf("%d", &t[i].date.mois);
        printf("Saisir l'ann�e : ");
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
     printf("---------------------\n");
     printf("---------------------\n");
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
    char choice[15];
    printf("quel est le numero du tache que vous souaithez de modifier : %d",index);
    scanf("%d",&index);

    if (index < 1 || index > n) {
        printf("Numero de tache invalide.\n");
        return;
    }
    printf("qu'est ce que tu veux modifier (titre , description , priorite , date\n)");
    printf("choisis qu'est ce que tu veux modifier : %d",choice);
    scanf("%s",choice);

        index--;
        if(strcmp(choice,"titre")==0){
        printf("Saisir le titre : ");
        scanf(" %[^\n]", t[index].titre);}
        else if(strcmp(choice,"description")==0){
        printf("Saisir la description  : ");
        scanf(" %[^\n]", t[index].description);}
        else if(strcmp(choice,"priorite")==0){
        printf("Saisir la priorite  : ");
        scanf(" %[^\n]", t[index].priorite);}
        else if(strcmp(choice,"date")==0){
        printf("Saisir le jour : ");
        scanf("%d", &t[index].date.jour);
        printf("Saisir le mois : ");
        scanf("%d", &t[index].date.mois);
        printf("Saisir l'ann�e : ");
        scanf("%d", &t[index].date.annee);}


}

void supprimer(tache *t, int *n) {
    int index;
    printf("Tapez le numero de la tache que vous souhaitez supprimer : ");
    scanf("%d", &index);

    if (index > 0 && index <= *n) {
        for (int i = index - 1; i < *n - 1; i++) {
            t[i] = t[i + 1];
        }
        (*n)--;
    } else {
        printf("C'est un num�ro invalide\n");
    }
}

void filtrer(tache *t, int *n) {
    char choixPriorite[20];
    printf("tu vas filtrer par la priorite\n");
    printf("Choisissez une priorite a filtrer (low ou high) : ");
    scanf(" %[^\n]", choixPriorite);

    printf("Voici les taches avec la priorite '%s' :\n", choixPriorite);
    for (int i = 0; i < *n; i++) {
        if (strcmp(t[i].priorite, choixPriorite) == 0) {
            printf("Tache %d:\n", i + 1);
            printf("Titre : %s\n", t[i].titre);
            printf("Description : %s\n", t[i].description);
            printf("Priorit� : %s\n", t[i].priorite);
            printf("Date : %02d/%02d/%04d\n", t[i].date.jour, t[i].date.mois, t[i].date.annee);
            printf("---------------------\n");
        }
    }
}

int validInt ( char choix[20] );

int main() {
    int n = 0;
    tache t[MAX_TACHES];
    // int choix;
    int choix;
    char choixInput[20];



    _Bool running = 1;
    do {
        printf("Que voulez-vous choisir ?\n");
        printf("1. Creer une tache  \n2. Afficher les taches \n3. modifier une tache \n4. supprimer\n5. filtrer \n6 .quitter\n");
        printf("--------------------------------\n");
        printf("ecrire le numero : ");
        scanf("%s", &choixInput);

        _Bool validating = true;


        do {
            if ( validInt( choixInput ) ) {
                printf("this is valide\n");
                validating = false;
                choix = validInt( choixInput );
            } else {
                printf("Please enter a valid number, allowed numbers (1,2,3,4,5,6) ");
                scanf("%s", &choixInput);
            }
        } while( validating );

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
            case 4 :
                supprimer(t,&n);
                break;
            case 5:
                filtrer(t,&n);
                break;
            case 6:
                running = 0;
                break;
            default:
                printf("Choix invalide\n");
                break;
        }

    } while (running);

    return 0;
}

int validInt ( char choix[20] ) {
    int isValid = 1;
    int num;
    for ( int i = 0; i < strlen(choix); i++) {
        if ( !isdigit(choix[i]) ) {
            isValid = 0;
            break;
        }
    }

    if ( isValid ) {
        num = atoi(choix);
        return num;
    } else {
        return 0;
    }
}

