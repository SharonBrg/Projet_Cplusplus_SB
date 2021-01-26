/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier source de la classe Plateformer*/

#include <iostream>
#include "plateformer.hpp"

//Constructeurs
Plateformer::Plateformer(Perso& p):perso_princ(p){
	sf::Texture motif_main,motif_block,motif_chat,motif_carotte,motif_trou,motif_pic;
    if (!motif_main.loadFromFile("Perso_essai_sprite_image/main_char.png"))
        std::cout<<"Oups! Probleme de chargement des images..."<<std::endl;
    map_textures["perso_princ"]=motif_main;
    if (!motif_block.loadFromFile("Perso_essai_sprite_image/block_essai.png"))
        std::cout<<"Oups! Probleme de chargement des images..."<<std::endl;
    map_textures["block"]=motif_block;
    if (!motif_chat.loadFromFile("Perso_essai_sprite_image/chat.png"))
        std::cout<<"Oups! Probleme de chargement des images..."<<std::endl;
    map_textures["chat"]=motif_chat;
    if (!motif_carotte.loadFromFile("Perso_essai_sprite_image/carrot.png"))
        std::cout<<"Oups! Probleme de chargement des images..."<<std::endl;
    map_textures["carotte"]=motif_carotte;
    if (!motif_pic.loadFromFile("Perso_essai_sprite_image/pic.png"))
        std::cout<<"Oups! Probleme de chargement des images..."<<std::endl;
    map_textures["pic"]=motif_pic;
}

//Fonction déterminant les directions que peut prendre le personnage sans rentrer dans un obstacle
void Plateformer::contact_obstacle(Perso& p,int* dir){
	int cpt=0;
	std::vector<Obstacle>::iterator it;
	for(it=vec_obstacle.begin();it!=vec_obstacle.end();it++){
		if( (*it)(2,p(2)) || (*it)(2,p(3)) || (p(2)<(*it)(2) && p(3)>(*it)(3))){
			if((*it)(0,p(0)-1)){
				dir[0]=1;
			}
			else if((*it)(0,p(1)+1)){
				dir[1]=1;
			}
		}
		if((*it)(0,p(0)) || (*it)(0,p(1)) || (p(0)>(*it)(0) && p(1)<(*it)(1))){
			if((*it)(2,p(2)-1)){
				dir[2]=1;
			}
			else if((*it)(2,p(3)+1)){
				dir[3]=1;
			}
		}

	}
}

//Méthode vérifiant le contact pour un pic en particulier
void Plateformer::contact_pic(PersoPrinc& p){
	std::vector<Pic>::iterator it;
	for(it=vec_pic.begin();it!=vec_pic.end();it++){
		this->contact(p,it,1);
	}

}

//Méthode vérifiant le contact entre le personnage principal et les ennemis du jeu
void Plateformer::contact_ennemis(PersoPrinc& p, int i){
	if(i){
		std::vector<Carotte>::iterator it;
		for(it=vec_carotte.begin();it!=vec_carotte.end();it++){
			if(contact(p,it,0))
				fin_carotte=1;
		}
	}
	else{
		std::vector<Chat>::iterator it;
		for(it=vec_chat.begin();it!=vec_chat.end();it++){
			if(contact(p,it,0))
				fin_chat=1;
		}
	}
}

// Ajout ayx listes
void Plateformer::set_vec_carotte(Carotte& obj){
	sf::Sprite sprite;
	sf::Texture motif;
	vec_carotte.push_back(obj);
	sprite.setPosition(sf::Vector2f(obj(0), obj(2)));
	sprite.setTexture(map_textures["carotte"]);
	vec_sprite_carotte.push_back(sprite);
}

void Plateformer::set_vec_chat(Chat& obj){
	sf::Sprite sprite;
	sf::Texture motif;
	vec_chat.push_back(obj);
	sprite.setPosition(sf::Vector2f(obj(0), obj(2)));
	sprite.setTexture(map_textures["chat"]);
	vec_sprite_chat.push_back(sprite);
}


void Plateformer::set_vec_obstacle(Obstacle& obj,int i){
	sf::Sprite sprite;
	sf::Texture motif;
	vec_obstacle.push_back(obj);
    sprite.setPosition(sf::Vector2f(obj(0), obj(2)));
    if(i)
    	sprite.setTexture(map_textures["block"]);
    else
    	sprite.setTexture(map_textures["pic"]);
    vec_sprite_obstacle.push_back(sprite);
}

//Fonction non opérationnelle pour faire avancer les personnages ennemis automatiquement
/*void Plateformer::avancer_ennemis(int i){
	if(i){
		std::vector<Carotte>::iterator it;
		std::vector<sf::Sprite>::iterator it_s=vec_sprite_carotte.begin();
		for(it=vec_carotte.begin();it!=vec_carotte.end();it++){
			this->avancer_perso(it,it_s);
			it_s++;
		}
	}
	else{
		std::vector<Chat>::iterator it;
		std::vector<sf::Sprite>::iterator it_s=vec_sprite_chat.begin();
		for(it=vec_chat.begin();it!=vec_chat.end();it++){
			this->avancer_perso(it,it_s);
			it_s++;
		}
	}
}*/

//Dessine les sprites des objets manipulés par plateforme à l'écran
void Plateformer::draw(sf::RenderWindow& window){
	std::vector<sf::Sprite>::iterator it_s;
	if(!fin_carotte)
		for(it_s=vec_sprite_carotte.begin();it_s!=vec_sprite_carotte.end();it_s++)
			window.draw(*it_s);
	if(!fin_chat)
		for(it_s=vec_sprite_chat.begin();it_s!=vec_sprite_chat.end();it_s++)
			window.draw(*it_s);
	for(it_s=vec_sprite_obstacle.begin();it_s!=vec_sprite_obstacle.end();it_s++)
		window.draw(*it_s);
}