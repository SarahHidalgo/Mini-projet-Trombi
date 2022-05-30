#pragma once

#include<string>
#include <SFML/Graphics.hpp>

#include "Groupe_TD.h"
#include "Etudiants.h"
#include "Portrait.h"

using namespace sf;
using namespace std;


class Fenetre
{
	string nom_fenetre_;
public:
	Fenetre(string lettre_gr);
	const string& getNom() const { return nom_fenetre_; };
	void afficherFenetreGroupe(Portrait portrait, string lettre_groupe, Groupe_TD Groupe_A, Groupe_TD Groupe_B, Groupe_TD Groupe_C, Groupe_TD Groupe_D, Groupe_TD Groupe_E);
	void afficherFenetre(Groupe_TD groupe, Portrait portrait);
};