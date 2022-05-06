#include <string>
#include <fstream>
#include <iostream>
#include "Groupe_TD.h"

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

void Groupe_TD::ajouterMembre(Etudiant* e)
{
	tabMembre_.push_back(e);
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

