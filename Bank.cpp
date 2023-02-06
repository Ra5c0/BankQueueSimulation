/**
 * @file Bank.cpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Bank.hpp"

using namespace std;

/**
 * @brief Construit une new Bank:: Bank object
 * 
 * @param start 
 * @param expectedTime 
 * @param cashierNb 
 * @param averageArrivalTime 
 * @param averageServiceTimes 
 */
Bank::Bank(double start, double expectedTime, int cashierNb, double averageArrivalTime, double* averageServiceTimes)
    : DES(start) {
    // Attributs d'initialisation
    _expectedTime = expectedTime;
    _cashierNb = cashierNb;
    _averageArrivalTime = averageArrivalTime;

    // Créer des caissiers et des files d'attente
    _cashiers = new Cashier[cashierNb];
    _waitingLists = new WaitingList[cashierNb];
    for(int i=0 ; i<cashierNb ; i++) {
        _waitingLists[i] = WaitingList(i, this);
        _cashiers[i] = Cashier(averageServiceTimes[i], i, this);
    }

    // Créer un premier événement d'arrivée
    ClientArrival *ca = new ClientArrival(0.11111, this);
    addEvent(ca);
}

/**
 * @brief Détruit Bank:: Bank object
 * 
 */
Bank::~Bank() {
    delete [] _cashiers;
    delete [] _waitingLists;
}

void Bank::run() {
    // Pour chaque événement
    for(_eventIterator = _events.begin() ; _eventIterator != _events.end() ; ++_eventIterator) {
        Event *e = *_eventIterator;
        // Changer l'heure actuelle de la simulation à l'heure de l'événement
        _time = e->time();
        cout << _time << ":  \t";
        // Traiter l'événement
        e->process();
    }
}

/**
 * @brief Renvoie l'heure d'arrivée moyenne
 * 
 * @return double 
 */
double Bank::averageArrivalTime() {
    return _averageArrivalTime;
}

/**
 * @brief Renvoie l'heure prévue de la simulation
 * 
 * @return double 
 */
double Bank::expectedTime() {
    return _expectedTime;
}

/**
 * @brief Renvoie le nombre de caissiers dans la banque
 * 
 * @return int 
 */
int Bank::cashierNb() {
    return _cashierNb;
}

/**
 * @brief Renvoie un pointeur vers le premier caissier en attente de servir les clients (de 0 à n). S'il n'y a pas de caissier libre, renvoie 0
 * 
 * @return Cashier* 
 */
Cashier* Bank::freeCashier() {
    // Parcourez les caissiers, s'il y en a un de libre, renvoyez-le
    for(int i=0 ; i < _cashierNb ; i++) {
        if(_cashiers[i].isFree()) {
            return &(_cashiers[i]);
        }
    }

    return nullptr;
}

/**
 * @brief Retourne les listes d'attente
 * 
 * @return WaitingList* 
 */
WaitingList* Bank::waitingLists() {
    return _waitingLists;
}

/**
 * @brief Renvoie un pointeur vers la liste d'attente la plus courte (de 0 à n)
 * 
 * @return WaitingList* 
 */
WaitingList* Bank::shortestQueue() {
    int minIndex = 0;
    int min = _waitingLists[minIndex].size();
    // Iterate through the waiting lists
    for(int i=1 ; i < _cashierNb ; i++) {
        // If a waiting list is shorter
        if(_waitingLists[i].size() < min) {
            // Store the index for this one
            minIndex = i;
            min = _waitingLists[i].size();
        }
    }
    
    return &(_waitingLists[minIndex]);
}

void Bank::addWaitingTime(double t) {
    _waitingTimes.push_back(t);
}

/**
 * @brief Renvoie la durée réelle de la simulation
 * 
 * @return double 
 */
double Bank::realDuration() {
    return _time;
}

/**
 * @brief Afficher les statistiques de la simulation
 * 
 */
void Bank::displayStats() {
    cout << "=============\nResultats de la simulation:" << endl << endl;

    cout << "PARAMETRES D'ENTREE:" << endl;
    cout << "La simulation a une duree prevue de " << _expectedTime << endl;
    cout << "Dans la banque, " << _cashierNb << " caissiers servent les clients en moyenne sur une duree de : [ ";
    for(int i=0 ; i<_cashierNb ; i++) {
        cout << _cashiers[i].averageServiceTime() << " ";
    }
    cout << "] (1 valeur pour chaque caissier)" << endl;
    cout << "Les clients arrivent en moyenne toutes les " << _averageArrivalTime << " unites de temps" << endl << endl;

    // Statistiques de la simulation
    cout << "RESULTATS EN SORTIE:" << endl;
    cout << "La simulation a reellement dure " << _time << endl << endl;

    // Statistiques des caissiers
    cout << "Les caissiers ont ete occupes [ ";
    for(int i=0 ; i<_cashierNb ; i++) {
        cout << _cashiers[i].occupationRate()*100 << " ";
    }
    cout << "] % de leur temps" << endl << endl;

    // Statistiques des clients
    cout << "[ ";
    for(int i=0 ; i<_cashierNb ; i++) {
        cout << _cashiers[i].clientNb() << " ";
    }
    cout << "] clients ont ete servis sur la duree totale de la simulation" << endl;
    cout << "Il y a donc eu " << _waitingTimes.size() << " clients servis au total" << endl;

    cout << "Les clients ont attendu en moyenne ";
    double sum = 0;
    for (vector<double>::iterator it = _waitingTimes.begin() ; it != _waitingTimes.end(); ++it) {
        sum += *it;
    }
    cout << (sum/_waitingTimes.size()) << " unites de temps" << endl << endl;

    // Statistiques de la file d'attente
    cout << "Les files ont atteint une taille maximale de [ ";
    int max = _waitingLists[0].maxLength();
    for(int i=0 ; i<_cashierNb ; i++) {
        cout << _waitingLists[i].maxLength() << " ";
        if(_waitingLists[i].maxLength() > max) {
            max = _waitingLists[i].maxLength();
        }
    }
    cout << "] clients" << endl;
    cout << "Soit un maximum de " << max << " clients, toutes files confondues" << endl;

    cout << "Les files ont eu en moyenne [ ";
    sum = 0;
    for(int i=0 ; i<_cashierNb ; i++) {
        cout << _waitingLists[i].averageLength() << " ";
        sum += _waitingLists[i].averageLength();
    }
    cout << "] clients" << endl;
    cout << "Soit un moyenne de " << (sum/_cashierNb) << " clients, toutes files confondues" << endl;
}
