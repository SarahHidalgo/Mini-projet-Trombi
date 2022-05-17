#pragma once

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class FiseTSE
{
	string nom_fichier_, nom_fise_;
	vector<string> numero, username, nom, vector<string> prenom, vector<string> groupe_TD, vector<string> image
public:
	FiseTSE(string nom_fise = " ", string lien = " ");
	void afficher();
	const string& getNom() const { return nom_fise_; };
	const string& getLink() const { return nom_fichier_; };
	void choixFise();
	void decoupageInfosEtudiants(string nom_fichier, vector<string> numero, vector<string> username, vector<string> nom, vector<string> prenom, vector<string> groupe_TD, vector<string> image);

};
