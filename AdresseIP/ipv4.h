/**
 * @file      ipv4.h
 * @author    Philippe CRUCHET <pcruchet@ac-nantes.fr>
 * @date      2024-09-15
 * @version   1.0
 * @brief     Déclaration de la classe IPv4.
 *
 * @details   Ce fichier contient l'interface de la classe IPv4
 *            permettant de manipuler les adresses IPv4
 */

#ifndef _IPV4_H
#define _IPV4_H

/**
 * @class  IPv4
 * @brief  Représente une adresse au format IPv4.
 *
 * @details La classe IPv4 permet d'obtenir l'adresse réseau d'une adresse IPv4
 *          fournit sous la forme décimale pointé suivit du CIDR ou du masque
 *          de réseau.
 *          Cette classe permet d'obtenir le masque et l'adresse de diffusion
 *          utilisé pour ce réseau.
 *
 * @note    L'adresses et le masque sont stockées sous forme d'un tableau d'octets
 *          non signé.
 *
 * Exemple d'utilisation :
 * @code
 *   unsigned char adresse[4]= {192,168,1,1};
 *   unsigned char reseau[4];
 *   IPv4 uneAdresse(adresse, 24);
 *   uneAdresse.ObtenirAdresseReseau(reseau);
 * @endcode
 */
class IPv4
{
  private:
    /// Tableau pour stocker l'adresse allouer dynamiquement
    unsigned char * adresse;
    /// Tableau pour stocker l'adresse allouer dynamiquement
    unsigned char * masque ;
    void CalculerMasque(unsigned char _cidr);
  public:
    IPv4(const unsigned char * _adresse, const unsigned char _cidr);
    IPv4(const unsigned char * _adresse, const unsigned char * _masque);
    ~IPv4();
    void ObtenirMasque(unsigned char * _masque);
    void ObtenirAdresseReseau(unsigned char * _reseau);
    void ObtenirAdresseDiffusion(unsigned char * _diffusion);
};
#endif
