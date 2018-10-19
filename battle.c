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

void inicia_robo (robos* corner, robos* horse, robos* hunter);
void arena (robos* corner, robos* horse, robos* hunter);
void imprimir_robo ();
void imprimir_disparo ();

int valida_posicao (robos robo);

void move_corner (robos* corner, int move_num);
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
	
		
	inicia_robo (&corner, &horse, &hunter);
	arena (&corner, &horse, &hunter);
	
}

void inicia_robo (robos* corner, robos* horse, robos* hunter){
	hunter->ammo = 100;
	hunter->fuel = 100;
	hunter->life = 100;
	hunter->range = 2;
	
	hunter->lin = 4;
	hunter->col = 2;

	corner->ammo = 150;
	corner->fuel = 100;
	corner->life = 100;
	corner->range = 4;

	corner->lin = 1;
	corner->col = 1;

	horse->ammo = 100;
	horse->fuel = 100;
	horse->life = 100;
	horse->range = 3;

	horse->lin = 6;
	horse->col = 9;
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

void move_corner (robos* corner, int move_num){
		
	switch (move_num){
		case 1: {
			move_up (corner);
		}
		case 2: {
			move_down(corner);
		}
		case 3: {
			move_left (corner);
		}
		case 4: {
			move_right (corner);
		}
}

	/*
	if (corner->lin < (TAM_LIN / 2) && corner->col < (TAM_COL / 2)){
		move_up (&aux);
		move_left (&aux);
	}
	else if (corner->lin < (TAM_LIN / 2) && corner->col > (TAM_COL / 2)){
			move_up (&aux);
			move_right (&aux);
	}
	else if (corner->lin > (TAM_LIN / 2) && corner-> col < (TAM_COL / 2)){
		move_down (&aux);
		move_left (&aux);
	}
	else if (corner->lin > (TAM_LIN / 2) && corner-> col > (TAM_COL / 2)){
		move_down (&aux);
		move_right (&aux);
	}
	
	teste = valida_posicao (aux);
	
	if (teste == 0)
	*/
}

int valida_posicao (robos robo){
	
	if (robo.lin <= 0 || robo.lin >= TAM_LIN || robo.col <= 0 || robo.col >= TAM_COL)
		return 0;
	
	else
		return 1;
}

void arena (robos* corner, robos* horse, robos* hunter){
	int i, j;
	
	
	
	for (i = 0; i <= TAM_LIN; i++){
		for (j = 0; j <= TAM_COL; j++)
			if (i == 0 || i == TAM_LIN)
				printf ("_");
				
			else if (j == 0 || j == TAM_COL)
				printf ("|");
			
			else if (i == corner->lin && j == corner->col || i == horse->lin && j == horse->col || i == hunter->lin && j == hunter->col)
						imprimir_robo ();
			
			
			
			else
				printf (" ");
				
			
		printf ("\n");
	}
	if (corner->life > 0){
		if (corner->lin == 1 && corner->col < (TAM_COL - 1))
			move_corner (corner, 4);
		
		else if (corner->lin < (TAM_LIN - 1) && corner->col == (TAM_COL - 1))
				move_corner (corner, 2);

		else if (corner->lin == (TAM_LIN - 1) && corner->col > 1)
				move_corner (corner, 3);
	
		else if (corner->lin > 1 && corner->col == 1)
				move_corner (corner, 1);

	}
	getchar();
	arena (corner, horse, hunter);
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
