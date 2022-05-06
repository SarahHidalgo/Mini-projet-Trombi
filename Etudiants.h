#pragma once

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Etudiant
{
	string Nom_, Username_, Prenom_, Groupe_TD_, Fichier_;
	int Numero_;
public:
	Etudiant(string nom = " ", string Username = " ", string Prenom = " ", string Groupe_TD = " ", string Fichier = " ", int Numero=0);
	void afficher();
};
