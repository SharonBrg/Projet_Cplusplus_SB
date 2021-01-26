/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier header de la classe Obstacle*/

#pragma once
#include <iostream>
#include "perso.hpp"
#include "perso_princ.hpp"

class Obstacle{
	public:
		//Constructeurs
		Obstacle();
		Obstacle(int pos_x,int pos_y);

		//Surcharge d'opérateurs
		bool operator()(int i,int j);
		int operator()(int i){return tab_pos[i];}

		//Accesseurs
		int get_touche()const{return touche;}
		void set_touche(int i){touche=i;}


	protected:
		int w,l;
		int tab_pos[4];
		int touche;
};