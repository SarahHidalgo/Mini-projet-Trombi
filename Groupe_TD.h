#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "Etudiants.h"
#include "FiseTSE.h"

using namespace std;

// Créée par Marie FRT et Sarah HDG
class Groupe_TD : public FiseTSE
{
	string nom_TD_; // lettre du groupe de TD 
	vector<Etudiant*> tabMembre_; //vecteur composer de pointeur vers etudiants

public:
	Groupe_TD(const string& nom = "");// constructeur par defaut de la classe Groupe_TD
	~Groupe_TD();
	const string& getNom() const { return nom_TD_; }
	int getSize() const { return tabMembre_.size(); }
	void afficher();
	void ajoutEtudiants(FiseTSE Fise_info); // ajout des etudiants dans le groupe de TD
	void sauver(ofstream& ofs) const; // sauvegarde des eleves du groupe du TD dans un fichier
	//void charger(ifstream& ifs);
	string getEtudiantImage(int i) { return tabMembre_[i]->getImage(); } //recup de l'image de l'étudiant d'indice i
	string getEtudiantNom(int i) { return tabMembre_[i]->getNom(); } //recup du nom de l'étudiant d'indice i
	string getEtudiantPrenom(int i) { return tabMembre_[i]->getPrenom(); } //recup du prenom de l'étudiant d'indice i
};


