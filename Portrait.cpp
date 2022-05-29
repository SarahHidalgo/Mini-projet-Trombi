#include"Portrait.h"
#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

Portrait::Portrait()
{
	nom_ = "img";
}


void Portrait::afficherImage(RenderWindow& window, int x, int y)
{
	Texture texture;

	if (!texture.loadFromFile((string)"Trombino-FISE1/" += nom_))
	{
		cout << "erreur" << endl;
	}
	sprite_.setTexture(texture);
	sprite_.setPosition(x, y);
	window.draw(sprite_);
}