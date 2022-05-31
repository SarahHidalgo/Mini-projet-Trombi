#include <string>
#include <fstream>
#include <iostream>
#include "Groupe_TD.h"
#include "Portrait.h"

using namespace std;

Groupe_TD::Groupe_TD(const string& nom)
{
	nom_TD_ = nom;
}


Groupe_TD::~Groupe_TD()
{
	for (int i = 0; i < tabMembre_.size(); i++)
		delete tabMembre_[i];
}

void Groupe_TD::afficher()
{
	cout << endl;
	cout << "-----------------------" << endl;
	cout << "Groupe de TD : " << nom_TD_ << endl;
	cout << "Effectif : " << tabMembre_.size() << endl;
	cout << "-----------------------" << endl;
	cout << "Membres : " << endl;
	cout << endl;
	for (int i = 0; i < tabMembre_.size(); i++)
	{
		tabMembre_[i]->afficher();
		cout << endl;
	}
}

void Groupe_TD::ajoutEtudiants(FiseTSE Fise_info)
{
	string nom_eleve, username_eleve, prenom_eleve, groupe_eleve, numero_eleve, image_eleve;

	for (int i = 1; i < 126; i++)
	{
		nom_eleve = Fise_info.afficherInfosVecteurs("nom_", i);
		username_eleve = Fise_info.afficherInfosVecteurs("username_", i);
		prenom_eleve = Fise_info.afficherInfosVecteurs("prenom_", i);
		groupe_eleve = Fise_info.afficherInfosVecteurs("groupe_TD_", i);
		numero_eleve = Fise_info.afficherInfosVecteurs("numero_", i);
		image_eleve = Fise_info.afficherInfosVecteurs("image_", i);

		if (strcmp(groupe_eleve.c_str(), nom_TD_.c_str()) == 0)
		{
			tabMembre_.push_back(new Etudiant(nom_eleve, username_eleve, prenom_eleve, groupe_eleve, image_eleve, stoi(numero_eleve)));
		}
	}
}

void Groupe_TD::sauver(ofstream& ofs) const
{
	ofs << "Groupe : "<< nom_TD_ << endl;
	ofs << tabMembre_.size() << " élèves " << endl;
	for (int i = 0; i < (int)tabMembre_.size(); i++)
		tabMembre_[i]->sauver(ofs);
}

/*
void Groupe_TD::charger(ifstream& ifs)
{
	getline(ifs, nom_TD_);
	// Suppression des membres existants
	for (int i = 0; i < (int)tabMembre_.size(); i++)
		delete tabMembre_[i];
	tabMembre_.clear();
	// Lecture des membres à partir du fichier
	size_t nb;
	ifs >> nb;
	ifs.ignore();
	for (int i = 0; i < (int)nb; i++)
	{
		Etudiant* e = new Etudiant;
		e->charger(ifs);
		ajouterMembre(e);
	}
}
*/