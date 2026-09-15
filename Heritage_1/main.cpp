#include <iostream>
#include "contenant.h"
#include "carton.h"
#include "caissedebouteilles.h"

using namespace std;

int main()
{
    cout << "Contenant --------- " <<endl;
    Contenant unContenant(5,10,2);
    cout << "Volume du contenant : "  << unContenant.CalculerVolume() << endl;

    cout << "Carton --------- " <<endl;
    Carton unCarton(3,3,3,5.5);
    cout << "Volume du carton : " << unCarton.CalculerVolume() << endl;
    cout << "Poids maxi du carton : " << unCarton.ObtenirPoidsMaxi() << endl;
    cout << "Hauteur du carton : " << unCarton.ObtenirHauteurCarton() << endl;

    cout << "Caisse de bouteilles --------------" << endl;
    CaisseDeBouteilles uneCaisseDeVin(25,17,31,6,75);
    cout << "Volume de vin : " << uneCaisseDeVin.CalculerVolume() << endl;
    Contenant * ptContenant;
    ptContenant = &uneCaisseDeVin;

    cout << "Volume de la caisse de vin : " << ptContenant->CalculerVolume() << endl;
    cout << "Volume de la caisse de vin : " << static_cast<Contenant>(uneCaisseDeVin).CalculerVolume() <<endl;
    cout << "Volume de la caisse de vin : " << uneCaisseDeVin.CalculerVolumeBrut() << endl;

    return 0;
}
