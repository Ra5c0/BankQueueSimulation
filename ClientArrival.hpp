/**
 * @file ClientArrival.hpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __CLIENT_ARRIVAL_HPP
#define __CLIENT_ARRIVAL_HPP

#include <iostream>

#include "Poisson.h"
#include "Bank.hpp"
#include "Client.hpp"
#include "Event.hpp"

class ClientArrival: public Event {
public:
    explicit ClientArrival(double, Bank*);
    void process() override;
};

#endif
