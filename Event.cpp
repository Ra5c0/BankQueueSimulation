/**
 * @file Event.cpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Event.hpp"

#include <iostream>

/**
 * @brief Construit une new Event:: Event object
 * 
 * @param time 
 * @param bank 
 */
Event::Event(double time, Bank* bank) {
    _time = time;
    _bank = bank;
}

/**
 * @brief Déroulement de l'événement
 *        Remplacé par ClientArrival & CashierRelease
 * 
 */
void Event::process() {
}

/**
 * @brief Renvoie l'heure de l'événement
 * 
 * @return double 
 */
double Event::time() const {
    return _time;
}
