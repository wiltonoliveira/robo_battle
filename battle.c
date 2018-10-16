#include <stdio.h>
#include <stdlib.h>

#define TAM_LIN 20
#define TAM_COL 60

struct Robo {
	float life;
	int ammo;
	int fuel;
	int range;
	
	int lin, col;
};
typedef struct Robo robos;

void inicia_robo (robos* robo);
void arena (robos* robo);
void imprimir_robo ();

void move_up (robos* robo);
void move_down (robos* robo);
void move_left (robos* robo);
void move_right (robos* robo);

int main()
{	
	struct Robo robo1;
	
	inicia_robo (&robo1);
	arena (&robo1);
	//imprimir_robo ();
}

void inicia_robo (robos* robo){
	robo->ammo = 100;
	robo->fuel = 100;
	robo->range = 2;
	robo->life = 100;
	
	robo->lin = 4;
	robo->col = 2;
}

void move_up (robos* robo){
	robo->lin = robo->lin - 1;
}

void move_down (robos* robo){
	robo->lin = robo->lin + 1;
}

void move_left (robos* robo){
	robo->col = robo->col - 1;
}

void move_right (robos* robo){
	robo->lin = robo->lin + 1;
}

void arena (robos* robo){
	int i, j;

	for (i = 0; i <= TAM_LIN; i++){
		for (j = 0; j <= TAM_COL; j++)
			if (i == 0 || i == TAM_LIN)
				printf ("_");
				
			else if (j == 0 || j == TAM_COL)
				printf ("|");
			
			else if (i == robo->lin && j == robo->col)
						imprimir_robo ();
			/*
				else if (i == 10 && j == 5)
					imprimir_robo ();
			*/	
			else
				printf (" ");
				
			
		printf ("\n");
	}
	
}

void imprimir_robo (){
	
	printf ("%c", 219);
}
