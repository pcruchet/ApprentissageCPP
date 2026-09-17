/**
 * @file      ipv4.cpp
 * @author    Philippe CRUCHET <pcruchet@ac-nantes.fr>
 * @date      2024-09-15
 * @version   1.0
 * @brief     Implémentation de la classe IPv4.
 *
 * @details   Contient le corps de toutes les méthodes déclarées dans
 *            ipv4.h. Voir ce fichier pour la documentation des
 *            attribut sde la classe.
 */
#include "ipv4.h"

/**
 * @brief IPv4::IPv4 Construit un objet IPv4 avec une valeur initiale.
 * @param _adresse  Adresse manipulée au format décimal pointé
 * @param _cidr     cidr sous la forme d'un entier sur 8 bits non signé
 */
IPv4::IPv4(const unsigned char * _adresse,const unsigned char _cidr)
{
    adresse = new unsigned char [4];
    masque  = new unsigned char [4];
    for(int indice = 0 ; indice < 4 ; indice++)
        adresse[indice] = _adresse[indice];
    if(_cidr <= 32)
        CalculerMasque(_cidr);
}

/**
 * @brief IPv4::IPv4
 * @details Surcharge du constructeur un objet IPv4 avec une valeur initiale.
 * @param _adresse  Adresse manipulée au format décimal pointé
 * @param _masque   Masque au format décimal pointé
 */
IPv4::IPv4(const unsigned char * _adresse,const unsigned char * _masque)
{
    adresse = new unsigned char [4];
    masque  = new unsigned char [4];
    for(int indice = 0 ; indice < 4 ; indice++)
    {
        adresse[indice] = _adresse[indice];
        masque[indice]  = _masque[indice];
    }
}

/**
 * @brief IPv4::~IPv4
 * @details Destructeur de la classe, libère la mémoire allouée
 */
IPv4::~IPv4()
{
    delete [] adresse;
    delete [] masque ;
}
/**
 * @brief IPv4::CalculerMasque
 * @details Construit un masque de sous réseau à partir du CIDR
 * @param _cidr valeur du cidr en octet non signé
 *
 * @see Appeler par le constructeur recevant un CIDR pour calculer le masque
 */
void IPv4::CalculerMasque(unsigned char _cidr)
{
    int indice ;
    // Le masque est remis à 0 -> 0.0.0.0
    for(indice = 0 ; indice < 4 ; indice++)
        masque[indice] = 0 ;
    indice = 0;
    // tant que le cidr est un multiple de 8
    while(_cidr >= 8)
    {
        masque[indice++] = 255 ;
        _cidr -= 8 ;
    }
    // Complément pour la fin du cidr (<8)
    unsigned char puissance = 128 ;
    while(_cidr-- > 0) // Après le test la variable _cidr est décrémentée
    {   // les puissances de 2 sont ajoutées à l'octet par valeur décroissante
        masque[indice] += puissance ;
        puissance /=2 ;
    }
}

/**
 * @brief IPv4::ObtenirMasque
 * @details Complète le tableau _masque passé sous forme de paramètre de sortie
 * @param _masque valeur du masque mis à jour
 *
 * @pre Le tableau _masque doit être alloué avant l'appel
 */
void IPv4::ObtenirMasque(unsigned char * _masque)
{
    for(int indice = 0 ; indice < 4 ; indice++)
        _masque[indice] = masque[indice];
}

/**
 * @brief IPv4::ObtenirAdresseReseau
 * @details Complète le tableau _reseau passé sous forme de paramètre de sortie
 * @param _reseau valeur de l'adresse réseau mis à jour
 */
void IPv4::ObtenirAdresseReseau(unsigned char * _reseau)
{
    for(int indice = 0 ; indice < 4 ; indice++)
        _reseau[indice] = adresse[indice] & masque[indice] ;
}

/**
 * @brief IPv4::ObtenirAdresseDiffusion
 * @details fourni l'adresse de diffusion pour le réseau en question
 * @param _diffusion valeur de l'adresse de diffusion paramètre de sortie
 *
 * @pre Le tableau _diffusion doit être alloué avant l'appel
 */
void IPv4::ObtenirAdresseDiffusion(unsigned char *_diffusion)
{
    unsigned char adresseDuReseau[4];
    ObtenirAdresseReseau(adresseDuReseau);
    for(int indice = 0 ; indice < 4 ; indice++)
        _diffusion[indice] = adresseDuReseau[indice] | ~masque[indice] ;
}