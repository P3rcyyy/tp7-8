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
printf("\n 11- lister les livres disponibles "); 
printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.

printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d",&choix);getchar();

//scanf("%d[^\n]",&choix);getchar();
return choix;


}



int main()
{

int reponse,chx;
T_Aut auteur;
T_Titre titre;
char nomemprunteur[K_MaxEmp];
T_Bibliotheque B; 
init( &B );
chargement(&B);

chx= menu();
while(chx!=0){
switch(chx)
	{
	case  1 : reponse = ajouterLivre(   &B  );
				if (reponse==1)
					printf(" ajout reussi !!");
					else
					printf("impossible d ajouter (bibliotheque pleine)");
			break;
	case 2 : reponse=afficherBibliotheque(&B);
			if (reponse==0)	
					printf("La bibliotheque est vide");

			break;	
	
	case 3 : 
		printf("Donner le titre du livre a rechercher : ");
		lire(titre,MAX_TITRE);
			reponse = rechercherLivre(&B,titre);
			if (reponse!=0)
				printf("\nRecherche réussie,le titre a été trouvé %d fois",reponse);
				else
				printf("\nRecherche échouée,le livre n'est pas présent dans la bibliothèque");
		break;
	
	case 4 :
		printf("Donnez le nom de l'auteur à rechercher : \n");
		lire(auteur,K_MaxAut);
			reponse = rechercherLivreParAuteur(&B,auteur);
			if (reponse==1)
				printf("\nRecherche réussie, l'auteur a été trouvé\n");
				else
				printf("\nRecherche échouée,l'auteur n'a pas été trouvé\n");
		break;

	case 5 :
		printf("donnez le nom du titre du livre à supprimer \n");
		lire(titre,MAX_TITRE);
		printf("%s",titre);
			reponse = SupprimerUnLivre(&B,titre);
			if (reponse==1)
				printf("\nSuppression réussie,le livre a été supprimé\n");
				else
				printf("\nSuppression échouée,le livre n'a pas été supprimé\n");
		break;

	case 6 :
		lireChaine("Donnez le nom du titre du livre à emprunter :",titre,MAX_TITRE);
		lireChaine("Quel est votre nom :",nomemprunteur,K_MaxEmp);
			reponse = emprunterUnLivre(&B,titre,nomemprunteur);
			if (reponse==1){
				printf("\nEmprunt réussie,le livre a été emprunté\n");
			}
				else
				printf("\nEmprunt échouée,le livre n'a pas été emprunté\n");
		break;

	case 7 :
		lireChaine("Donnez le nom du titre du livre à rendre :",titre,MAX_TITRE);		
			reponse = restituerUnLivre(&B,titre);
			if (reponse==1)
				printf("\nRendu réussie,le livre a été rendu\n");
				else
				printf("\nRendu échouée,le livre n'a pas été rendu\n");
		break;

	case 8 :
		trititre(&B);
		printf("Tri par titre réussi\n");
		printf("Voici la liste des livres triés par titre\n");
		afficherBibliotheque(&B);
		break;

	case 9 :
		triauteur(&B);
		printf("Tri par auteur réussi\n");
		printf("Voici la liste des livres triés par auteur\n");
		afficherBibliotheque(&B);
		break;

	case 10 :
		triannee(&B);
		printf("Tri par annee réussi\n");
		printf("Voici la liste des livres triés par annee\n");
		afficherBibliotheque(&B);
		break;

	case 11 :
	printf("Livre disponible : \n");
		listerlivredispo(&B);
		break;

	case 12 :
	listerretard(&B);
		break;

	}
	chx= menu();
}

sauvegarde(&B);
return 0;

}
