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

	int Nmax = groupe.getSize(); // nombre d'étudiants dans le groupe
	int nb = 0; // on part de l'étudiant 0

	app.clear(Color::White);
	// On définit par défault le status d'absent aux élèves
	string presence = "a.png";
	Portrait portraitText;
	portraitText.SetNom(presence);


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
			portraitText.afficherImage(app, 150 + j * 270, 100 + i * 450, true);
		}
	}


	// On place les flèches de navigation
	Portrait portraitFleche;
	portraitFleche.SetNom("fleche_droite.png");
	portraitFleche.afficherImage(app, 1850, 490, true);
	//portraitFleche.SetNom("fleche_gauche.png");
	//portraitFleche.afficherImage(app, 20, 490, true);





	app.display();

	int nb_page = 1;
	int nb_restant;
	nb_restant = Nmax - nb;
	int current_nb = 0;

	while (app.isOpen())
	{
		vector <int> etudiants_present;
		Event event;

		// Affichage de la fenêtre à l'écran
		while (app.pollEvent(event))
		{
			// Appuis sur la croix
			if (event.type == Event::Closed)
				app.close();
			// Appui sur le bouton gauche
			if ((event.type == Event::MouseButtonPressed) && (event.mouseButton.button == Mouse::Left))
			{
				Vector2i localPosition = Mouse::getPosition(app);

				// Navigation 
				if (localPosition.x >= (1750)) // Clique sur la flèche de droite ( partie droite de la fenetre)
				{
					app.clear(Color::White);

					portraitFleche.SetNom("fleche_gauche.png");
					portraitFleche.afficherImage(app, 20, 490, true);

					//while (nb_restant >= 0 && current_nb<12)
					
					for (int i = 0; i < 2; i++)
					{
						for (int j = 0; j < 6; j++)
						{
							if (nb_restant >= 0 && current_nb < 12 && nb<25)
							{
								// Affichage photos des étudiants
								portrait.SetNom(groupe.getEtudiantImage(nb));
								portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

								// Affichage des noms des étudiants
								portrait.afficherText(groupe.getEtudiantNom(nb), groupe.getEtudiantPrenom(nb), app, 150 + j * 270, 430 + i * 450);
								
								portraitText.afficherImage(app, 150 + j * 270, 100 + i * 450, true);

								current_nb++; // numéro de l'étudiant sur la page courante
								nb++; // on passe à l'étudiant suivant en incrémentant l'entier nb
								nb_restant = Nmax - nb;
							}
								
						}
					}
					// s'il reste des éleves on affiche la fleche de droite 
					if (nb_restant != 0)
					{
						portraitFleche.SetNom("fleche_droite.png");
						portraitFleche.afficherImage(app, 1850, 490, true);
					}
					app.display();
					
				}
				current_nb = 0;



				bool present = false;
				// Affichage de la présence des eleves
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						// Si clique sur un étudiant
						if ((localPosition.x >= (150 + j * 270) && localPosition.x <= (390 + j * 300)) && (localPosition.y >= (100 + i * 450) && localPosition.y <= (440 + i * 450)))
						{
							if (present)
							{
								//portraitText.SetNom("p.png");
								//portraitText.
							}
							//portraitText.SetNom(presence);
							//portraitText.afficherImage(app, 150 + j * 270, 100 + i * 450, true);
							//app.display();
						}
					}
				}
			}
		}
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