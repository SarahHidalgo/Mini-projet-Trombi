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

// Fonction non nécessaire au final
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
	ofs << nom_TD_ << endl;
	ofs << tabMembre_.size() << endl;
	for (int i = 0; i < (int)tabMembre_.size(); i++)
		tabMembre_[i]->sauver(ofs);
}

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

void Groupe_TD::afficherEcran(Groupe_TD groupe)
{
	RenderWindow app(VideoMode(1920, 1080), groupe.getNom());

	while (app.isOpen())
	{
		Event event;

		// Affichage de la fenêtre à l'écran

		app.clear(Color::White);

		int Nmax = groupe.getSize(); // nombre d'étudiants dans le groupe
		int n = 0; // on part de l'étudiant 0

		Portrait portrait;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				// Affichage photos des étudiants
				portrait.SetNom(groupe.getEtudiantImage(n));
				portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

				// Affichage des noms des étudiants
				portrait.afficherText(groupe.getEtudiantNom(n), groupe.getEtudiantPrenom(n), app, 150 + j * 270, 430 + i * 450);

				n++; // on passe à l'étudiant suivant en incrémentant l'entier n

			}
		}

		// On place les flèches de navigation
		portrait.SetNom("fleche_droite.png");
		portrait.afficherImage(app, 1850, 490,true);
		portrait.SetNom("fleche_gauche.png");
		portrait.afficherImage(app, 20, 490,true);

		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
				app.close();
			/*if (event.type == Mouse::isButtonPressed(Mouse::Left))
			{
				// if souris est sur une fleche
				// on lit la position globale de la souris (relativement au bureau)
				Vector2i pos_souris = Mouse::getPosition();

				app.clear();

				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						if (6 * i + j + 1 < Nmax)
						{
							// Affichage photos des étudiants
							portrait.SetNom(groupe.getEtudiantImage(n));
							portrait.afficherImage(app, 20 + j * 300, 20 + i * 450);

							// Affichage des noms des étudiants
							portrait.afficherText(groupe.getEtudiantNom(n), groupe.getEtudiantPrenom(n), app, 20 + j * 300, 350 + i * 450);

							n++; // on passe à l'étudiant suivant en incrémentant l'entier n
						}
					}
				}
			}*/

			// if souris est sur une image

			
		}

		app.display();
	}
}