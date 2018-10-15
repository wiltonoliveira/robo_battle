#include <stdio.h>
#include <stdlib.h>

#define TAM_LIN 20
#define TAM_COL 40

void arena ();
void imprimir_robo ();
int move_up (struct Robo robo);
//void move_down (struct Robo robo);
//void move_left (struct Robo robo);
//void move_right (struct Robo robo);

struct Robo {
	float life;
	int ammo;
	int fuel;
	int range;
	
	int lin, col;
};



struct Estrategia {
	int a;
};





int main()
{
	
	
	
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



int move_up (struct Robo robo) {
	robo.col = robo.col - 1;
	
	return robo.col;
}

/*
void move_down (struct Robo robo){
	robo.col = robo.col + 1;
}

void move_left (struct Robo robo){
	robo.lin = robo.lin + 1
}

void move_right (struct Robo robo){
	robo.lin = robo.lin - 1;
}
*/
