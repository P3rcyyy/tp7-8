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
//char chaine2[M];
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
int emprunterUnLivre(T_Bibliotheque *ptrB, char *titre, char *nomemprunteur1)
{
int i;
for(i=0;i<ptrB->nbLivres;i++)
	{
	if(strcmp(titre,ptrB->etagere[i].titre)==0)
		{
			if(ptrB->etagere[i].emprunteur.nomemprunteur[0]== '\0')
			{
				strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,nomemprunteur1);
				lireDateSysteme(&(ptrB->etagere[i]).emprunteur);
				return 1;
			}
			else
			{
				printf("Le livre est deja emprunte par %s\n",(ptrB->etagere[i].emprunteur).nomemprunteur);
				return 0;
			}
		}
	}	
	
return 0;
}

int restituerUnLivre(T_Bibliotheque *ptrB, char *titre)
{
	int i=0;
	for(i=0;i<ptrB->nbLivres;i++){
		if(strcmp(titre,ptrB->etagere[i].titre)==0){
				if((ptrB->etagere[i].emprunteur).nomemprunteur[0]== '\0')
				{
					printf("Le livre n'est pas emprunte\n");
					return 0;
				}
				else
				{
					(ptrB->etagere[i].emprunteur).nomemprunteur[0]= '\0';
					(ptrB->etagere[i].emprunteur).lejour=0;
					(ptrB->etagere[i].emprunteur).lemois=0;
					(ptrB->etagere[i].emprunteur).lannee=0;
					return 1;
				}
		
		}	
	}
return 0;
}

void trititre(T_Bibliotheque *ptrB)
{
int i=0;
int j=0;
T_livre temp;
for(i=0;i<ptrB->nbLivres;i++)
	{
		for(j=i+1;j<ptrB->nbLivres;j++)
		{
			if(strcmp(ptrB->etagere[i].titre,ptrB->etagere[j].titre)>0)
			{
				temp=ptrB->etagere[i];
				ptrB->etagere[i]=ptrB->etagere[j];
				ptrB->etagere[j]=temp;
			}
		}
	}
}

void triauteur(T_Bibliotheque *ptrB)
{
int i=0;
int j=0;
T_livre temp;
for(i=0;i<ptrB->nbLivres;i++)
	{
		for(j=i+1;j<ptrB->nbLivres;j++)
		{
			if(strcmp(ptrB->etagere[i].auteur,ptrB->etagere[j].auteur)>0)
			{
				temp=ptrB->etagere[i];
				ptrB->etagere[i]=ptrB->etagere[j];
				ptrB->etagere[j]=temp;
			}
		}
	}
}

void triannee(T_Bibliotheque *ptrB)
{
int i=0;
int j=0;
T_livre temp;
for(i=0;i<ptrB->nbLivres;i++)
	{
		for(j=i+1;j<ptrB->nbLivres;j++)
		{
			if(ptrB->etagere[i].annee>ptrB->etagere[j].annee)
			{
				temp=ptrB->etagere[i];
				ptrB->etagere[i]=ptrB->etagere[j];
				ptrB->etagere[j]=temp;
			}
		}
	}
}

void listerlivredispo(T_Bibliotheque *ptrB)
{
int i=0;
for(i=0;i<ptrB->nbLivres;i++)
	{
		if(ptrB->etagere[i].emprunteur.nomemprunteur[0]== '\0')
		{
			printf("%s\n",ptrB->etagere[i].titre);
		}
	}
}

void listerretard(T_Bibliotheque *ptrB)
{
T_Emp dateactuelle;
lireDateSysteme(&dateactuelle);// a mettre quand les tests sont finis
/*dateactuelle.lejour=30;
dateactuelle.lemois=8;
dateactuelle.lannee=2023;
ptrB->etagere[1].emprunteur.lejour=28; //	a mettre pour tester ce sera sur le livre le rouge et le noir
ptrB->etagere[1].emprunteur.lemois=2;
ptrB->etagere[1].emprunteur.lannee=2023;*/
int i=0;
T_Jour aux=0;
for(i=0;i<ptrB->nbLivres;i++)
	{
		if(ptrB->etagere[i].emprunteur.nomemprunteur[0]!= '\0')
		{
		//if pas la même année
		if((ptrB->etagere[i].emprunteur.lannee)==dateactuelle.lannee)
		{
			//if du février bissextile
			if (((ptrB->etagere[i].emprunteur.lejour)>22 &&  (ptrB->etagere[i].emprunteur.lejour)<=29) && (ptrB->etagere[i].emprunteur.lemois)==2 && (ptrB->etagere[i].emprunteur.lannee)%4==0)
			{
				aux = (29-(ptrB->etagere[i].emprunteur.lejour));
				aux=7-aux;
				printf("BIBIBIBIBIBI");
			}
			
			//if du février non bissextile
			else if (((ptrB->etagere[i].emprunteur.lejour)>22 &&  (ptrB->etagere[i].emprunteur.lejour)<=28) && (ptrB->etagere[i].emprunteur.lemois)==2 && (ptrB->etagere[i].emprunteur.lannee)%4!=0)
			{
				aux = (28-(ptrB->etagere[i].emprunteur.lejour));
				aux=7-aux;
			}
			//if du mois de 31 jours
			else if (((ptrB->etagere[i].emprunteur.lejour)>24 &&  (ptrB->etagere[i].emprunteur.lejour)<=31) && ((ptrB->etagere[i].emprunteur.lemois)==1 || (ptrB->etagere[i].emprunteur.lemois)==3 || (ptrB->etagere[i].emprunteur.lemois)==5 || (ptrB->etagere[i].emprunteur.lemois)==7 || (ptrB->etagere[i].emprunteur.lemois)==8 || (ptrB->etagere[i].emprunteur.lemois)==10 || (ptrB->etagere[i].emprunteur.lemois)==12))
			{
				aux = (31-(ptrB->etagere[i].emprunteur.lejour));
				aux=7-aux;
			}
			//if du mois de 30 jours
			else if (((ptrB->etagere[i].emprunteur.lejour)>23 &&  (ptrB->etagere[i].emprunteur.lejour)<=30) && ((ptrB->etagere[i].emprunteur.lemois)==4 || (ptrB->etagere[i].emprunteur.lemois)==6 || (ptrB->etagere[i].emprunteur.lemois)==9 || (ptrB->etagere[i].emprunteur.lemois)==11))
			{
				aux = (30-(ptrB->etagere[i].emprunteur.lejour));
				aux=7-aux;
			}
			else
			{
				aux = (7+(ptrB->etagere[i].emprunteur.lejour));
			}
		}
		else if ((ptrB->etagere[i].emprunteur.lemois==12)&& (ptrB->etagere[i].emprunteur.lejour>24) && (ptrB->etagere[i].emprunteur.lejour<=31))
			{
				aux = (31-(ptrB->etagere[i].emprunteur.lejour));
				aux=7-aux;
			}
		else{
			printf("vous êtes en retard d'un an !!!!!!!!!!!!!!!!!!!");
			break;

		}


				
			if(dateactuelle.lejour>aux)
			{
				printf("%s\n",ptrB->etagere[i].titre);
			}
			else
			{
				printf("Aucun retard\n");
			}
		}
	}
}
		


