// Mini-projet.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

// GrA ou Groupe A : demander a la prof !!

#include <sstream>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <array>

#include "Etudiants.h"
#include "Groupe_TD.h"
#include "FiseTSE.h"

using namespace std;
using namespace sf;


/*

int main()
{
	// Initialisation d'un étudiant
	Etudiant etudiant("Dupont", "De", "rr", "C", "png", 23);
	etudiant.afficher();

	// Initialisation d'un groupe de TD
	Groupe_TD groupe_C("Groupe C");
	groupe_C.ajouterMembre(new Etudiant("Dupont", "De1", "rr1", "C", "png1", 23));
	groupe_C.ajouterMembre(new Etudiant("Duchmol", "De2", "rr2", "C", "png2", 24));
	groupe_C.ajouterMembre(new Etudiant("Toto", "De3", "rr3", "C", "png3", 25));
	groupe_C.afficher();

	// Choix du fichier à ouvrir (Fise1, Fise2, Fise3)
	FiseTSE Fise_info;
	Fise_info.choixFise();

	//Verification des choix, affichage du nom et du fichier a ouvrir
	cout << Fise_info.getNom() << endl;
	cout << Fise_info.getLink() << endl;
	cout << Fise_info.getChoixGroupe() << endl;

	// Découpage des infos du fichier
	string lien_fichier;
	lien_fichier = Fise_info.getLink();
	Fise_info.decoupageInfosEtudiants(lien_fichier);
	cout << Fise_info.afficherInfosVecteurs("nom_", 125) << endl; // test affichage du fichier image du rang 125

	// Initialisation des 5 groupes de TD différents
	Groupe_TD Groupe_A("A");
	Groupe_TD Groupe_B("B");
	Groupe_TD Groupe_C("C");
	Groupe_TD Groupe_D("D");
	Groupe_TD Groupe_E("E");

	// Tri des etudiants dans les groupe de TD
	Groupe_A.ajoutEtudiants(Fise_info);
	Groupe_B.ajoutEtudiants(Fise_info);
	Groupe_C.ajoutEtudiants(Fise_info);
	Groupe_D.ajoutEtudiants(Fise_info);
	Groupe_E.ajoutEtudiants(Fise_info);
	Groupe_A.afficher(); // Affichage du groupe A

	cout << "FIN" << endl;

	return 0;
}
	

*/