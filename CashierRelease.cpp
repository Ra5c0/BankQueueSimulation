/**
 * @file CashierRelease.cpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "CashierRelease.hpp"

using namespace std;

/**
 * @brief Construit une new Cashier Release:: Cashier Release object
 * 
 * @param t 
 * @param ca 
 * @param n 
 * @param cl 
 * @param b 
 */
CashierRelease::CashierRelease(double t, Cashier* ca, int n, Client cl, Bank* b): Event(t, b), _cashier(ca), _client(cl) {
    _number = n;
}

/**
 * @brief Processus de l'événement CashierRelease
 * 
 */
void CashierRelease::process() {
    // Si la liste d'attente n'est pas vide
    if(_bank->waitingLists()[_number].size()>0) {
        cout << "Cashier " << _cashier->number() << " serves next client" << endl;
        // Prendre le 1er client en attente dans la bonne file d'attente
        Client c = _bank->waitingLists()[_number].removeFirst();

        // Statistiques
        _bank->addWaitingTime(_bank->time() - c.arrivalTime());

        // Demandez au caissier de le servir
        _cashier->serve(c);
    }
    // Sinon, caissier attend
    else {
        cout << "Cashier " << _cashier->number() << " waits" << endl;
        _cashier->wait();
    }
}
