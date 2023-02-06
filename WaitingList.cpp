/**
 * @file WaitingList.cpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "WaitingList.hpp"

/**
 * @brief Construit une new Waiting List:: Waiting List object
 * 
 */
WaitingList::WaitingList() {
    _number = -1;
    _currClients = 0;
    _maxClients = 0;
    _lastModifTime = 0;
    _timeClientSum = 0;

    _bank = nullptr;
}

/**
 * @brief Construit une new Waiting List:: Waiting List object
 * 
 * @param n 
 * @param bank 
 */
WaitingList::WaitingList(int n, Bank* bank): _number(n) {
    _currClients = 0;
    _maxClients = 0;
//    _lastModifTime = bank->time();
    _lastModifTime = 0;
    _timeClientSum = 0;

    _bank = bank;
}

/**
 * @brief Détruit Waiting List:: Waiting List object
 * 
 */
WaitingList::~WaitingList() = default;

/**
 * @brief Ajoute Client à WaitingList
 * 
 * @param c 
 */
void WaitingList::add(Client c) {
    addToAverage();

    _currClients ++;
    if(_currClients > _maxClients) {
        _maxClients = _currClients;
    }
    _clientList.push_back(c);
}

/**
 * @brief Supprime le premier client en attente de la file d'attente et le renvoie
 * 
 * @return Client 
 */
Client WaitingList::removeFirst() {
    addToAverage();

    _currClients --;
    Client c = _clientList.front();
    _clientList.pop_front();
    return c;
}

/**
 * @brief Renvoie si la file d'attente est vide
 * 
 * @return true 
 * @return false 
 */
bool WaitingList::isEmpty(){
    return _clientList.empty();
}

/**
 * @brief Renvoie la taille de la file d'attente
 * 
 * @return int 
 */
int WaitingList::size() {
    return _clientList.size();
}

/**
 * @brief Renvoie l'index de la file d'attente dans la banque
 * 
 * @return int 
 */
int WaitingList::number() {
    return _number;
}

/**
 * @brief Fonction pour ajouter (nb de client) * (temps passé avec son nb de clients) à la somme courante
 * 
 */
void WaitingList::addToAverage() {
    double timeDiff = _bank->time() - _lastModifTime;
    _timeClientSum += _currClients*timeDiff;
    _lastModifTime = _bank->time();
}

/**
 * @brief Renvoie la longueur maximale atteinte par la file d'attente
 * 
 * @return int 
 */
int WaitingList::maxLength() {
    return _maxClients;
}

/**
 * @brief Renvoie le nombre de client en attente en moyenne dans la file d'attente
 * 
 * @return double 
 */
double WaitingList::averageLength() {
    addToAverage();
    return _timeClientSum / _bank->time();
}
