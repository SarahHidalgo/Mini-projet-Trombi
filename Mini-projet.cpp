// Mini-projet.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <sstream>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <array>

#include "Etudiants.h"
#include "Groupe_TD.h"


using namespace std;
using namespace sf;

void decoupageInfosEtudiants(string fichier) 
{
	// Récupération des données sur les étudiants du fichier 
	vector<string> Numero{}, Username{}, Nom{}, Prenom{}, Groupe_TD{}, Fichier{};
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
			Numero.push_back(mot);
			getline(sstream, mot, delimiter2);
			Username.push_back(mot);
			getline(sstream, mot, delimiter2);
			Nom.push_back(mot);
			getline(sstream, mot, delimiter2);
			Prenom.push_back(mot);
			getline(sstream, mot, delimiter2);
			Groupe_TD.push_back(mot);
			getline(sstream, mot, delimiter2);
			Fichier.push_back(mot);
		}

		// Affichage des données des étudiants mises dans des vecteurs
		
		for (const auto& str : Numero) {
			cout << str << endl;;
		}
		for (const auto& str : Groupe_TD) {
			cout << str << endl;;
		}
	}
}

void choixFise(string fichierFise) {
	string choix, Fise, Groupe;
	char delimiter = '-';
	bool flag = true;
	array <string,3> myList1 = { "FISE1", "FISE2", "FISE3"};
	array <string, 5> myList2 = { "GrA", "GrB", "GrC","GrD","GrE"};

	// Display les différentes filieres et groupe pour orienter l'utilisateur
	cout << "---------------------------" << endl;
	cout << " Filieres : " << endl;
	cout << " FISE1 " << endl;
	cout << " FISE2 " << endl;
	cout << " FISE3 " << endl;
	cout << "---------------------------" << endl;
	cout << " Groupes : " << endl;
	cout << " GrA " << endl;
	cout << " GrB " << endl;
	cout << " GrC " << endl;
	cout << " GrD " << endl;
	cout << " GrE " << endl;
	cout << "---------------------------" << endl;

	do {

		cout << "Donnnez la filiere et le groupe de TD dont vous voulez faire l'appel (par exemple FISE2-GrA) : " << endl;
		cin >> choix;
		stringstream sstream(choix);
		getline(sstream, Fise, delimiter);
		cout << Fise << endl;
		//const char* choixF = Fise.c_str(); // on transforme un string en const char*
		getline(sstream, Groupe);
		cout << Groupe << endl;
		//const char* choixG = Groupe.c_str();
		// Si Fise et Groupe font partie de myList(1 ou 2) alors l'utilisateur a rentré ce qui était demandé, on sort donc de la boucle
		if ((find(begin(myList1), end(myList1), Fise) != end(myList1)) && (find(begin(myList2), end(myList2),Groupe) != end(myList2))) 
		{
			flag = false;
		}
		// Sinon on rentre de re rentre la filiere et le groupe
		else
		{
			cout << "Veuillez reessayer, ecrivez la filiere et le groupe en suivant l'exemple donne ! " << endl;
			cout << endl;
		}
	} while (flag);
}


int main()
{
	// Initialisation d'un étudiant
	Etudiant etudiant("D", "De", "rr", "C", "png", 23);
	etudiant.afficher();

	// Initialisation d'un groupe de TD
	Groupe_TD groupe_C("Groupe C");
	groupe_C.ajouterMembre(new Etudiant("Dupont", "De1", "rr1", "C", "png1", 23));
	groupe_C.ajouterMembre(new Etudiant("Duchmol", "De2", "rr2", "C", "png2", 24));
	groupe_C.ajouterMembre(new Etudiant("Toto", "De3", "rr3", "C", "png3", 25));
	groupe_C.afficher();

	// Choix du fichier à ouvrir (Fise1, Fise2, Fise3)
	string fichier = "fise1.csv"; // par défault on ouvre fise1
	choixFise(fichier);
	decoupageInfosEtudiants(fichier);

	// Tri des élèves en fonction des groupe de TD ??


	
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
