#pragma once

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// Cr��e par Sarah HDG
class Etudiant 
{
	string nom_, username_, prenom_, groupe_TD_, image_; 
	bool present_; // bool qui indique la pr�sence de l'�l�ve
	int numero_; //num d'identification de l'etudiant dans le fichier
public:
	Etudiant(string nom = " ", string username = " ", string prenom = " ", string groupe_TD = " ", string image = " ", int numero=0, bool present=false);
	//constructeur de la classe �tudiant
	void afficher(); //afficher les param�tres de l'�tudiants sur la console
	const string& getImage()const { return image_; };
	const string getNom() { return nom_; };
	void setPresence(bool presence) { present_ = presence; } // modifie le bool�en present_ 
	const string getPrenom() { return prenom_; };
	void sauver(ofstream& ofs) const; // sauvegarder les parametres de l'etudiants dans un fichier
	//void charger(ifstream& ifs);
};
