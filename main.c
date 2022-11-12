#include <stdio.h>
#include <stdlib.h>
#include "list.c"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	

/*------------------------------------------------------------------------*/

	
/*-------------Le main de la structure de donn�es List Chain�s------------*/

	
	 
	ListeElement *liste;
	
	liste= new_list();
	print_list(liste);
	liste= push_front_list(liste,20);
	liste= push_back_list(liste,10);
	liste= push_front_list(liste,45);
	liste= push_back_list(liste,50);
	printf("L'ajoout a été effectué avec succès\n");

	print_list(liste);

	
	
		
	
	
	return 0;
}
