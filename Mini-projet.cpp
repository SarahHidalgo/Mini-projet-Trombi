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



void decoupageInfosEtudiants(string fichier, vector<string> numero, vector<string> username, vector<string> nom, vector<string> prenom, vector<string> groupe_TD, vector<string> image)
{
	// Récupération des données sur les étudiants du fichier 
	vector<string> Nu{}, Us{}, No{}, Pr{}, Gr{}, Im{};
	ifstream Trombi("fise1.csv", ios::in);  // on ouvre en lecture

	if (!Trombi.is_open()) {
		cout << "Erreur d'ouverture" << endl;
	}
	else {
		string ligne;
		char delimiter1 = '\n';
		while (getline(Trombi, ligne, delimiter1))
		{
			// cout << ligne << endl;
			stringstream sstream(ligne);
			char delimiter2 = ';';
			string mot;
			getline(sstream, mot, delimiter2);
			Nu.push_back(mot);
			getline(sstream, mot, delimiter2);
			Us.push_back(mot);
			getline(sstream, mot, delimiter2);
			No.push_back(mot);
			getline(sstream, mot, delimiter2);
			Pr.push_back(mot);
			getline(sstream, mot, delimiter2);
			Gr.push_back(mot);
			getline(sstream, mot, delimiter2);
			Im.push_back(mot);
		}
		/*
		numero = &Nu;
		username = &Us;
		nom = &No;
		prenom = &Pr;
		groupe_TD = &Gr;
		image = &Im;
		*/
	}
	for (const auto& str : Nu) {
		cout << str << endl;;
	}
	for (const auto& str : Gr) {
		cout << str << endl;;
	}
	
}



// Tri des élèves en fonction des groupe de TD ??

void ajoutEtudiants(Groupe_TD groupA, Groupe_TD groupB, Groupe_TD groupC, Groupe_TD groupD, Groupe_TD groupE,vector<string> numero, vector<string> username, vector<string> nom, vector<string> prenom, vector<string> groupe_TD, vector<string> image)
{
	for (int i =1 ; i < numero.size(); i++)
	{
		Etudiant etu(nom[i], username[i], prenom[i], groupe_TD[i], image[i], stoi(numero[i]));
		if (groupe_TD[i] == "A") 
		{
			groupA.ajouterMembre(&etu);
		}
		if (groupe_TD[i] == "B")
		{
			groupB.ajouterMembre(&etu);
		}
		if (groupe_TD[i] == "C")
		{
			groupC.ajouterMembre(&etu);
		}
		if (groupe_TD[i] == "D")
		{
			groupD.ajouterMembre(&etu);
		}
		if (groupe_TD[i] == "E")
		{
			groupE.ajouterMembre(&etu);
		}
		groupA.afficher();

	}
}




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

	//Verification des choix
	cout << Fise_info.getNom() << endl;
	cout << Fise_info.getLink() << endl;

	cout << "FIN" << endl;

	vector<string> num{}, user{}, name{}, pre{}, groupe{}, img{};
	//decoupageInfosEtudiants(fichier, num, user, name, pre, groupe, img);

	// Initialisation des 5 groupes de TD différents
	Groupe_TD Groupe_A("Groupe-A");
	Groupe_TD Groupe_B("Groupe-B");
	Groupe_TD Groupe_C("Groupe-C");
	Groupe_TD Groupe_D("Groupe-D");
	Groupe_TD Groupe_E("Groupe-E");

	//ajoutEtudiants(Groupe_A, Groupe_B, Groupe_C, Groupe_D, Groupe_E, num, user, name, pre, groupe, img);


	// Affichage des données des étudiants mises dans des vecteurs
	/*
	for (const auto& str : num) {
		cout << str << endl;;
	}
	for (const auto& str : groupe) {
		cout << str << endl;;
	}*/
	


	return 0;
}
	

// Utilisation de SFML
/*	string groupe;
	cout << "Choisissez le groupe de TD" << endl;
	cin >> groupe;

	sf::Texture texture;
	if (!texture.loadFromFile("marie.png"))
	{
		// erreur...
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);

	// définit un triangle
	sf::CircleShape triangle(80.f, 3);
	// définit un carré
	sf::CircleShape square(80.f, 4);
	// définit un octogone
	sf::CircleShape octagon(80.f, 8);
	triangle.setTexture(&texture);
	octagon.setTexture(&texture);

	// Création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(800, 800), "FISE1");
	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			// Demande de fermeture de la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// On efface la fenêtre (en blanc)
		window.clear(sf::Color::White);
		// Affichage du sprite
		window.draw(sprite);
		window.draw(triangle);
		window.draw(octagon);
		// Mise à jour de la fenêtre
		window.display();

	}*/
