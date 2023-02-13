# include "biblio.h"


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
int i=0;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre( &(ptrB->etagere[i])  );
			
			}


		
		return 1;
		}
}

int  rechercherLivre(const T_Bibliotheque  *ptrB, char *titre)
{
int i=0;
int compteur=0;
for(i=0;i<ptrB->nbLivres;i++)
	{
	if(strcmp(titre,ptrB->etagere[i].titre)==0)
		{
			compteur++;
		afficherLivre( &(ptrB->etagere[i])  );
		
		}
	}
return compteur;
}

int rechercherLivreParAuteur(const T_Bibliotheque  *ptrB, char *auteur)
{
int i=0;

for(i=0;i<ptrB->nbLivres;i++)
	{
	if(strcmp(auteur,ptrB->etagere[i].auteur)==0)
		{
		afficherLivre( &(ptrB->etagere[i])  );
		return 1;
		}
	}
return 0;
}

int SupprimerUnLivre(T_Bibliotheque *ptrB, char *livre){
int i=0;
for(i=0;i<ptrB->nbLivres;i++)
	{
		printf("*%s* *%s*\n",livre,ptrB->etagere[i].titre);

		if(strcmp(livre,(ptrB->etagere)[i].titre)==0){
			ptrB->etagere[i]=ptrB->etagere[ptrB->nbLivres-1];
			ptrB->nbLivres--;
			return 1;
		}	
	}
return 0;
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

void lectureFichierTXT()
{
int M=100;
FILE *fic=NULL; //le type FILE
char chaine[M];
char chaine2[M];
char c;
fic=fopen("fic.txt","rt"); // r = le mode read   w = mode write (avec ecrasement)
//fopen renvoie NULL si probleme (fichier effac� , disque non accessible ...
if (fic!=NULL)
	{
	do
		{
		//fgets(chaine,M,fic);   //fputs pour �crire dans un fichier txt
		//fscanf(fic,"%s",chaine); //fprintf pour �crire dans un fichier txt
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

//fonction emprunterUnlivre qui permet de mofiier le champ emprunteur d'un livre
//si le livre est disponible
//renvoie 1 si le livre a ete emprunte
//renvoie 0 si le livre n'a pas ete emprunte
int emprunterUnLivre(T_Bibliotheque *ptrB, char *titre, char *emprunteur)
{
int i=0;
for(i=0;i<ptrB->nbLivres;i++)
	{
		if(strcmp(titre,ptrB->etagere[i].titre)==0)
		{
			if(ptrB->etagere[i].emprunteur[0]=='\0')
			{
				strcpy(ptrB->etagere[i].emprunteur,emprunteur);
				return 1;
			}
			else
			{
				printf("Le livre est deja emprunte par %s\n",ptrB->etagere[i].emprunteur);
				return 0;
			}
		}
	}
return 0;
}









