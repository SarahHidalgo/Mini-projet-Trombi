#pragma once

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Etudiant
{
	string nom_, username_, prenom_, groupe_TD_, image_;
	int numero_;
public:
	Etudiant(string nom = " ", string username = " ", string prenom = " ", string groupe_TD = " ", string image = " ", int numero=0);
	void afficher();
	string getImage() { return image_; };
	const string& getNomPrenom()const { return nom_ + " " + prenom_; };
	//void sauver(ofstream& ofs) const;
	//void charger(ifstream& ifs);
};
