#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Créée par Sarah HDG
class FiseTSE 
{
	string nom_fichier_, nom_fise_, choix_groupe_; // nom du fichier.csv, nom de la fise, nom du groupe ("GrA")
	vector<string> numero_, username_, nom_, prenom_, groupe_TD_, image_; // vecteur numero_ contient tout les numeros du fichier, même principe 
	//pour les autres vecteurs
public:
	FiseTSE(string nom_fise = " ", string lien = " "); //constructeur par defaut de la classe FIseTSE 
	void afficher(); //affichage des parametres de la classe sur la console
	const string& getNom() const { return nom_fise_; };
	const string& getLink() const { return nom_fichier_; };
	const string& getChoixGroupe() const { return choix_groupe_; };
	string afficherInfosVecteurs(string nom_vecteur, int i);
	void choixFise(); //sert a rentrer son choix de FISE et de groupe de TD sur la console
	void decoupageInfosEtudiants(string nom_fichier); //tri du fichier .csv pour remplir les vecteurs

};
