/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier source de la classe Obstacle*/

#include <iostream>
#include "obstacle.hpp"


//Constructeurs
Obstacle::Obstacle():w(200),l(100){}

Obstacle::Obstacle(int pos_x,int pos_y):w(200),l(100){
	tab_pos[0]=pos_x; 
	tab_pos[1]=pos_x+w;
	tab_pos[2]=pos_y;
	tab_pos[3]=pos_y+l;
}

//Surcharge d'opérateur permettant de savoir si le j appartient à un intervalle entre deux coordonnées
bool Obstacle::operator()(int i,int j){
	if((j>=tab_pos[i]) && (j<=tab_pos[i+1]))
		return 1;
	else 
		return 0;
}

