/**
 * @file simulation.hpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __SIMULATION_HPP
#define __SIMULATION_HPP

#include <iostream>
#include <set>
#include <random>

#include "Poisson.h"
#include "Bank.hpp"
#include "Event.hpp"

void genRandomDoubles(double min, double max, double** arr, int arrSize);
void displayStats(Bank);

#endif
