#include"Portrait.h"
#include "Groupe_TD.h"
#include "Fenetre.h"

#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Fenetre::Fenetre(string lettre_gr)
{
	nom_fenetre_ = "Groupe " + lettre_gr;
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
	int num_page = 1; // compteur de page
	bool der_page = false; // booléen qui détermine si on a atteint la dernière page
	Portrait portraitFleche;


	app.clear(Color::White);

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

	

	// On place les flèches de navigation que à droite car on est à la première page donc il n'y a rien à gauche
	portraitFleche.SetNom("fleche_droite.png");
	portraitFleche.afficherImage(app, 1850, 490, true);

	app.display();

	int nb_restant;
	nb_restant = Nmax - nb;
	int current_nb = 0;

	while (app.isOpen())
	{
		Portrait portraitText;
		string presence = "p.png";

		vector <int> etudiants_present;
		Event event;

		// Affichage de la fenêtre à l'écran
		while (app.pollEvent(event))
		{
			// Appuis sur la croix
			if (event.type == Event::Closed)
				app.close();

			/// Appui sur le bouton gauche de la souris
			if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
			{
				bool present = false;

				Vector2i localPosition = Mouse::getPosition(app); // on récupère la position de la souris

				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						// Si clique sur un étudiant
						if ((localPosition.x >= (150 + j * 270) && localPosition.x <= (390 + j * 300)) && (localPosition.y >= (100 + i * 450) && localPosition.y <= (440 + i * 450)))
						{
							Portrait portraitText;
							portraitText.SetNom(presence);
							portraitText.afficherImage(app, 150 + j * 270, 100 + i * 450, true);
						}
						// Si clique sur la fleche
					}
				}


				/// Clique sur la flèche de droite
				if (!der_page && (localPosition.x >= (1750) && localPosition.y <= (540) && localPosition.y >= (490))) 
				{
					app.clear(Color::White);
					current_nb = 0;
					num_page++;

					portraitFleche.SetNom("fleche_gauche.png");
					portraitFleche.afficherImage(app, 20, 490, true);

					for (int i = 0; i < 2; i++)
					{
						for (int j = 0; j < 6; j++)
						{
							if (nb_restant >= 0 && current_nb < 12 && nb < groupe.getSize())
							{
								// Affichage photos des étudiants
								portrait.SetNom(groupe.getEtudiantImage(nb));
								portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

								// Affichage des noms des étudiants
								portrait.afficherText(groupe.getEtudiantNom(nb), groupe.getEtudiantPrenom(nb), app, 150 + j * 270, 430 + i * 450);
								current_nb++;
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
					if (nb_restant == 0)
					{
						der_page = true;
					}
					app.display();

				}


				/// Clique sur la flèche de gauche 
				if (num_page!=1 && (localPosition.x <= (200) && localPosition.y <= (540) && localPosition.y >= (490))) 
				{
					app.clear(Color::White); // on nettoie la fenêtre


					current_nb = 0; // réinitialisation du compteur local
					der_page = false; // si on était à la dernière page, on y est plus, sinon ça ne change rien
					
									  
					// cette boucle permet de déterminer à quel étudiant il faut démarrer l'affichage
					if (num_page==2) // si on est à la deuxième page
					{
						nb = 0; //on remet nb à 0 pour commencer l'affichage à l'étudiant 0, ce qui correspond bien à la première page
					}
					else if(num_page==3) // si on est à la troisème page
					{
						nb = 12; //on remet nb à 12 pour commencer l'affichage à l'étudiant 12, ce qui correspond bien à la deuxième page
					}

					
					// On affiche par défaut les flèches de droite car si on va à gauche c'est qu'il y avait une page à droite
					portraitFleche.SetNom("fleche_droite.png");
					portraitFleche.afficherImage(app, 1850, 490, true);

					num_page--; // on décrémente le numéro de la page

					// s'il reste une page à gauche, on remet une flèche 
					if (nb!=0)
					{
						portraitFleche.SetNom("fleche_gauche.png");
						portraitFleche.afficherImage(app, 20, 490, true);
					}

					while (nb_restant >= 0 && current_nb < 12)
					{
						for (int i = 0; i < 2; i++)
						{
							for (int j = 0; j < 6; j++)
							{
								// Affichage photos des étudiants
								portrait.SetNom(groupe.getEtudiantImage(nb));
								portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

								// Affichage des noms des étudiants
								portrait.afficherText(groupe.getEtudiantNom(nb), groupe.getEtudiantPrenom(nb), app, 150 + j * 270, 430 + i * 450);
								current_nb++;
								nb++; // on passe à l'étudiant suivant en incrémentant l'entier nb
								nb_restant = Nmax - nb;
							}
						}
					}
					app.display();

				}
			}
			//portrait.afficherPresence(app, 150 + j * 270, 100 + i * 450, presence);
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