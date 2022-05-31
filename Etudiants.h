#pragma once

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// Créée par Sarah HDG
class Etudiant 
{
	string nom_, username_, prenom_, groupe_TD_, image_; 
	bool present_; // bool qui indique la présence de l'élève
	int numero_; //num d'identification de l'etudiant dans le fichier
public:
	Etudiant(string nom = " ", string username = " ", string prenom = " ", string groupe_TD = " ", string image = " ", int numero=0, bool present=false);
	//constructeur de la classe étudiant
	void afficher(); //afficher les paramètres de l'étudiants sur la console
	const string& getImage()const { return image_; };
	const string getNom() { return nom_; };
	void setPresence(bool presence) { present_ = presence; } // modifie le booléen present_ 
	const string getPrenom() { return prenom_; };
	void sauver(ofstream& ofs) const; // sauvegarder les parametres de l'etudiants dans un fichier
	//void charger(ifstream& ifs);
};
