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

struct Disparo {
	int lin, col;
	int direcao;
};
typedef struct Disparo disparo;

void inicia_robo (robos* robo);
void arena (robos* robo);
void imprimir_robo ();
void imprimir_disparo ();

void move_up (robos* robo);
void move_down (robos* robo);
void move_left (robos* robo);
void move_right (robos* robo);

void diag_sup_esq (robos* robo);
void diag_sup_dir (robos* robo);
void diag_inf_esq (robos* robo);
void diag_inf_dir (robos* robo);

void dis_up (disparo* dis);
void dis_down (disparo* dis);
void dis_left (disparo* dis);
void dis_right (disparo* dis);

void dis_sup_e (disparo* dis);
void dis_sup_d (disparo* dis);
void dis_inf_e (disparo* dis);
void dis_inf_d (disparo* dis);

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
		
			
			else
				printf (" ");
				
			
		printf ("\n");
	}
	system ("PAUSE");
	diag_inf_dir (robo);
	arena (robo);
	
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
	robo->col = robo->col + 1;
}
void diag_sup_esq (robos* robo){
	move_up (robo);
	move_left (robo);
}

void diag_sup_dir (robos* robo){
	move_up (robo);
	move_right (robo);
}

void diag_inf_esq (robos* robo){
	move_down (robo);
	move_left (robo);
}
void diag_inf_dir (robos* robo){
	move_down (robo);
	move_right (robo);
}

void dis_up (disparo* dis){
	dis->lin = dis->lin - 1;
}

void dis_down (disparo* dis){
	dis->lin = dis->lin + 1;
}

void dis_left (disparo* dis){
	dis->col = dis->col - 1;
}

void dis_right (disparo* dis){
	dis->col = dis->col + 1;
}

void dis_sup_e (disparo* dis){
	dis_up (dis);
	dis_left (dis);
}

void dis_sup_d (disparo* dis){
	dis_up (dis);
	dis_right (dis);
}

void dis_inf_e (disparo* dis){
	dis_down (dis);
	dis_left (dis);
}

void dis_inf_d (disparo* dis){
	dis_down (dis);
	dis_right (dis);
}



void imprimir_disparo (){
	printf (".");
}


void imprimir_robo (){	
	printf ("%c", 219);
}
