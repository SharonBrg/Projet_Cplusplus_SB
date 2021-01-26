/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier header de la classe Plateformer*/

#pragma once
#include <iostream>
#include <vector>
#include "perso.hpp"
#include "obstacle.hpp"
#include "pic.hpp"
#include "perso_princ.hpp"
#include "ennemis.hpp"
#include "carotte.hpp"
#include "chat.hpp"
#include <SFML/Graphics.hpp>

class Plateformer{
	private:
		Perso perso_princ;
		//Vecteurs pour ranger les éléméents du jeu
		std::vector<Obstacle> vec_obstacle;
		std::vector<Pic> vec_pic;
		std::vector<Carotte> vec_carotte;
		std::vector<Chat> vec_chat;

		//Vecteurs pour garder les éléments graphiques
		std::vector<sf::Sprite> vec_sprite_carotte;
		std::vector<sf::Sprite> vec_sprite_chat;
		std::vector<sf::Sprite> vec_sprite_obstacle;
		std::map<std::string,sf::Texture> map_textures;
		int fin_carotte;
		int fin_chat;

	public:
		//Constructeur
		Plateformer(Perso& p);

		//Vérifier les interactions entre les objets du jeu
		void contact_obstacle(Perso& p,int* dir);
		void contact_pic(PersoPrinc& p);
		void contact_ennemis(PersoPrinc& p, int i);
		template<typename T>
		int contact(PersoPrinc& p, T& it,int i);

		//Accesseurs
		void set_vec_carotte(Carotte& obj);
		void set_vec_chat(Chat& obj);
		void set_vec_obstacle(Obstacle& obj,int i);
		void set_vec_pic(Pic& obj){vec_pic.push_back(obj);}

		//Fonction à utiliser pour savoir si c'est la fin du jeu ou non
		int get_fin_carotte()const{return fin_carotte;}
		int get_fin_chat()const{return fin_chat;}

		//Fonction pour faire avancer les ennemis dans la fenêtre
		//template<typename T>
		//void avancer_perso(T& it,sf::Sprite it_s);
		//void avancer_ennemis(int i);

		//Dessiner les éléments du jeu
		void draw(sf::RenderWindow& window);
	
};

// Template

template<typename T>
int Plateformer::contact(PersoPrinc& p, T& it,int i){
	int fin=0;
	//Vérification des coordonnées des deux objets (p et it)
	if( (*it)(2,p(2)) || (*it)(2,p(3)) || (p(2)<(*it)(2) && p(3)>(*it)(3))){
		if((*it)(0,p(0)-i) || (*it)(0,p(1)+i)){
			if(i){
				/*Vérification qu'attaque n'est pas lancée par le personnage principal*/
				if(p.get_attaque_ok()){
					fin++;
				}
			}
			/*Si l'autre élément n'a pas été attaqué par le personnage principal alors il l'attaque*/
			else if(!i || !fin)
				it->blesser(p);
		}		
	}

	if((*it)(0,p(0)) || (*it)(0,p(1)) || (p(0)>(*it)(0) && p(1)<(*it)(1))){
		if( (*it)(2,p(2)-i) || (*it)(2,p(3)+i) ){
			if(i){
				if(p.get_attaque_ok()){
					fin++;
				}
			}
			else if(!i || !fin)
				it->blesser(p);
		}
	}
	return fin;
}

/*template<typename T>
void Plateformer::avancer_perso(T& it,sf::Sprite it_s){
	int dir[4]={0},succes;

	//On regarde les directions possubles des ennemis
	this->contact_obstacle(it,dir);

	//Mise à jour des sprite
	if(!dir[0]){
		succes=(*it).gauche();
		if(succes){
			it_s.move(sf::Vector2f(-((*it).get_deplacement()), 0.f));
	}
	else if(!dir[1]){
		succes=(*it).droite();
		if(succes)
			it_s.move(sf::Vector2f(((*it).get_deplacement()), 0.f));
	}
	else if(!dir[2]){
		succes=(*it).saut();
		if(succes)
			it_s.move(sf::Vector2f(0.f, -((*it).get_deplacement())));
	}
	else if(!dir[3]){
		succes=(*it).baisser();
		if(succes)
			it_s.move(sf::Vector2f(0.f, ((*it).get_deplacement())));
	}	
}*/