//
// Created by maxim on 04/02/2025.
//

#ifndef GAME_H
#define GAME_H
#include "visuals.h"

#endif //GAME_H

inline int tour = 0;
inline bool change = true;
inline bool game_on = false ;
inline int joueur_x = 2, joueur_y = 2;

inline std::array<std::array<int, W_WIDTH>, W_HEIGHT> matrice_decouverte;
inline std::array<std::array<int, W_WIDTH>, W_HEIGHT> plateau;
inline std::array<std::array<int, W_WIDTH>, W_HEIGHT> plateau_affiche;

//Fonctions
bool is_valid(int arrx, int arry) ;