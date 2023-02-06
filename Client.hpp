/**
 * @file Client.hpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __CLIENT_HPP
#define __CLIENT_HPP

class Bank;

class Client {
protected:
    double _arrivalTime;
    Bank* _bank;
public:
    explicit Client(double, Bank*);

    double arrivalTime();
};

#endif
