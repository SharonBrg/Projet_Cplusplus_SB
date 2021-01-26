/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier header de la classe Pic*/

#pragma once
#include <iostream>
#include "obstacle.hpp"

class Pic: public Obstacle{
	public:
		//Constructeur
		Pic(int x_pos,int y_pos):Obstacle(x_pos,y_pos){}

		//Fonction pour blesser le personnage principal
		void blesser(PersoPrinc& p){p.set_pv();}
};