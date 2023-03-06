#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("CODE :", (ptrL->code ), MAX_CODE);
lireChaine("EDITEUR :", (ptrL->editeur ), MAX);
printf("ANNEE :");
scanf("%d", &(ptrL->annee));
lireChaine("EMPRUNTEUR :", (ptrL->emprunteur.nomemprunteur ), MAX);

}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf(" - ");
afficherChaine("CODE (chiffres):", (ptrL->code ));
printf(" - ");
afficherChaine("EDITEUR :", (ptrL->editeur ));
printf(" - ");
printf("ANNEE : %d", (ptrL->annee));
printf(" - ");
printf("EMPRUNTEUR :%s", (ptrL->emprunteur.nomemprunteur ));
printf(" - ");
printf("DATE EMPRUNT :%d", (ptrL->emprunteur.lejour ));
if (ptrL->emprunteur.lejour==0) 
    printf("/%d", (ptrL->emprunteur.lemois ));
else 
    printf("/%d", (ptrL->emprunteur.lemois)+1 );
printf("/%d", (ptrL->emprunteur.lannee ));
printf("\n");
}

void lireDateSysteme(T_Emp *E)
{
char j[9],m[10],h[9],mer[11],vir[2];
int d,a;


system("date > ladate"	);
FILE * fic=NULL;  // pointeur de fichier
fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD

//ici , si fic vaut NULL, alors le fopen a indiquÃ©
//que le fichier ladate n'est pas accessible
if (fic!=NULL)
	{
	while(!feof(fic))	
		{
		fscanf(fic,"%s %d %s %d %s %s %s",j,&d,m,&a,vir,h,mer);		
		if (!feof(fic)) 
			printf("\n-->LU : %s- %d- %s- %d- %s- %s",j,d,m,a,h,mer);		

		}
	fclose(fic);
	
if (strstr(j,"lundi")==0) E->lejour=lundi;
if (strstr(j,"mardi")==0) E->lejour=mardi;
if (strstr(j,"mercredi")==0) E->lejour=mercredi;
if (strstr(j,"jeudi")==0) E->lejour=jeudi;
if (strstr(j,"vendredi")==0) E->lejour=vendredi;
if (strstr(j,"samedi")==0) E->lejour=samedi;
if (strstr(j,"dimanche")==0) E->lejour=dimanche;

E->ladate=d;

if (strcmp(m,"janvier")==0) E->lemois=janvier;
if (strcmp(m,"fevrier")==0) E->lemois=fevrier;
if (strcmp(m,"mars")==0) E->lemois=mars;
if (strcmp(m,"avril")==0) E->lemois=avril;
if (strcmp(m,"mai")==0) E->lemois=mai;
if (strcmp(m,"juin")==0) E->lemois=juin;
if (strcmp(m,"juillet")==0) E->lemois=juillet;
if (strcmp(m,"aout")==0) E->lemois=aout;
if (strcmp(m,"septembre")==0) E->lemois=septembre;
if (strcmp(m,"octobre")==0) E->lemois=octobre;
if (strcmp(m,"novembre")==0) E->lemois=novembre;
if (strcmp(m,"decembre")==0) E->lemois=decembre;


E->lannee=a;
	}
	else
	{
		printf("n souci avec la date systeme !!");
		
		//on range une date irrÃ©elle 
		E->lejour=dimanche;
		E->ladate=99;
		E->lemois=decembre;
		E->lannee=-999;


	}

}




