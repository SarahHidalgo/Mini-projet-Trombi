#pragma once

#include<string>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class Portrait 
{
	string nom_;
	Sprite sprite_;
public:
	Portrait();
	void SetNom(string dodo) { nom_ = dodo; };
	void afficherImage(RenderWindow&, int position_x, int position_y);
};