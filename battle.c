#include <stdio.h>
#include <stdlib.h>

#define TAM 20

void arena ();
void imprimir_robo ();



int main()
{
	arena ();
	
}

void arena (){
	int arena[TAM][TAM];
	int i, j;

	for (i = 0; i <= TAM; i++){
		for (j = 0; j <= TAM; j++)
			if (i == 0 || j == 0 || i == 20 || j == 20)
				printf (".");
			else
				printf (" ");
			
		printf ("\n");
	}
}

void imprimir_robo (){
	
	printf ("%c", 219);printf ("%c", 219);printf ("%c\n", 219);
	printf ("%c", 219);printf ("%c", 219);printf ("%c", 219); printf ("%c", 219);printf ("%c\n", 219);
	printf ("%c", 219);printf ("%c", 219);printf ("%c", 219);printf ("%c", 219);printf ("%c\n", 219);
	printf ("%c", 219);printf ("%c", 219);printf ("%c\n", 219);
}
