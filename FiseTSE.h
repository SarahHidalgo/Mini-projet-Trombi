#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class FiseTSE 
{
	string nom_fichier_, nom_fise_, choix_groupe_;
	vector<string> numero_, username_, nom_, prenom_, groupe_TD_, image_;
public:
	FiseTSE(string nom_fise = " ", string lien = " ");
	void afficher();
	const string& getNom() const { return nom_fise_; };
	const string& getLink() const { return nom_fichier_; };
	const string& getChoixGroupe() const { return choix_groupe_; };
	string afficherInfosVecteurs(string nom_vecteur, int i);
	void choixFise();
	void decoupageInfosEtudiants(string nom_fichier);

};
