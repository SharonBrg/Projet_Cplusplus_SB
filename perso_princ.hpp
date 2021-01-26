/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier header de la classe PersoPrinc*/

#pragma once
#include <iostream>
#include "perso.hpp"

class PersoPrinc: public Perso{
	private:
		int pv;
		bool attaque_ok;

	public:
		//Constructeurs
		PersoPrinc():Perso(),pv(5000){}
		PersoPrinc(int pos_x,int pos_y):Perso(pos_x,pos_y),pv(5000){}

		//Accesseurs
		int get_pv()const{return pv;}
		void set_pv(){pv--;}
		int get_attaque_ok()const{return attaque_ok;}
		void set_attaque_ok(int val){attaque_ok=val;}

		// Fonction pour attaquer un ennemi
		void attaque(){attaque_ok=1;};


};