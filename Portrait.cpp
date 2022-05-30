#include"Portrait.h"
#include "Groupe_TD.h"

#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

Portrait::Portrait()
{
	nom_ = "img";
}

void Portrait::afficherImage(RenderWindow& window, int x, int y, bool fleche)
{
	Texture texture;

	if (!texture.loadFromFile((string)"Trombino-FISE1/" += nom_))
	{
		cout << "erreur" << endl;
	}
	sprite_.setTexture(texture);
	if (fleche==true)
		sprite_.setTextureRect(IntRect(0, 0, 50, 50)); // permet de redimmensionner le sprite pour les flèches qui sont plus petites
	sprite_.setPosition(x, y);
	window.draw(sprite_);
}

// Affichage du nom et prenom en dessous de la photo
void Portrait::afficherText(string prenom, string nom, RenderWindow& window, int x, int y)
{
	Text text;
	Font font;
	font.loadFromFile("Quicksand-Regular.otf");
	text.setString(L"éèàçÉëêî");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::Black);
	text.setString(nom); // ecriture du nom
	text.setPosition(x, y); // position du nom
	window.draw(text);
	text.setString(prenom); //ecriture du prenom
	text.setPosition(x, y + 30); // positionnement du prenom
	window.draw(text);
}