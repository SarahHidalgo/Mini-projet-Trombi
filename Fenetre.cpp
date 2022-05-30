#include"Portrait.h"
#include "Groupe_TD.h"
#include "Fenetre.h"

#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Fenetre::Fenetre(string lettre_gr)
{
	nom_fenetre_ = "Groupe "+ lettre_gr;
}

// affichage de la fenetre du groupe entrer par l'utilisateur
void Fenetre::afficherFenetreGroupe(Portrait portrait, string lettre_groupe, Groupe_TD Groupe_A, Groupe_TD Groupe_B, Groupe_TD Groupe_C, Groupe_TD Groupe_D, Groupe_TD Groupe_E)
{
	if (lettre_groupe == Groupe_A.getNom()) {
		afficherFenetre(Groupe_A, portrait);
	}
	if (lettre_groupe == Groupe_B.getNom()) {
		afficherFenetre(Groupe_B, portrait);
	}
	if (lettre_groupe == Groupe_C.getNom()) {
		afficherFenetre(Groupe_C, portrait);
	}
	if (lettre_groupe == Groupe_D.getNom()) {
		afficherFenetre(Groupe_D, portrait);
	}
	if (lettre_groupe == Groupe_E.getNom()) {
		afficherFenetre(Groupe_E, portrait);
	}
}

// fonction pour afficher la fenetre d'un groupe
void Fenetre::afficherFenetre(Groupe_TD groupe, Portrait portrait)
{
	RenderWindow app(VideoMode(1920, 1080), getNom());

	while (app.isOpen())
	{
		Event event;
		// Affichage de la fenêtre à l'écran
		while (app.pollEvent(event))
		{
			// Appuis sur la croix
			if (event.type == Event::Closed)
				app.close();
			// Appui sur le bouton gauche
			if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
			{
				bool present;
				Vector2i localPosition = sf::Mouse::getPosition(app);
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						// Si clique sur un étudiant
						if ((localPosition.y >= (20 + j * 300) && localPosition.y<=(260 + j * 300)) && (localPosition.x>= (20 + i * 450) && localPosition.x <= (360 + i * 450)))
						{
							portrait.afficherText("Présent", "", app, 50 + j * 300, 380 + i * 450);	
							cout << "Present" << endl;
						}
						else {
							present=false ;
						}
						// Si clique sur la fleche
					}
				}
			}
		}
		app.clear(Color::White);

		int Nmax = groupe.getSize(); // nombre d'étudiants dans le groupe
		int nb = 0; // on part de l'étudiant 0

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				// Affichage photos des étudiants
				portrait.SetNom(groupe.getEtudiantImage(nb));
				portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

				// Affichage des noms des étudiants
				portrait.afficherText(groupe.getEtudiantNom(nb), groupe.getEtudiantPrenom(nb), app, 150 + j * 270, 430 + i * 450);

				nb++; // on passe à l'étudiant suivant en incrémentant l'entier n

			}
		}

		/*
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (6 * i + j + 1 < Nmax) // si on a pas atteint le nb d'étdiants du TD on affiche un étudiant
				{
					// Affichage photos des étudiants
					portrait.SetNom(groupe.getEtudiantImage(nb));
					portrait.afficherImage(app, 20 + j * 300, 20 + i * 450, false);

					// Affichage des noms des étudiants
					portrait.afficherText(groupe.getEtudiantNom(nb), groupe.getEtudiantPrenom(nb), app, 20 + j * 300, 350 + i * 450);

					// on passe à l'étudiant suivant en incrémentant l'entier n
					nb++;
				}
			}
		}*/

		Portrait portraitbis;
		// On place les flèches de navigation
		portraitbis.SetNom("fleche_droite.png");
		portraitbis.afficherImage(app, 1850, 490, true);
		portraitbis.SetNom("fleche_gauche.png");
		portraitbis.afficherImage(app, 20, 490, true);

		app.display();
	}

}