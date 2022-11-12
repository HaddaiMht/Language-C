#include <stdio.h>
#include <stdlib.h>


/*Definition de la structure de donn�es d'une liste chain�e*/
 typedef struct ListeElement{
 	int value;
 	struct ListeElement *next;
 }ListeElement,*List;
 
 typedef enum Booleen{
 	false,
 	true
 }Bool;




/**
* Retourne une nouvelle Liste
* @return Une liste vide
*/
List new_list()
{
	return NULL;
}

/*---------------------------------------------------------------------*/

/**
* V�rifie si une List est vide
* @param li La liste � tester
* @return true si elle est vide, faux sinon
*/
Bool is_empty_list(List li)
{
	if(li == NULL)
		return true;

	return false;
}

/*---------------------------------------------------------------------*/

/**
* Affiche une Liste
* @param li La liste � afficher
*/
 void print_list(List li)
{
	if(is_empty_list(li))
	{
		printf("Rien a afficher, la Liste est vide.\n");
		return;
	}
	
	printf("Les element de la liste sont :");
	while(li != NULL)
	{
		printf("[%d] ", li->value);
		li = li->next;
	}

	printf("\n");
}

/*---------------------------------------------------------------------*/

/**
* Retourne la taille de la Liste
* @param li La liste
* @return Le nombre d'�lements de la Liste
*/
int list_length(List li)
{
	int size = 0;

	if(is_empty_list(li))
		return size;

	while(li != NULL)
	{
		size++;
		li = li->next;
	}

	return size;
}

/*---------------------------------------------------------------------*/

/**
* Ajoute un entier en fin de Liste
* @param li La liste
* @param x L'entier � ins�rer
* @return La liste avec le nouvel �lement ajout�
*/
List push_back_list(List li, int x)
{
	ListeElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = NULL;

	if(is_empty_list(li))
		return element;

	ListeElement *temp;
	temp = li;

	while(temp->next != NULL)
		temp = temp->next;

	temp->next = element;

	return li;
}

/*---------------------------------------------------------------------*/

/**
* Ajoute un entier en d�but de Liste
* @param li La liste
* @param x L'entier � ins�rer
* @return La liste avec le nouvel �lement ajout�
*/
List push_front_list(List li, int x)
{
	ListeElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;

	if(is_empty_list(li))
		element->next = NULL;
	else
		element->next = li;

	return element;
}

/*---------------------------------------------------------------------*/

/**
* Supprime un entier de la fin de la Liste
* @param li La liste
* @return La liste sans l'�l�ment retir�
*/
List pop_back_list(List li)
{
	if(is_empty_list(li))
		return new_list();

	//Si la liste n'a qu'un seul �l�ment
	if(li->next == NULL)
	{
		free(li);
		li = NULL;

		return new_list();
	}

	ListeElement *temp = li;
	ListeElement *before = li;

	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}

	before->next = NULL;

	free(temp);
	temp = NULL;

	return li;
}

/*---------------------------------------------------------------------*/

/**
* Supprime un entier de la t�te de la Liste
* @param li La liste
* @return La liste sans l'�l�ment retir�
*/
List pop_front_list(List li)
{
	ListeElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	if(is_empty_list(li))
		return new_list();

	element = li->next;

	free(li);
	li = NULL;

	return element;
}

/*---------------------------------------------------------------------*/

/**
* Supprime tous les �l�ments d'une Liste
* @param li La liste
* @return Une Liste vide
*/
List clear_list(List liste)
{
	if(is_empty_list(liste))
		return new_list();

	while(liste != NULL)
		liste = pop_front_list(liste);

	return liste;
}
