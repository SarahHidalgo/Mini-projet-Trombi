#pragma once

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// Créée par Sarah HDG
class Etudiant 
{
	string nom_, username_, prenom_, groupe_TD_, image_; 
	int numero_; //num d'identification de l'etudiant dans le fichier
public:
	Etudiant(string nom = " ", string username = " ", string prenom = " ", string groupe_TD = " ", string image = " ", int numero=0);
	//constructeur de la classe étudiant
	void afficher(); //afficher les paramètres de l'étudiants sur la console
	const string& getImage()const { return image_; };
	const string getNom() { return nom_; };
	const string getPrenom() { return prenom_; };
	void sauver(ofstream& ofs) const; // sauvegarder les parametres de l'etudiants dans un fichier
	//void charger(ifstream& ifs);
};
