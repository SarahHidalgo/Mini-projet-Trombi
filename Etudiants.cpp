#include <string>
#include <fstream>
#include <iostream>
#include "Etudiants.h"

using namespace std;

Etudiant::Etudiant(string nom, string Username, string Prenom, string Groupe_TD, string image, int Numero)
{
	nom_ = nom;
	username_ = Username;
	prenom_ = Prenom;
	groupe_TD_ = Groupe_TD;
	image_ = image;
	numero_ = Numero;
}

void Etudiant::afficher()
{
	cout << "Etudiant : " << nom_ << " " << prenom_ << endl;
	cout << "Numero de l'étudiant : " << numero_ << endl;
	cout << "Username : " << username_ << endl;
	cout << "Groupe de TD : " << groupe_TD_ << endl;
	cout << "Fichier photo : " << image_ << endl;

}