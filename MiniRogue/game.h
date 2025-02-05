#ifndef GAME_H
#define GAME_H
#include "visuals.h"

#endif //GAME_H

inline int tour = 0;
inline bool change = true;
inline bool game_on = false ;
inline int joueur_x, joueur_y;

inline std::array<std::array<int, W_WIDTH>, W_HEIGHT> matrice_decouverte;
inline std::array<std::array<int, W_WIDTH>, W_HEIGHT> plateau;
inline std::array<std::array<int, W_WIDTH>, W_HEIGHT> plateau_depart;
inline std::array<std::array<int, W_WIDTH>, W_HEIGHT> plateau_affiche; // Celui qu'on display vraiment

//Fonctions
bool is_valid(int arrx, int arry) ;
std::array<std::array<int, W_WIDTH>, W_HEIGHT> Plateau(std::array<std::array<int, W_WIDTH>, W_HEIGHT> plateau);
void placeRectangle(std::array<std::array<int, W_WIDTH>, W_HEIGHT>& plateau, int n, int m, int x, int y);
void ajout_piece(std::array<std::array<int, W_WIDTH>, W_HEIGHT>& plateau);
void mechant(std::array<std::array<int, W_WIDTH>, W_HEIGHT>& plateau);
void plateau_travail(std::array<std::array<int, W_WIDTH>, W_HEIGHT> &plateau);