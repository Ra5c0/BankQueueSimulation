/**
 * @file CashierRelease.hpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __CASHIER_RELEASE_HPP
#define __CASHIER_RELEASE_HPP

#include <iostream>

#include "Bank.hpp"
#include "Cashier.hpp"
#include "Client.hpp"
#include "Event.hpp"

class Cashier;

class CashierRelease: public Event {
protected:
    int _number;
    Cashier* _cashier;
    Client _client;
public:
    explicit CashierRelease(double, Cashier*, int, Client, Bank*);
    void process();
};

#endif
