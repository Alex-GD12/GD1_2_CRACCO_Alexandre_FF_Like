#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

	//Variable
    int ptsVieMonstre = 200;
	int ptsVieJoueur = 200;
	int pmMonstre = 50;
	int pmJoueur = 50;
	int action;
	int actionMonstre;
	int tamponDefJoueur = 0;
	int tamponDefMonstre = 0;
	int tamponPoisonJoueur = 0;
	int tamponPoisonMonstre = 0;

	
	//Fonction randomint a = 0;
	int a = 0;
	int b = 100;
	int rand_a_b(int a, int b){
		return rand()%(b-a) +a;
	}

	//-------------------------------------------------------------------

	//Début
	
	printf("\nUn gluant vous attaque !\n");
	
	
	while (ptsVieMonstre > 0 && ptsVieJoueur > 0){
		
		//TOUR JOUEUR
		
		//dégats poison
		if (tamponPoisonJoueur == 1){
			ptsVieJoueur -= 10;
		}
		
		
		//Affichage des PV et PM du joueur
		printf("\nVous: %d/200 PV \n",ptsVieJoueur);
		printf("Vous: %d/50 PM \n",pmJoueur);
		
		// Reinitialisation tamponDefJoueur
		tamponDefJoueur = 0;
		
		// Recup Mana
		if (pmJoueur < 50){
			pmJoueur = pmJoueur + 1;
		}
		
		//Choix des actions disonibles
		printf("\nQue faites-vous ?\n");
		printf(" 1: attaque  2: defense 3: poison 4: Antidote\n");
		scanf("%d", &action);
		
		//Atq
		if (action == 1){
			printf("Vous frappez le monstre avec votre epee.\n");
			if (tamponDefMonstre == 1){
				ptsVieMonstre -= 20/4;
			}else{
				ptsVieMonstre -= 20;
			}
		}
		
		//Def
		if (action == 2){
			tamponDefJoueur = 1;
			printf("Vous vous mettez en position de defense.\n");
			}
		
		//Poison
		if (action == 3){
			if(pmJoueur > 4){
				printf("vous empoisonnez le gluant!\n");
				tamponPoisonMonstre = 1;
				pmJoueur -= 5;
			}else{
				printf("\nLe sort echoue...\n");
			}
		
		}
		
		//Antidote
		if (action == 4){
			if(pmJoueur > 4){
				printf("Vous utilisez un sort d'Antidote : le poison disparait!\n");
				tamponPoisonJoueur = 0;
				pmJoueur -= 5;
			}else{
				printf("\nLe sort echoue...\n");
			}
		}
		
		
		printf("\n----------------------------------------------------\n");
		
		//TOUR GLUANT
		
		//dégats poison
		if (tamponPoisonMonstre == 1){
			ptsVieMonstre -= 10;
		}
		
		
		//Affichage des PV et PM du gluant
		printf("\ngluant: %d/200 PV \n",ptsVieMonstre);
		printf("gluant: %d/50 PM \n",pmMonstre);
		
		// Reinitialisation tamponDefMonstre
		tamponDefMonstre = 0;
		
		// recup mana
		if (pmMonstre < 50){
			pmMonstre = pmMonstre + 1;
		}
		
		// Jet aleatoire de l'action
		actionMonstre = rand_a_b(a, b);
	
		// Atq Gluant
		if (action < 44){
			printf("\nLe gluant attaque!\n");
			if (tamponDefJoueur == 1){
				ptsVieJoueur -= 20/4;
			}else{
				ptsVieJoueur -= 20;
			}
		}
		
		//def
		if (action > 45 && action < 79){
			tamponDefMonstre = 1;
			printf("Le gluant se défend.\n");
		}
		
		//Sort
		if(action > 80 && pmMonstre >= 5){
			if (tamponPoisonMonstre != 1){
				//poison
				if(tamponPoisonJoueur == 0){
					printf("Le gluant vous empoisonne!\n");
					tamponPoisonJoueur = 1;
					pmMonstre -= 5;
				}else{
					printf("\nLe gluant vous observe...");
				}
			}else{
				//antidote
				printf("Le gluant lance un sort d'Antidote : le poison disparait!\n");
				tamponPoisonMonstre = 0;
				pmMonstre -= 5;
			}
		}else{
			if(action > 80 && pmMonstre < 5){
				printf("\nLe gluant vous observe...");
			}
		}
		
		
		printf("\n----------------------------------------------------\n");
	}	
	//Fin
}