#pragma once

#include<string>
#include <SFML/Graphics.hpp>
#include "Groupe_TD.h"
#include "Etudiants.h"

using namespace sf;
using namespace std;

// Créée par Marie FRT, 1 méthode ajoutée par Sarah
class Portrait
{
	string nom_; // nom de l'image a ajouter a la texture .png
	Sprite sprite_; 
public:
	Portrait();
	void SetNom(string dodo) { nom_ = dodo; }; // modifie le nom de l'image mettre dans la texture
	void afficherImage(RenderWindow&, int position_x, int position_y, bool fleche); // fonction qui draw une image
	void afficherText(string prenom, string nom, RenderWindow&, int x, int y); // fonction qui draw un texte
};