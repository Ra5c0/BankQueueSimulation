/**
 * @file Cashier.cpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Cashier.hpp"

using namespace std;

/**
 * @brief Construit une new Cashier:: Cashier object
 * 
 */
Cashier::Cashier(): _currentClient(Client(-1, nullptr)) {
    _number = -1;
    _averageServiceTime = -1;
    _clientNb = 0;
    _servingClient = false;
    _occupationTime = 0;
    _bank = nullptr;
}

/**
 * @brief Construit une new Cashier:: Cashier object
 * 
 * @param averageTime 
 * @param n 
 * @param b 
 */
Cashier::Cashier(double averageTime, int n, Bank* b): _currentClient(Client(-1, b)) {
    _number = n;
    _averageServiceTime = averageTime;
    _clientNb = 0;
    _servingClient = false;
    _occupationTime = 0;
    _bank = b;
}

/**
 * @brief Détruit Cashier:: Cashier object
 * 
 */
Cashier::~Cashier() = default;

double Cashier::averageServiceTime(){
    return _averageServiceTime;
}

int Cashier::clientNb(){
    return _clientNb;
}

int Cashier::number() {
    return _number;
}

bool Cashier::isFree() {
    return !_servingClient;
}

void Cashier::serve(Client c) {
    _clientNb ++;
    _servingClient = true;
    _currentClient = c;
    double duration = Poisson::next(_averageServiceTime);
    double eventTime = _bank->time()+duration;

    // Pour les statistiques
    // _bank->addWaitingTime(duration);
    _occupationTime += duration;

    // Ajoute un événement pour arrêter de servir le client
    _bank->addEvent(new CashierRelease(eventTime, this, _number, c, _bank));
}

void Cashier::wait() {
    _servingClient = false;
    _currentClient = Client(-1, nullptr);
}

double Cashier::occupationRate() {
    return (_occupationTime/_bank->time());
}
