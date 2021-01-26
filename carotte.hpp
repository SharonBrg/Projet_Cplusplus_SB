/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier header de la classe Carotte*/

#pragma once
#include <iostream>
#include "ennemis.hpp"
#include "perso.hpp"

class Carotte: public Ennemis{
	public:
		//Constructeurs
		Carotte():Ennemis(){this->deplacement=4;};
		Carotte(int pos_x,int pos_y):Ennemis(pos_x,pos_y){this->deplacement=4;}

		//Fonction propre à carotte
		int get_deplacement()const{return deplacement;}
};