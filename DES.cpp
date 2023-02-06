/**
 * @file DES.cpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "DES.hpp"

/**
 * @brief Construit une new DES::DES object
 * 
 * @param start 
 */
DES::DES(double start) {
    _time = start;
}

/**
 * @brief Détruit the DES::DES object
 * 
 */
DES::~DES() {
    _events.clear();
}

/**
 * @brief Remplacé par la banque
 * 
 */
void DES::run() {
}

/**
 * @brief Ajoute un événement à un ensemble d'événements
 * 
 * @param e 
 */
void DES::addEvent(Event* e) {
    _events.insert(e);
}

/**
 * @brief Renvoie l'heure actuelle de la simulation
 * 
 * @return double 
 */
double DES::time() {
    return _time;
}
