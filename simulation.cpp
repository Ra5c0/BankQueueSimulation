/**
 * @file simulation.cpp
 * @author Oscar Gigon (gigonoscar@cy-tech.fr) & Yassine El Asri (elasriyass@cytech.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "simulation.hpp"

using namespace std;

/**
 * @brief Main
 * 
 * @return les stats de la simulation
 */
int main() {
    // Définitions des paramètres de simulation
    double expectedTime = 1000;
    int cashierNb = 3;
    double averageArrivalTime = 5;
    double* averageServiceTimes = new double[cashierNb];

    // Graine d'initialisation pour le générateur aléatoire de Poisson
    Poisson::init();

    // Génére des doubles aléatoires pour définir les temps de service moyens pour chaque caissier
    genRandomDoubles(15, 15, &averageServiceTimes, cashierNb);

    // Créer une banque avec des paramètres
    Bank bank(0, expectedTime, cashierNb, averageArrivalTime, averageServiceTimes);
    // Start the simulation
    bank.run();

    // Afficher les statistiques de la simulation
    bank.displayStats();
}

/**
 * @brief Génére des doubles aléatoires entre min et max dans un tableau
 * 
 */
void genRandomDoubles(double min, double max, double** arr, int arrSize) {
    uniform_real_distribution<double> unif(min, max);
    random_device rd;
    default_random_engine re(rd());
    for(int i=0 ; i<arrSize ; i++) {
        *(*arr+i) = unif(re);
    }
}
