#include <string>
#include <fstream>
#include <iostream>
#include "Etudiants.h"

using namespace std;

Etudiant::Etudiant(string nom, string Username, string Prenom, string Groupe_TD, string image, int Numero, bool present)
{
	nom_ = nom;
	username_ = Username;
	prenom_ = Prenom;
	groupe_TD_ = Groupe_TD;
	image_ = image;
	numero_ = Numero;
	present_ = present;

}

void Etudiant::afficher()
{
	cout << "Etudiant : " << nom_ << " " << prenom_ << endl;
	cout << "Numero de l'étudiant : " << numero_ << endl;
	cout << "Username : " << username_ << endl;
	cout << "Groupe de TD : " << groupe_TD_ << endl;
	cout << "Fichier photo : " << image_ << endl;

}

void Etudiant::sauver(ofstream& ofs) const
{
	ofs << "-------------------" << endl;
	ofs << nom_ << " ";
	ofs << prenom_ << endl;
	ofs << "Username : " << username_ << endl;
	ofs << "Groupe : " << groupe_TD_ << endl;
	ofs << "Lien de l'image : "<<image_ << endl;
	ofs << "Numéro de l'étudiant : " << numero_ << endl;
	if (present_) {
		ofs << "--> PRESENT " << endl;
	}
	else
	{
		ofs << "--> ABSENT" << endl;
	}


}
