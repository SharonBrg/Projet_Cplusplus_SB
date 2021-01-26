/*BAURBERG Sharon Mini_Projet C++ 2020-2021 main source*/

#include "perso.hpp"
#include "perso_princ.hpp"
#include "obstacle.hpp"
#include "plateformer.hpp"
#include "pic.hpp"
#include <SFML/Graphics.hpp>

int main()
{
	//Init du jeu
    bool succes;
    int dir[4]={0};
   
    sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");
    PersoPrinc main_char(0,800);
    Plateformer jeu(main_char);
    Pic block(300,500);
    Obstacle block2(600,650);
    Carotte ennemi1(1500,800);
    Chat ennemi2(0,0);
    jeu.set_vec_obstacle(block,0);
    jeu.set_vec_pic(block);
    jeu.set_vec_obstacle(block2,1);
    jeu.set_vec_carotte(ennemi1);
    jeu.set_vec_chat(ennemi2);
    sf::Texture motif_main;
    motif_main.loadFromFile("Perso_essai_sprite_image/main_char.png");
    
    sf::Sprite sprite;
    sprite.setPosition(sf::Vector2f(0.f, 800.f));

    //Boucle infinie du jeu
    while (window.isOpen())
    {
    	//Verifier contact
    	jeu.contact_obstacle(main_char,dir);
    	jeu.contact_pic(main_char);
    	
    	//Evenement graphique
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            succes=main_char.gauche();
            if(succes && !dir[0])
            	sprite.move(sf::Vector2f(-1.f, 0.f));
            else if(dir[0])
            	main_char.droite();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
           	succes=main_char.droite();
           	if(succes && !dir[1]){
           		sprite.move(sf::Vector2f(1.f, 0.f));
           	}
           	else if(dir[1])
           		main_char.gauche();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
           	succes=main_char.saut();
           	if(succes && !dir[2])
               	sprite.move(sf::Vector2f(0.f, -1.f));
            else if(dir[2])
            	main_char.baisser();
	    }
    	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            succes=main_char.baisser();
           	if(succes && !dir[3])
               	sprite.move(sf::Vector2f(0.f, 1.f));
            else if(dir[3])
            	main_char.saut();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        	main_char.attaque();
        }        
        for(int i=0; i<4;i++)
        	dir[i]=0;

        //Conditions de fin de jeu
        if(!jeu.get_fin_carotte())
        	jeu.contact_ennemis(main_char, 1); //Carotte
        if(!jeu.get_fin_chat())
        	jeu.contact_ennemis(main_char, 0); //Chat

        //Fonctions pour faire avancer les personnages ennemis (problèmes de compilation)
        //jeu.avancer_ennemis(1); // Carotte
        //jeu.avancer_ennemis(0); // Chat
        sprite.setTexture(motif_main);
        
        //Mise à jour de l'écran
        window.clear();
        window.draw(sprite);
        jeu.draw(window);
        window.display();

        //Vérification si fin de jeu
        if(jeu.get_fin_carotte() && jeu.get_fin_chat()){
        	window.close();
        	std::cout<<"Vous avez gagne!"<<std::endl;
        }
        if(main_char.get_pv()<=0){
        	window.close();
        	std::cout<<"Vous avez perdu!"<<std::endl;
        }
    }

    return 0;
}