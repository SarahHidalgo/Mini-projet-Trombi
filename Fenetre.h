#pragma once

#include<string>
#include <SFML/Graphics.hpp>

#include "Groupe_TD.h"
#include "Etudiants.h"
#include "Portrait.h"

using namespace sf;
using namespace std;

// Créer par Marie FRT et Sarah HDG
class Fenetre
{
	string nom_fenetre_; // Nom de la fenetre qui va être display
public:
	Fenetre(string lettre_gr); // constructeur par defaut de la classe Fenetre
	const string& getNom() const { return nom_fenetre_; };
	void afficherFenetreGroupe(ofstream& ofs, Portrait portrait, string lettre_groupe, Groupe_TD Groupe_A, Groupe_TD Groupe_B, Groupe_TD Groupe_C, Groupe_TD Groupe_D, Groupe_TD Groupe_E);
	//affichage du groupe de TD entrer par l'utilisateur
	void afficherFenetre(Groupe_TD groupe, Portrait portrait, ofstream& ofs); // affichage de la fenetre en fonction d'un groupe de TD
};