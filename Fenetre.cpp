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
void Fenetre::afficherFenetreGroupe(ofstream& ofs,Portrait portrait, string lettre_groupe, Groupe_TD Groupe_A, Groupe_TD Groupe_B, Groupe_TD Groupe_C, Groupe_TD Groupe_D, Groupe_TD Groupe_E)
{
	if (lettre_groupe == Groupe_A.getNom()) {
		afficherFenetre(Groupe_A, portrait, ofs);
	}
	if (lettre_groupe == Groupe_B.getNom()) {
		afficherFenetre(Groupe_B, portrait, ofs);
	}
	if (lettre_groupe == Groupe_C.getNom()) {
		afficherFenetre(Groupe_C, portrait, ofs);
	}
	if (lettre_groupe == Groupe_D.getNom()) {
		afficherFenetre(Groupe_D, portrait, ofs);
	}
	if (lettre_groupe == Groupe_E.getNom()) {
		afficherFenetre(Groupe_E, portrait, ofs);
	}
}

// fonction pour afficher la fenetre d'un groupe
void Fenetre::afficherFenetre(Groupe_TD groupe, Portrait portrait, ofstream& ofs)
{
	RenderWindow app(VideoMode(1920, 1080), getNom());

	int Nmax = groupe.getSize(); // nombre d'�tudiants dans le groupe
	int nb = 0; // on part de l'�tudiant 0
	int num_page = 1; // compteur de page
	bool der_page = false; // bool�en qui d�termine si on a atteint la derni�re page

	// Vecteur qui va stocker des booleens pour savoir quel �tudiant est absent, et lequel est pr�sent
	vector <bool> etudiants_present; 
	for (int k = 0; k < groupe.getSize(); k++)
	{
		etudiants_present.push_back(false);
	}

	// Vecteur de string qui stocke l'image present ou absent
	string nom_pre = "a.png";
	vector <string> etudiants_image; 
	for (int k = 0; k < groupe.getSize(); k++)
	{
		etudiants_image.push_back(nom_pre);
	}

	app.clear(Color::White);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			// Affichage photos des �tudiants
			portrait.SetNom(groupe.getEtudiantImage(nb));
			portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

			// Affichage des noms des �tudiants
			portrait.afficherText(groupe.getEtudiantNom(nb), groupe.getEtudiantPrenom(nb), app, 150 + j * 270, 430 + i * 450);

			//
			portrait.SetNom(etudiants_image[6 * i + j + (num_page - 1) * 12]);
			portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);


			nb++; // on passe � l'�tudiant suivant en incr�mentant l'entier n
		}
	}
	

	// On place les fl�ches de navigation que � droite car on est � la premi�re page donc il n'y a rien � gauche
	Portrait portraitFleche;
	portraitFleche.SetNom("fleche_droite.png");
	portraitFleche.afficherImage(app, 1850, 490, true);

	app.display();

	int nb_restant; // nombre restant d'�tudiants � afficher
	nb_restant = Nmax - nb;
	int current_nb = 0; // correspond au num�ro de l'�tudiant dans la page (donc entre 0 et 11)

	while (app.isOpen())
	{
		Portrait portraitText;
		Event event;

		// Affichage de la fen�tre � l'�cran
		while (app.pollEvent(event))
		{
			// Appuis sur la croix
			if (event.type == Event::Closed)
				app.close();

			// Appui sur le bouton gauche de la souris
			if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
			{
				Vector2i localPosition = Mouse::getPosition(app); // on r�cup�re la position de la souris

				/// Clique sur la fl�che de droite
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
								// Affichage photos des �tudiants
								portrait.SetNom(groupe.getEtudiantImage(nb));
								portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

								// Affichage des noms des �tudiants
								portrait.afficherText(groupe.getEtudiantNom(nb), groupe.getEtudiantPrenom(nb), app, 150 + j * 270, 430 + i * 450);
								current_nb++; // correspond au num�ro de l'�tudiant dans la page (donc entre 0 et 11)
								nb++; // on passe � l'�tudiant suivant en incr�mentant l'entier nb
								nb_restant = Nmax - nb; // update le nombre restant d'�l�ve � afficher
							}

						}
					}
					// s'il reste des �leves on affiche la fleche de droite 
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

				/// Clique sur la fl�che de gauche 
				if (num_page != 1 && (localPosition.x <= (200) && localPosition.y <= (540) && localPosition.y >= (490)))
				{
					app.clear(Color::White); // on nettoie la fen�tre

					current_nb = 0; // r�initialisation du compteur local
					der_page = false; // si on �tait � la derni�re page, on y est plus, sinon �a ne change rien

					// cette boucle permet de d�terminer � quel �tudiant il faut d�marrer l'affichage
					if (num_page == 2) // si on est � la deuxi�me page
					{
						nb = 0; //on remet nb � 0 pour commencer l'affichage � l'�tudiant 0, ce qui correspond bien � la premi�re page
					}
					else if (num_page == 3) // si on est � la trois�me page
					{
						nb = 12; //on remet nb � 12 pour commencer l'affichage � l'�tudiant 12, ce qui correspond bien � la deuxi�me page
					}


					// On affiche par d�faut les fl�ches de droite car si on va � gauche c'est qu'il y avait une page � droite
					portraitFleche.SetNom("fleche_droite.png");
					portraitFleche.afficherImage(app, 1850, 490, true);

					num_page--; // on d�cr�mente le num�ro de la page

					// s'il reste une page � gauche, on remet une fl�che 
					if (nb != 0)
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
								// Affichage photos des �tudiants
								portrait.SetNom(groupe.getEtudiantImage(nb));
								portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

								// Affichage des noms des �tudiants
								portrait.afficherText(groupe.getEtudiantNom(nb), groupe.getEtudiantPrenom(nb), app, 150 + j * 270, 430 + i * 450);
								current_nb++;
								nb++; // on passe � l'�tudiant suivant en incr�mentant l'entier nb
								nb_restant = Nmax - nb;
							}
						}
					}
					app.display();
				}
				
				
				
				app.clear(Color::White);
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						if (6 * i + j + (num_page - 1) * 12 < groupe.getSize())
						{
							// Si clique sur une image
							if ((localPosition.x >= (150 + j * 270) && localPosition.x <= (390 + j * 270)) && (localPosition.y >= (100 + i * 450) && localPosition.y <= (440 + i * 450)))
							{
								// Si l'�tudiant �tait marqu� absent
								if (etudiants_present[6 * i + j + (num_page - 1) * 12] == false) 
								{
									etudiants_present[6 * i + j + (num_page - 1) * 12] = true; // l'�tudiant est maintenant marqu� pr�sent
									etudiants_image[6 * i + j + (num_page - 1) * 12] = "p.png"; // on change l'image pour celle de pr�sent
								}
								// Si l'�tudiant �tait marqu� pr�sent
								else
								{
									etudiants_present[6 * i + j + (num_page - 1) * 12] = false; // l'�tudiant est maintenant marqu� absent
									etudiants_image[6 * i + j + (num_page - 1) * 12] = "a.png";  // on change l'image pour celle de absent
								}
							}
							// Affichage photos des �tudiants
							portrait.SetNom(groupe.getEtudiantImage(6 * i + j + (num_page - 1) * 12));
							portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

							// Affichage des noms des �tudiants
							portrait.afficherText(groupe.getEtudiantNom(6 * i + j + (num_page - 1) * 12), groupe.getEtudiantPrenom(6 * i + j + (num_page - 1) * 12), app, 150 + j * 270, 430 + i * 450);

							//Affichage de la pr�sence de eleve
							portrait.SetNom(etudiants_image[6 * i + j + (num_page - 1) * 12]);
							portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

							// Affichage des fleches en fonction de la page ou l'on se situe
							if (!der_page)
							{
								portraitFleche.SetNom("fleche_droite.png");
								portraitFleche.afficherImage(app, 1850, 490, true);
							}
							if (num_page != 1)
							{
								portraitFleche.SetNom("fleche_gauche.png");
								portraitFleche.afficherImage(app, 20, 490, true);
							}

						}
					}
				}
				app.display();
			}
		}
	}
	/// Apres la fermeture de la fen�tre on cr�er la fiche d'appel

	// Ici on met a jour le parametre de presence de chaque etudiant du TD
	for (int k = 0; k<etudiants_present.size(); k++)
	{
		groupe.setEtudiantsPresence(etudiants_present[k], k); 
	}

	// Sauvegarde des infos des �tudiants dans un fichier txt
	groupe.sauver(ofs);
}

