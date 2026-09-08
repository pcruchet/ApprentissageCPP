/************************************************************************************
/*!
    \file         main.cpp
    \author    	  Philippe CRUCHET (Touchard Wahington le Mans)
    \license      BSD (see license.txt)
    \date         08 septembre 2017
    \brief        Corrigé du TD1 - Les flux entrant en C++
    \details      Mise en oeuvre des flux entrant et sortant sur fichier
    \version  	  v1.0 - First release
*/
/*********************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <errno.h>

using namespace std;

int main()
{
    string inputFile;
    string pays;
    char tmp;
    int nbOr;
    int nbArgent;
    int nbBronze;

    cout << "Entrer le nom du fichier à lire : ";

    cin >> inputFile;

    ifstream fichier(inputFile.c_str()); //Creation du flux en lecture du fichier
    if (fichier.fail())
        cerr << "Erreur lors de l'ouverture du fichier" << endl;

    else
    {
        ofstream output("nouveau.txt");
        //affichage de la premiere ligne du tableau
        output << setfill('-');
        output << "+" << setw(18) << "+" << setw(9) << "+" << setw(9) << "+" << setw(9) << "+" << endl;
        output << setfill(' ');

        while(fichier)
        {
            fichier >> pays >> nbOr >> nbArgent >> nbBronze; //recuperation des valeurs
            if(fichier)//Si le fichier peut etre lu
            {
                //affichage des lignes du tableau
                output << "| " << left << setw(16) << pays << "|" << right << setw(7) << nbOr << " |" << right << setw(7) << nbArgent << " |" << right << setw(7) << nbBronze << " |" << endl;
            }
        }
        //Affichage du bas du tableau.
        output << setfill('-');
        output << "+" << setw(18) << "+" << setw(9) << "+" << setw(9) << "+" << setw(9) << "+" << endl;
    }
    return 0;
}