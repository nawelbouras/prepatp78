#include "livre.h"
#include <stdlib.h>
#include <stdio.h>


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("CODE :", (ptrL->code ), MAX_CODE);
lireChaine("Editeur :", (ptrL->editeur ), MAX);
printf("ANNEE :");
scanf("%d", &(ptrL->annee ));

strcpy((ptrL->emprunteur).nomemprunteur ,"");
}

void afficherLivre(T_livre *ptrL)
{

    char jour[13], mois[13];

    printf("\n titre du livre : %s", ptrL->titre);
    printf("\n auteur du livre : %s", ptrL->auteur);
    printf("\n code du livre : %s", ptrL->code);
    printf("\n editeur du livre : %s", ptrL->editeur);
    printf("\n annee du livre : %d", ptrL->annee);

    printf("\n emprunteur du livre : %s", ptrL->emprunteur.nomemprunteur);

    printf("\n  emprunt realise le : ");
    switch (ptrL->emprunteur.lejour)
    {
    case 0:
        strcpy(jour, "lundi");
        break;
    case 1:
        strcpy(jour, "mardi");
        break;
    case 2:
        strcpy(jour, "mercredi");
        break;
    case 3:
        strcpy(jour, "jeudi");
        break;
    case 4:
        strcpy(jour, "vendredi");
        break;
    case 5:
        strcpy(jour, "samedi");
        break;
    case 6:
        strcpy(jour, "dimanche");
        break;

    default:
        strcpy(jour, "jour inconnu");
        break;
    }
    printf("%s ", jour);

    printf("%d ", ptrL->emprunteur.ladate);

    switch (ptrL->emprunteur.lemois)
    {
    case 0:
        strcpy(mois, "janvier");
        break;
    case 1:
        strcpy(mois, "fevrier");
        break;
    case 2:
        strcpy(mois, "mars");
        break;
    case 3:
        strcpy(mois, "avril");
        break;
    case 4:
        strcpy(mois, "mai");
        break;
    case 5:
        strcpy(mois, "juin");
        break;
    case 6:
        strcpy(mois, "juillet");
        break;
    case 7:
        strcpy(mois, "aout");
        break;
    case 8:
        strcpy(mois, "septembre");
        break;
    case 9:
        strcpy(mois, "octobre");
        break;
    case 10:
        strcpy(mois, "novembre");
        break;
    case 11:
        strcpy(mois, "decembre");
        break;

    default:
        strcpy(jour, "mois inconnu");
        break;
    }
    printf("%s ", mois);

    printf("%d ", ptrL->emprunteur.lannee);
}

void lireDateSysteme(T_Emp *E)
{

    /*printf(">%p<\n", E);
    printf("nom=>%d<\n", E->ladate);
    printf("resultat str: %d\n", strstr("Lun", "lundi"));
    */

    char j[9], m[10], h[9], mer[11];//, vir[2];
    int d, a;

    system("LC_TIME=fr_FR.UTF-8 date > ladate");
    FILE *fic = NULL;           // pointeur de fichier
    fic = fopen("ladate", "r"); // fileOpen en mode 'r'EAD

    // ici , si fic vaut NULL, alors le fopen a indiquÃ©
    // que le fichier ladate n'est pas accessible
    if (fic != NULL)
    {
        //printf("fichier ouvert\n");
        while (!feof(fic))
        {
            //printf("premier while\n");
            fscanf(fic, "%s %d %s %d %s %s", j, &d, m, &a, h, mer);
            if (!feof(fic))
                printf("\n-->LU : %s- %d- %s- %d- %s- %s", j, d, m, a, h, mer);
        }
        fclose(fic);

printf(">%s<\n", j);

        if (strstr(j, "lundi"))
            E->lejour = lundi;
        if (strstr(j, "mardi"))
            E->lejour = mardi;
        if (strstr(j, "mercredi"))
            E->lejour = mercredi;
        if (strstr(j, "jeudi"))
            E->lejour = jeudi;
        if (strstr(j, "vendredi"))
            E->lejour = vendredi;
        if (strstr(j, "samedi"))
            E->lejour = samedi;
        if (strstr(j, "dimanche"))
            E->lejour = dimanche;

        E->ladate = d;

        if (strcmp(m, "janvier") == 0)
            E->lemois = janvier;
        if (strcmp(m, "fevrier") == 0)
            E->lemois = fevrier;
        if (strcmp(m, "mars") == 0)
            E->lemois = mars;
        if (strcmp(m, "avril") == 0)
            E->lemois = avril;
        if (strcmp(m, "mai") == 0)
            E->lemois = mai;
        if (strcmp(m, "juin") == 0)
            E->lemois = juin;
        if (strcmp(m, "juillet") == 0)
            E->lemois = juillet;
        if (strcmp(m, "aout") == 0)
            E->lemois = aout;
        if (strcmp(m, "septembre") == 0)
            E->lemois = septembre;
        if (strcmp(m, "octobre") == 0)
            E->lemois = octobre;
        if (strcmp(m, "novembre") == 0)
            E->lemois = novembre;
        if (strcmp(m, "decembre") == 0)
            E->lemois = decembre;

        E->lannee = a;
    }
    else
    {
        printf("n souci avec la date systeme !!");

        // on range une date irrÃ©elle
        E->lejour = dimanche;
        E->ladate = 99;
        E->lemois = decembre;
        E->lannee = -999;
    }
}