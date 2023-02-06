/**
 * @file DES.hpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __DES_HPP
#define __DES_HPP

#include <iostream>
#include <set>

#include "Event.hpp"

using namespace std;

class Event;

/**
 * @brief Structure utilisée pour comparer deux événements pour l'ensemble d'événements
 * 
 */
struct EventComp {
    bool operator()(const Event* lhs, const Event* rhs) const  {
        /* Les événements sont comparés à l'aide de leur temps d'exécution */
        return (lhs->time() < rhs->time());
    }
};

class DES {
protected:
    double _time;

    set<Event*, EventComp> _events;
    set<Event*, EventComp>::iterator _eventIterator;

public:
    explicit DES(double);
    virtual ~DES();

    virtual void run();
    void addEvent(Event*);
    double time();
};

#endif
