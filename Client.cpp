/**
 * @file Client.cpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Client.hpp"

/**
 * @brief Construit une new Client:: Client object
 * 
 * @param arrivalTime 
 * @param bank 
 */
Client::Client(double arrivalTime, Bank* bank){
    _arrivalTime = arrivalTime;
    _bank = bank;
}

/**
 * @brief Renvoie l'heure d'arrivée du client
 * 
 * @return double 
 */
double Client::arrivalTime() {
    return _arrivalTime;
}

