#include <sstream>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "FiseTSE.h"

using namespace std;

FiseTSE::FiseTSE(string nom_fise, string lien)
{
	nom_fichier_ = lien;
	nom_fise_ = nom_fise;
	
}


void FiseTSE::afficher()
{
	cout << "Filiere : " << nom_fise_ << " " <<endl;
	cout << "Lien du fichier : " << nom_fichier_ << endl;


}


void FiseTSE :: decoupageInfosEtudiants(string fichier, vector<string> numero, vector<string> username, vector<string> nom, vector<string> prenom, vector<string> groupe_TD, vector<string> image)



void FiseTSE :: choixFise() {
	string choix, Fise, Groupe;
	char delimiter = '-';
	bool flag = true;
	array <string, 3> myList1 = { "FISE1", "FISE2", "FISE3" };
	array <string, 5> myList2 = { "GrA", "GrB", "GrC","GrD","GrE" };

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
		getline(sstream, Groupe);
		cout << Groupe << endl;
		// Si Fise et Groupe font partie de myList(1 ou 2) alors l'utilisateur a rentré ce qui était demandé, on sort donc de la boucle
		if ((find(begin(myList1), end(myList1), Fise) != end(myList1)) && (find(begin(myList2), end(myList2), Groupe) != end(myList2)))
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

	nom_fise_ = Fise;
	nom_fichier_ = Fise + ".csv";
}