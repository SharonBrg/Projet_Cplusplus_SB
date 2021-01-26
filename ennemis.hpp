/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier header de la classe Ennemis*/

#pragma once
#include <iostream>
#include "perso.hpp"
#include "perso_princ.hpp"

class Ennemis: public Perso{
	protected:
		int deplacement;
	public:
		//Constructeur
		Ennemis():Perso(){};
		Ennemis(int pos_x,int pos_y):Perso(pos_x,pos_y){}

		//Surcharge d'opérateur
		bool operator()(int i,int j);
		int operator()(int i)const{return this->tab_pos[i];}

		//Fonction pour blesser le persinnage principal
		void blesser(PersoPrinc& p);

		//Surcharge des fonctions de Perso
		int gauche();
		int droite();
};