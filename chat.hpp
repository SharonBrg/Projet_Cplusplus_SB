/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier header de la classe Chat*/

#pragma once
#include <iostream>
#include "ennemis.hpp"

class Chat: public Ennemis{
	public:
		//Déclaration constructeur
		Chat(int x_pos,int y_pos):Ennemis(x_pos,y_pos){this->deplacement=2;}

};