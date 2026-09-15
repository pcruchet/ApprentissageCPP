#ifndef CAISSEDEBOUTEILLES_H
#define CAISSEDEBOUTEILLES_H

#include <iostream>
#include "contenant.h"

using namespace std;

class CaisseDeBouteilles : public Contenant
{
private:
    int nbBouteilles;
    int contenance;
public:
    CaisseDeBouteilles(const int _largeur, const int _hauteur, const int _profondeur, const int _nbBouteilles, const int _contenance);
    ~CaisseDeBouteilles();
    int CalculerVolume();
    int CalculerVolumeBrut();
};

#endif // CAISSEDEBOUTEILLES_H
