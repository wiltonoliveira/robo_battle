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
void arena (robos* robo, disparo* dis);
void imprimir_robo ();
void imprimir_disparo ();

void estrategia_corner (robos* corner);
void move_horse (robos* horse, int move_num);
void estrategia_hunter (robos* hunter);

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
	robos corner, horse, hunter;
	disparo dis1;
	
		
	inicia_robo (&corner);
	arena (&corner, &dis1);
	
}

void inicia_robo (robos* robo){
	robo->ammo = 100;
	robo->fuel = 100;
	robo->range = 2;
	robo->life = 100;
	
	robo->lin = 4;
	robo->col = 2;
}

void move_horse (robos* horse, int move_num){
	robos aux ;
	
	aux.lin = horse->lin;
	aux.col = horse->col;
	
	switch (move_num){
		case 1:{
			move_up (&aux);
			move_up (&aux);
			move_left (&aux);
			break;
		}
		case 2:{
			move_up (&aux);
			move_up (&aux);
			move_right (&aux);
			break;
		}
		
		case 3:{
			move_down (&aux);
			move_down (&aux);
			move_left (&aux);
			break;
		}
		case 4: {
			move_down (&aux);
			move_down (&aux);
			move_right (&aux);
			break;
		}
		case 5: {
			move_left (&aux);
			move_left (&aux);
			move_up (&aux);
			break;
		}
		case 6:{
			move_left (&aux);
			move_left (&aux);
			move_down (&aux);
			break;
		}
		case 7: {
			move_right (&aux);
			move_right (&aux);
			move_up (&aux);
			break;
		}
		case 8:{
			move_right (&aux);
			move_right (&aux);
			move_down (&aux);
			break;
		}
	}
	if (aux.lin <= 0 || aux.lin >= TAM_LIN || aux.col <= 0 || aux.col >= TAM_COL){
		move_horse (horse, move_num + 1);
	}
	else{
		horse->lin = aux.lin;
		horse->col = aux.col;
	}
		
}

void arena (robos* robo, disparo* dis){
	int i, j;
	
	
	
	for (i = 0; i <= TAM_LIN; i++){
		for (j = 0; j <= TAM_COL; j++)
			if (i == 0 || i == TAM_LIN)
				printf ("_");
				
			else if (j == 0 || j == TAM_COL)
				printf ("|");
			
			else if (i == robo->lin && j == robo->col)
						imprimir_robo ();
			
			else if (i == dis->lin && j == dis->col)
						imprimir_disparo ();
			
			else
				printf (" ");
				
			
		printf ("\n");
	}
	while (robo->col < (TAM_COL - 1) && robo->col > 1 && robo->lin > 1 && robo->lin < (TAM_LIN - 1)){
	diag_inf_dir(robo);
	arena (robo, dis);
	}
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
	printf ("*");
}


void imprimir_robo (){	
	printf ("%c", 219);
}
