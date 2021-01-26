/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier source de la classe Ennemis*/

#include <iostream>
#include "ennemis.hpp"

//Surcharge d'opéarteurs
bool Ennemis::operator()(int i,int j){
	if((j>=tab_pos[i]) && (j<=tab_pos[i+1]))
		return 1;
	else 
		return 0;
}

//Fonction pour blesser le personnage principal
void Ennemis::blesser(PersoPrinc& p){
	p.set_pv();
}


// Surcharge des fonctions gauche et droite par rapport à Perso
int Ennemis::gauche(){
	if(tab_pos[0]>deplacement){
		tab_pos[0]-=deplacement;
		tab_pos[1]-=deplacement;
		return 1;
	}
	else 
		return 0;
}

int Ennemis::droite(){
	if(tab_pos[1]<1940-deplacement){
		tab_pos[0]+=deplacement;
		tab_pos[1]+=deplacement;
		return 1;
	}
	else 
		return 0;
}

