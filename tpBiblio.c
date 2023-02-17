// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"


int menu()
{
	int choix;
// au programme du TP7 :
printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
printf("\n 2 - afficher tous les livres de la bibliotheque "); 
printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)


// au programme du TP8 :
// ajouter le champ emprunteur à votre structure T_Livre

printf("\n 6 - emprunter un livre de la bibliotheque");
printf("\n 7 - restituer/rendre un livre de la bibliotheque");
printf("\n 8 - trier les livres (par titre)");
printf("\n 9 - trier les livres (par auteur)");
printf("\n 10 - trier les livres (par annee)");

// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
// printf("\n 11- lister les livres disponibles "); 
// printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
// printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ")

printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d[^\n]",&choix);getchar();
return choix;


}


int main()
{
int reponse,chx;
T_Bibliotheque B; 
init( &B );
chargement(&B);
T_Titre titre;
T_Aut auteur;


do
{
chx= menu();
switch(chx)
	{
	case  1 : reponse = ajouterLivre(   &B  );
				if (reponse==1)
					printf(" Ajout reussi !!");
					else
					printf("Impossible d'ajouter (bibliotheque pleine)");
			break;
	case 2 : reponse=afficherBibliotheque(&B);
			if (reponse==0)	
					printf("La bibliotheque est vide");

			break;
	case 3 : printf("Donnez un titre à rechercher :\n");
			 lire(titre,60);
			 reponse = rechercherTitre(&B, &titre);
	 		 if(reponse == 0) 
			 	printf("Il n'y a pas le livre dans la bibliothèque\n");
			else 
				printf("Il y a %d exemplaire(s)\n", reponse);
			break;
	case 4 : printf("Donnez un auteur:\n");
			 lire(auteur,60);
			 rechercherAuteur(&B, &auteur);
			break;
	case 5 : printf("Donnez un titre à supprimer :\n");
			 lire(titre,60);
			 reponse = supprimerLivre(&B, &titre);
			 if(reponse == 0) 
			 	printf("Il n'y a pas le livre dans la bibliothèque\n");
			 else 
			 	printf("%d Livre(s) supprimés\n", reponse);
			break;
	case 6 : printf("Donner le titre du livre à emprunter dans la bibliothèque :\n");
			 lire(titre,60);
			 reponse = emprunterLivre(&B, &titre);
			 if(reponse == 1) 
			 	printf("Vous avez emprunté le livre\n");
			 else if(reponse == 0)
			 	printf("Le livre est déjà emprunté\n");
			 break;
	case 7 : printf("Donner le nom du livre à restituer :\n");
			 lire(titre,60);
			 reponse = restituer(&B, &titre);
			 if(reponse == 1) 
			 	printf("Vous avez rendu le livre\n");
			 else if(reponse == 0)
			 	printf("Le livre n'est pas emprunté\n");
			 break;
	case 8 : printf("Trier les livres (par titre)\n");
			TrierParTitre(&B);
			reponse = afficherBibliotheque(&B);
			break;
	case 9 : printf("Trier les livres (par auteur)\n");
			TrierParAuteur(&B);
			reponse = afficherBibliotheque(&B);
			break;
	case 10 :printf("Trier les livres (par annee)\n");
			TrierParAnnee(&B);
			reponse = afficherBibliotheque(&B);
			break;
	}

}while(chx!=0);
sauvegarde(&B);

return 0;

}
