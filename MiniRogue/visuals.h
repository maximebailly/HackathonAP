//
// Created by maxim on 04/02/2025.
//
using namespace std;
#ifndef VISUALS_H
#define VISUALS_H

#include <iostream>
#include <array>
#include "SDL.h"

// le renderer est utilisé par SDL et passé à toutes les fonctions
inline SDL_Renderer *renderer;
const int W_WIDTH = 45;
const int W_HEIGHT = 30;
const int BLOCK_SIZE = 20; // Pour un meilleur affichage des chiffres et des lettres

// Fonctions
void dessine_plateau(array<array<int, W_WIDTH>, W_HEIGHT> plateau);
array<array<int, W_WIDTH>, W_HEIGHT> produit_termeterme(array<array<int, W_WIDTH>, W_HEIGHT> mat1, array<array<int, W_WIDTH>, W_HEIGHT> mat2);




#endif //VISUALS_H
