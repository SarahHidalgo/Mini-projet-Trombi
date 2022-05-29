#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "Etudiants.h"
#include "FiseTSE.h"

using namespace std;

class Groupe_TD : public FiseTSE
{
	string nom_TD_;
	vector<Etudiant *> tabMembre_;

public:
	Groupe_TD(const string& nom = "");
	~Groupe_TD();
	void ajouterMembre(Etudiant* e);
	const string& getNom() const { return nom_TD_; };
	void afficher();
	void ajoutEtudiants(FiseTSE Fise_info);
	string getEtudiantImage(int i) { return tabMembre_[i]->getImage(); };
	string getEtudiantNomPrenom(int i) { return tabMembre_[i]->getNomPrenom(); };
	int getSize() const { return tabMembre_.size(); };
	void afficherEcran(Groupe_TD);
};

