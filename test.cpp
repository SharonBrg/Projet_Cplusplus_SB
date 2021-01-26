/*BAURBERG Sharon Mini_Projet C++ 2020-2021 fichier source test unitaire*/

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "perso.hpp"
#include "perso_princ.hpp"
#include "obstacle.hpp"
#include "plateformer.hpp"
#include "chat.hpp"
#include "carotte.hpp"
#include "ennemis.hpp"
#include "pic.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>                        
#include <string>
 

TEST_CASE("1: Creation d'objet")
{
  PersoPrinc joueur(500,500);
  Plateformer jeu(joueur);
  REQUIRE(joueur(0)==500);
  REQUIRE(joueur(2)==500);
}

TEST_CASE("2: Directions possibles")
{
  int dir[4]= {0};
  PersoPrinc joueur(500,300);
  Plateformer jeu(joueur);
  Obstacle block(500,501);
  jeu.set_vec_obstacle(block,1);
  jeu.contact_obstacle(joueur,dir);
  REQUIRE(dir[3]==1);
}



TEST_CASE("3: Perte de PV")
{
  PersoPrinc joueur(500,500);
  Plateformer jeu(joueur);
  int pv=joueur.get_pv();
  Carotte carotte(500,500);
  carotte.blesser(joueur);
  REQUIRE(joueur.get_pv()==pv-1);

}
