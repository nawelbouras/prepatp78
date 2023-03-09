#include "biblio.h"
#include <stdlib.h>
#include <stdio.h>

void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}	
return 0;
}



int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre(&(ptrB->etagere[i]));
			}		
		return 1;
		}
}

int rechercherTitre(T_Bibliotheque *ptrB, T_Titre *titre){
	int i, compteur=0;
	for(i=0;i<(ptrB->nbLivres);i++){
		if(strcmp(ptrB->etagere[i].titre, *titre) == 0){
			compteur++;
		}
	}
	return compteur;
	}

void rechercherAuteur(T_Bibliotheque *ptrB, T_Aut *auteur){
	int i;
	for(i=0;i<(ptrB->nbLivres);i++){
		if(strcmp(ptrB->etagere[i].auteur, *auteur) == 0){
			printf("Livre trouvé : \n");
			afficherLivre(&(ptrB->etagere[i]));
		}
	}
}

int supprimerLivre(T_Bibliotheque *ptrB, T_Titre *titre){
	int i;
	for(i=0;i<=(ptrB->nbLivres);i++){
		if(strcmp(ptrB->etagere[i].titre, *titre) == 0){
			ptrB->etagere[i] = ptrB->etagere[ptrB->nbLivres-1];
			ptrB->nbLivres--;
			return 1;
		}
		}
	return 0;
}

/*int emprunterLivre(T_Bibliotheque *ptrB, T_Titre *titre){
	int i;
	for(i=0;i<=(ptrB->nbLivres);i++){
		if(strcmp(ptrB->etagere[i].titre, *titre) == 0 && *(ptrB->etagere[i].emprunteur) == NULL){
			lireChaine("NOM :", (ptrB->etagere[i].emprunteur), MAX_TITRE);
			return 1;
		}
		
	}
	return 0;
}*/

int restituer(T_Bibliotheque *ptrB, T_Titre *titre){
	int i;
	for(i=0;i<=(ptrB->nbLivres);i++){
		if(strcmp(ptrB->etagere[i].titre, *titre) == 0 && strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,"")!=0){
			ptrB->etagere[i].emprunteur.nomemprunteur[0] = '\0';
			ptrB->etagere[i].emprunteur.lejour = '\0';
			ptrB->etagere[i].emprunteur.ladate = '\0';
			ptrB->etagere[i].emprunteur.lemois = '\0';
			ptrB->etagere[i].emprunteur.lannee = '\0';
			return 1;
		}
	}
	return 0;
}

int emprunterLivre(T_Bibliotheque *ptrB, T_Titre *titre, char nom[]){
	int i;
	for(i=0;i<=(ptrB->nbLivres);i++){
		if(strcmp(ptrB->etagere[i].titre, *titre) == 0 && strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,"")==0){
			strcpy((ptrB->etagere[i].emprunteur).nomemprunteur, nom);
			lireDateSysteme(&(ptrB->etagere[i].emprunteur));
			return 1;
		}		
	}
	return 0;
}

void TrierParTitre(T_Bibliotheque *ptrB){
	int i, j;
	T_livre temp;
	for(i=0;i<(ptrB->nbLivres);i++){
		for(j=0;j<(ptrB->nbLivres);j++){
			if(strcmp(ptrB->etagere[i].titre, ptrB->etagere[j].titre) < 0){
				temp = ptrB->etagere[i];
				ptrB->etagere[i] = ptrB->etagere[j];
				ptrB->etagere[j] = temp;
			}
		}
	}
}
void TrierParAuteur(T_Bibliotheque *ptrB){
	int i, j;
	T_livre temp;
	for(i=0;i<(ptrB->nbLivres);i++){
		for(j=0;j<(ptrB->nbLivres);j++){
			if(strcmp(ptrB->etagere[i].auteur, ptrB->etagere[j].auteur) < 0){
				temp = ptrB->etagere[i];
				ptrB->etagere[i] = ptrB->etagere[j];
				ptrB->etagere[j] = temp;
			}
		}
	}
}
void TrierParAnnee(T_Bibliotheque *ptrB){
	int i, j;
	T_livre temp;
	for(i=0;i<(ptrB->nbLivres);i++){
		for(j=0;j<(ptrB->nbLivres);j++){
			if(ptrB->etagere[i].annee < ptrB->etagere[j].annee){
				temp = ptrB->etagere[i];
				ptrB->etagere[i] = ptrB->etagere[j];
				ptrB->etagere[j] = temp;
			}
		}
	}
}
void listerLivreEnRetard(T_Bibliotheque *ptrB){
	int i;
	int date_debut,date_fin, jour, mois, annee;
	T_Emp E;
    lireDateSysteme(&E);
	date_fin = date_to_jour(E.ladate, E.lemois, E.lannee);
	for(i=0;i<(ptrB->nbLivres);i++){
		jour = ptrB->etagere[i].emprunteur.ladate;
		mois = ptrB->etagere[i].emprunteur.ladate;
		annee = ptrB->etagere[i].emprunteur.lannee;
		date_debut = date_to_jour(jour, mois, annee);
		if((date_fin-date_debut)>7){
			afficherLivre(&(ptrB->etagere[i]));}
		}
	}
	
void livreDisponible(T_Bibliotheque *ptrB){
	int i;
	for(i=0;i<(ptrB->nbLivres);i++){
		if(strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,"")==0){
			printf("livre numéro %d\n\n\n",i);
			afficherLivre(&(ptrB->etagere[i]));
		}
	}
}





/***********************************************************************************************************************************/
void lectureFichierTXT()
{
int M=100;
FILE *fic=NULL; //le type FILE
char chaine[M];
char chaine2[M];
char c;
fic=fopen("fic.txt","rt"); // r = le mode read   w = mode write (avec ecrasement)
//fopen renvoie NULL si probleme (fichier effacé , disque non accessible ...
if (fic!=NULL)
	{
	do
		{
		//fgets(chaine,M,fic);   //fputs pour écrire dans un fichier txt
		//fscanf(fic,"%s",chaine); //fprintf pour écrire dans un fichier txt
	//	fscanf(fic,"%s %s",chaine,chaine2);
		fscanf(fic,"%c",&c);
		//fscanf(fic,"%c",&chaine[0]);
	//	if (!feof(fic))
           //printf("\n\t >%s--%s<",chaine,chaine2);
        printf(">%c<",c);
		}
    while(!feof(fic));
	fclose(fic);
	puts("\nLECTURE REUSSIE ..............");
	}
	else puts("ECHEC DE LECTURE DU FICHIER TXT !!!!!  ");
}


void sauvegarde(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i;
fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	for(i=0;i<ptrB->nbLivres;i++)
		{
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

		}
	fclose(fic);
	puts("SAUVEGARDE REUSSIE ..............");



	}
	else puts("ECHEC DE SAUVEGARDE  !!!!!  ");




}

void chargement(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i=0;
fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	do
		{

		fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
		i++;
		}
		while(!feof(fic));
	fclose(fic);
	ptrB->nbLivres=i-1;
	puts("CHARGEMENT  REUSSI ..............");
	}
	else puts("ECHEC DE CHARGEMENT  !!!!!  ");

}
/***********************************************************************************************************************************/
	int date_to_jour(int jour, int mois, int annee)
{
    int N = 367 * annee - 7 * (annee + (mois + 9) / 12) / 4 + 275 * mois / 9 + jour - 730531 + 1721425 - 2415019; // algo de Rata Die
    return N;
}





