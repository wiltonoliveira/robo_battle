#include <stdio.h>
#include <stdlib.h>

void arena ();
void imprimir_robo ();



int main()
{
	//arena ();
	imprimir_robo ();
}

void arena (){
	int arena[20][20];
	int i, j;

	for (i = 0; i < 20; i++){
		for (j = 0; j < 20; j++)
			printf("|____|");
		
		printf("\n");
	}
}

void imprimir_robo (){

	printf ("%c\n", 219);
}