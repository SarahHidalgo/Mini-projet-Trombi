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

	int Nmax = groupe.getSize(); // nombre d'étudiants dans le groupe
	int nb = 0; // on part de l'étudiant 0
	int num_page = 1; // compteur de page
	bool der_page = false; // booléen qui détermine si on a atteint la dernière page

	// Vecteur qui va stocker des booleens pour savoir quel étudiant est absent, et lequel est présent
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
			// Affichage photos des étudiants
			portrait.SetNom(groupe.getEtudiantImage(nb));
			portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

			// Affichage des noms des étudiants
			portrait.afficherText(groupe.getEtudiantNom(nb), groupe.getEtudiantPrenom(nb), app, 150 + j * 270, 430 + i * 450);

			//
			portrait.SetNom(etudiants_image[6 * i + j + (num_page - 1) * 12]);
			portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);


			nb++; // on passe à l'étudiant suivant en incrémentant l'entier n
		}
	}
	

	// On place les flèches de navigation que à droite car on est à la première page donc il n'y a rien à gauche
	Portrait portraitFleche;
	portraitFleche.SetNom("fleche_droite.png");
	portraitFleche.afficherImage(app, 1850, 490, true);

	app.display();

	int nb_restant; // nombre restant d'étudiants à afficher
	nb_restant = Nmax - nb;
	int current_nb = 0; // correspond au numéro de l'étudiant dans la page (donc entre 0 et 11)

	while (app.isOpen())
	{
		Portrait portraitText;
		Event event;

		// Affichage de la fenêtre à l'écran
		while (app.pollEvent(event))
		{
			// Appuis sur la croix
			if (event.type == Event::Closed)
				app.close();

			// Appui sur le bouton gauche de la souris
			if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
			{
				Vector2i localPosition = Mouse::getPosition(app); // on récupère la position de la souris

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
								current_nb++; // correspond au numéro de l'étudiant dans la page (donc entre 0 et 11)
								nb++; // on passe à l'étudiant suivant en incrémentant l'entier nb
								nb_restant = Nmax - nb; // update le nombre restant d'élève à afficher
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
				if (num_page != 1 && (localPosition.x <= (200) && localPosition.y <= (540) && localPosition.y >= (490)))
				{
					app.clear(Color::White); // on nettoie la fenêtre

					current_nb = 0; // réinitialisation du compteur local
					der_page = false; // si on était à la dernière page, on y est plus, sinon ça ne change rien

					// cette boucle permet de déterminer à quel étudiant il faut démarrer l'affichage
					if (num_page == 2) // si on est à la deuxième page
					{
						nb = 0; //on remet nb à 0 pour commencer l'affichage à l'étudiant 0, ce qui correspond bien à la première page
					}
					else if (num_page == 3) // si on est à la troisème page
					{
						nb = 12; //on remet nb à 12 pour commencer l'affichage à l'étudiant 12, ce qui correspond bien à la deuxième page
					}


					// On affiche par défaut les flèches de droite car si on va à gauche c'est qu'il y avait une page à droite
					portraitFleche.SetNom("fleche_droite.png");
					portraitFleche.afficherImage(app, 1850, 490, true);

					num_page--; // on décrémente le numéro de la page

					// s'il reste une page à gauche, on remet une flèche 
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
								// Si l'étudiant était marqué absent
								if (etudiants_present[6 * i + j + (num_page - 1) * 12] == false) 
								{
									etudiants_present[6 * i + j + (num_page - 1) * 12] = true; // l'étudiant est maintenant marqué présent
									etudiants_image[6 * i + j + (num_page - 1) * 12] = "p.png"; // on change l'image pour celle de présent
								}
								// Si l'étudiant était marqué présent
								else
								{
									etudiants_present[6 * i + j + (num_page - 1) * 12] = false; // l'étudiant est maintenant marqué absent
									etudiants_image[6 * i + j + (num_page - 1) * 12] = "a.png";  // on change l'image pour celle de absent
								}
							}
							// Affichage photos des étudiants
							portrait.SetNom(groupe.getEtudiantImage(6 * i + j + (num_page - 1) * 12));
							portrait.afficherImage(app, 150 + j * 270, 100 + i * 450, false);

							// Affichage des noms des étudiants
							portrait.afficherText(groupe.getEtudiantNom(6 * i + j + (num_page - 1) * 12), groupe.getEtudiantPrenom(6 * i + j + (num_page - 1) * 12), app, 150 + j * 270, 430 + i * 450);

							//Affichage de la présence de eleve
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
	/// Apres la fermeture de la fenêtre on créer la fiche d'appel

	// Ici on met a jour le parametre de presence de chaque etudiant du TD
	for (int k = 0; k<etudiants_present.size(); k++)
	{
		groupe.setEtudiantsPresence(etudiants_present[k], k); 
	}

	// Sauvegarde des infos des étudiants dans un fichier txt
	groupe.sauver(ofs);
}

