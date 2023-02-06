/**
 * @file Event.hpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __EVENT_HPP
#define __EVENT_HPP

#include <set>

using namespace std;

class Bank;

class Event {
protected:
    Bank* _bank;
    double _time;
public:
    explicit Event(double, Bank*);

    virtual void process();
    double time() const;
//    bool operator<(const Event&) const;
};

#endif
