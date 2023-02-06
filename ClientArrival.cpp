/**
 * @file ClientArrival.cpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "ClientArrival.hpp"

using namespace std;

/**
 * @brief Construit une new Client Arrival:: Client Arrival object
 * 
 * @param t 
 * @param b 
 */
ClientArrival::ClientArrival(double t, Bank* b): Event(t, b) {}

/**
 * @brief Processus de l'événement d'arrivée du client
 * 
 */
void ClientArrival::process() {
    // Créer un client (en utilisant le temps moyen)
    Client client(_time, _bank);

    Cashier* cashier = _bank->freeCashier();
    // S'il n'y a pas de caissier libre, ajoutez le client à la file d'attente la plus triée
    if(cashier == nullptr) {
        WaitingList* wl = _bank->shortestQueue();
        wl->add(client);
        cout << "New client waits at line " << wl->number() << endl;
    }
    // Sinon, demandez au caissier de servir le client
    else {
        // Pour les statistiques à la fin de la simulation
        _bank->addWaitingTime(0);

        cout << "New client served by " << cashier->number() << endl;
        cashier->serve(client); 
    }

    // Créer le prochain événement d'arrivée du client s'il ne dépasse pas l'heure prévue de la simulation
    double nextTime = _bank->time()+Poisson::next(_bank->averageArrivalTime());
    if(nextTime < _bank->expectedTime()) {
        ClientArrival *ca = new ClientArrival(nextTime, _bank);
        _bank->addEvent(ca);
    }
}
