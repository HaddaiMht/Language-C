	#include <stdio.h>
	#include <stdlib.h>
	/* D�finition d'une File */
	typedef struct QueueElement
	{
		int value;
		struct QueueElement *next;
	}QueueElement, *Queue;
	
	typedef enum Booleen {
		false,
		true
		
	}Bool;

/*------------------------------------------------------------------------*/

	/* Param�tres de la File */
	static QueueElement *first = NULL;
	static QueueElement *last = NULL;
	static int nb_elements = 0;
	
	Bool is_empty_queue(void)
	{
		if(first == NULL && last == NULL)
			return true;
	
		return false;
	}
/*------------------------------------------------------------------------*/
	
	/* Affiche une File*/
	void print_queue(void)
	{
		if(is_empty_queue())
		{
			printf("Rien a afficher, la File est vide.\n");
			return;
		}
	
		QueueElement *temp = first;
		printf("Les elements de la liste : \n");
		while(temp != NULL)
		{
			printf("[%d] ", temp->value);
			temp = temp->next;
		}
		printf("\n");
}

/*------------------------------------------------------------------------*/

	
	/**
* Ins�re un entier dans une File
* @param x L'entier � ajouter
*/
void push_queue(int x)
{
	QueueElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = NULL;

	if(is_empty_queue())
	{
		first = element;
		last = element;
	}
	else
	{
		last->next = element;
		last = element;
	}

	nb_elements++;
}
	
	
/*------------------------------------------------------------------------*/

/**
* Retire un �l�ment de la File
*/
void pop_queue(void)
{
	if(is_empty_queue())
	{
		printf("Rien a retirer, la File est deja vide.\n");
		return;
	}

	QueueElement *temp = first;

	if(first == last)
	{
		first = NULL;
		last = NULL;
	}
	else
		first = first->next;

	free(temp);
	nb_elements--;
}
