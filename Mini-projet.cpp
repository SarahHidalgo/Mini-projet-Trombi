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
#include"Portrait.h"

using namespace std;
using namespace sf;



int main()
{
	// Choix du fichier à ouvrir (Fise1, Fise2, Fise3)
	FiseTSE Fise_info;
	Fise_info.choixFise();

	//Verification des choix, affichage du nom et du fichier a ouvrir
	string nom_fise = Fise_info.getNom();
	string nom_groupe = Fise_info.getChoixGroupe(); // affichage de "GrC"
	string lettre_gr;
	lettre_gr = nom_groupe[2]; // Lalettre du groupe est conservé dans la variable lettre_gr


	// Découpage des infos du fichier
	string lien_fichier;
	lien_fichier = Fise_info.getLink();
	Fise_info.decoupageInfosEtudiants(lien_fichier); // tri du fichier

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


	Groupe_C.afficherEcran(Groupe_C);


	cout << "FIN" << endl;

	return 0;
}
	
