#include <stdio.h>
#include <stdlib.h>

#define TAM_LIN 20
#define TAM_COL 40

void arena ();
void imprimir_robo ();


struct robo {
	float life;
	int ammo;
	int fuel;
	int range;
	

};

struct Estrategia {

};

struct Grupo {
	struct robo robo1;
	struct Estrategia estrategia1;
	
	struct robo robo2;
	struct Estrategia estrategia2;
	
	struct robo robo3;
	struct Estrategia estrategia3;
};

void robo_config (struct robo robo1, struct robo robo2, struct robo robo3);

int main()
{
	struct Grupo grupo;
	
	robo_config (grupo.robo1, grupo.robo2, grupo.robo3);
	
	//arena ();
	//imprimir_robo ();
}

void arena (){
	int arena[TAM_LIN][TAM_COL];
	int i, j;

	for (i = 0; i <= TAM_LIN; i++){
		for (j = 0; j <= TAM_COL; j++)
			if (i == 0 || i == TAM_LIN)
				printf ("_");
				
			else if (j == 0 || j == TAM_COL)
				printf ("|");
			
			else if (i == 10 && j == 5)
				imprimir_robo ();
				
			else
				printf (" ");
			
		printf ("\n");
	}
}

void imprimir_robo (){
	
	printf ("%c", 219);
}


void robo_config (struct robo robo1, struct robo robo2, struct robo robo3);{
	
}
