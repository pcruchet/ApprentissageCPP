#include "carton.h"


Carton::Carton(const int _largeur, const int _hauteur, const int _profondeur, const float _poidsMaxi)
  : Contenant(_largeur, _hauteur, _profondeur)
  , poidsMaxi(_poidsMaxi)
{
    cout << "constructeur de la classe Carton" << endl ;
}

Carton::~Carton()
{
    cout << "desstructeur de la classe Carton" << endl ;
}


float Carton::ObtenirPoidsMaxi()
{
    return poidsMaxi;
}

int Carton::ObtenirHauteurCarton()
{
    return hauteur;
}
