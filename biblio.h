#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 100 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);
int  rechercherLivre(const T_Bibliotheque  *ptrB, char *titre);
int rechercherLivreParAuteur(const T_Bibliotheque  *ptrB, char *auteur);
int SupprimerUnLivre(T_Bibliotheque  *ptrB, char *livre);
void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);
void lectureFichierTXT();
int emprunterUnLivre(T_Bibliotheque *ptrB, char *titre,char *nomemprunteur);
int restituerUnLivre(T_Bibliotheque *ptrB, char *titre);
void trititre(T_Bibliotheque *ptrB);
void triauteur(T_Bibliotheque *ptrB);
void triannee(T_Bibliotheque *ptrB);
void listerlivredispo(T_Bibliotheque *ptrB);
void listerretard(T_Bibliotheque *ptrB);



#endif