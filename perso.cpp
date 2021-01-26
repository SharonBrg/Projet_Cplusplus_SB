/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier source de la classe Perso*/

#include <iostream>
#include "perso.hpp"

//Constructeurs
Perso::Perso():w(127),l(201){
	
}

Perso::Perso(int pos_x,int pos_y):w(127),l(201){
	tab_pos[0]=pos_x;
	tab_pos[1]=pos_x+w;
	tab_pos[2]=pos_y;
	tab_pos[3]=pos_y+l;
}


//Déclaration des fonctions basiques pour déplacer le personnage
int Perso::gauche(){
	if(tab_pos[0]>0){
		tab_pos[0]--;
		tab_pos[1]--;
		return 1;
	}
	else 
		return 0;
}

int Perso::droite(){
	if(tab_pos[1]<1940){
		tab_pos[0]++;
		tab_pos[1]++;
		return 1;
	}
	else 
		return 0;
}

int Perso::saut(){
	if(tab_pos[2]>0){
		tab_pos[2]--;
		tab_pos[3]--;
		return 1;
	}
	else
		return 0;
}
		


int Perso::baisser(){
	if(tab_pos[3]<1000){
		tab_pos[2]++;
		tab_pos[3]++;
		return 1;
	}
	else
		return 0;
}