#include <string>
#include <fstream>
#include <iostream>
#include "Etudiants.h"

using namespace std;

Etudiant::Etudiant(string nom, string Username, string Prenom, string Groupe_TD, string Fichier, int Numero)
{
	Nom_ = nom;
	Username_ = Username;
	Prenom_ = Prenom;
	Groupe_TD_ = Groupe_TD;
	Fichier_ = Fichier;
	Numero_ = Numero;
}

void Etudiant::afficher()
{
	cout << "Etudiant : " << Nom_ << " " << Prenom_ << endl;
	cout << "Numero de l'étudiant : " << Numero_ << endl;
	cout << "Username : " << Username_ << endl;
	cout << "Groupe de TD : " << Groupe_TD_ << endl;
	cout << "Fichier photo : " << Fichier_ << endl;

}