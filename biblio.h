#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 100 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct a
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void lectureFichierTXT();
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercherTitre(T_Bibliotheque *ptrB, T_Titre *titre);
void rechercherAuteur(T_Bibliotheque *ptrB, T_Aut *auteur);
int supprimerLivre(T_Bibliotheque *ptrB, T_Titre *titre);
int emprunterLivre(T_Bibliotheque *ptrB, T_Titre *titre);
int restituer(T_Bibliotheque *ptrB, T_Titre *titre);
void lectureFichierTXT();
void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);
void TrierParAnnee(T_Bibliotheque *ptrB);
void TrierParAuteur(T_Bibliotheque *ptrB);
void TrierParTitre(T_Bibliotheque *ptrB);






#endif