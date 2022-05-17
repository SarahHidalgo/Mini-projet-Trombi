#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "Etudiants.h"

using namespace std;

class Groupe_TD
{
	string nom_TD_;
	vector<Etudiant*> tabMembre_;

public:
	Groupe_TD(const string& nom = "");
	~Groupe_TD();
	void ajouterMembre(Etudiant* e);
	//const string& getNom() const { return nom_TD_; };
	void afficher();
	//void sauver(ofstream& ofs) const;
	//void charger(ifstream& ifs);
};

