/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier header de la classe Perso*/

#pragma once
#include <iostream>

class Perso{
	protected:
		int tab_pos[4]; // x_start,x_end,y_start,y_end
		int w,l;
	public:
		//Constructeurs et Déconstructeur
		Perso();
		Perso(int pos_x,int pos_y);
		~Perso(){}

		//Surcharge d'opérateur
		int operator()(int i)const{return tab_pos[i];} // 4 fonctions en 1 + moins chiant que vec à manipuler

		//Fonctions virtual, redéfinies dans d'autres classes qui héritent de persos
		virtual int get_deplacement()const{return 1;}
		virtual int gauche();
		virtual int droite();

		//Fonctions basiques pour le personnage
		int saut();
		int baisser();

};