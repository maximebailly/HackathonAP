#include "game.h"
using namespace std;
#include "visuals.h"


// Fonction pdt terme à terme
array<array<int, W_WIDTH>, W_HEIGHT> produit_termeterme(array<array<int, W_WIDTH>, W_HEIGHT> mat1, array<array<int, W_WIDTH>, W_HEIGHT> mat2) {
    array<array<int, W_WIDTH>, W_HEIGHT> mat3;
    for (int i = 0; i < W_HEIGHT; i++) {
        for (int j = 0; j < W_WIDTH; j++) {
            mat3[i][j] = mat1[i][j]*mat2[i][j];
        }
    }
    return mat3;
}

void set_color(int carre, bool gris) {
    if (gris) {
        if (carre == 0) {
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);   // Carré noir
        }
        else if (carre == 1) {
            SDL_SetRenderDrawColor(renderer, 0x7F, 0x7F, 0x7F, 0xFF);   // Carré blanc
        }
        else if (carre == 2) {
            SDL_SetRenderDrawColor(renderer, 0x7F, 0x2D, 0x1D, 0xFF);   // Carré orange
        }
        else if (carre == 3) {
            SDL_SetRenderDrawColor(renderer, 0x4C, 0x4C, 0x4C, 0xFF);   // Carré gris
        }
        else if (carre == 4) { // Porte pour passer d'une salle à l'autre
            SDL_SetRenderDrawColor(renderer, 0x00, 0x41, 0x15, 0xFF);   // Carré vert
        }
        else if (carre == 5) {
            SDL_SetRenderDrawColor(renderer, 0x7F, 0x4F, 0x25, 0xFF);   // Carré orange clair
        }
        else if (carre == 7) { // méchant
            SDL_SetRenderDrawColor(renderer, 0x3F, 0x00, 0x00, 0xFF);   // Carré bordeaux
        }
        else if (carre == 8) { // Piece d'or
            SDL_SetRenderDrawColor(renderer, 0x7F, 0x7F, 0x00, 0xFF);   // Carré jaune
        }
        else if (carre == 9) { // Player
            SDL_SetRenderDrawColor(renderer, 0x7F, 0x00, 0x00, 0xFF);   // Carré rouge
        }
    } else {
        if (carre == 0) {
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);   // Carré noir
        }
        else if (carre == 1) {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);   // Carré blanc
        }
        else if (carre == 2) {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x5B, 0x3A, 0xFF);   // Carré orange
        }
        else if (carre == 3) {
            SDL_SetRenderDrawColor(renderer, 0x99, 0x99, 0x99, 0xFF);   // Carré gris
        }
        else if (carre == 4) { // Porte pour passer d'une salle à l'autre
            SDL_SetRenderDrawColor(renderer, 0x00, 0x87, 0x31, 0xFF);   // Carré vert
        }
        else if (carre == 5) {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x9E, 0x49, 0xFF);   // Carré orange clair
        }
        else if (carre == 7) { // méchant
            SDL_SetRenderDrawColor(renderer, 0x7F, 0x00, 0x00, 0xFF);   // Carré bordeaux
        }
        else if (carre == 8) { // Piece d'or
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);   // Carré jaune
        }
        else if (carre == 9) { // Player
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);   // Carré rouge
        }
    }


}

// 0 : case noire / inconnue ou vide
// 1 : case salle / découverte
// 2 : murs
// 3 : couloirs
// 4 : porte verte
// 9 : joueur
// Envoie au renderer les données du plateau
void dessine_plateau(array<array<int, W_WIDTH>, W_HEIGHT> plateau) {
    for (int i = 0; i < W_WIDTH; i++) { // Colonne x
        for (int j = 0; j < W_HEIGHT; j++) { // Ligne y
            int carre = plateau[j][i];
            if (carre >= 100) {
                set_color(carre/100, true);
            } else {
                set_color(carre, false);
            }

            SDL_Rect rect { .x = i*BLOCK_SIZE, .y = j*BLOCK_SIZE, .w = BLOCK_SIZE, .h = BLOCK_SIZE };
            SDL_RenderFillRect(renderer, &rect); // Envoie le carré au renderer
        }
    }
}

void decouvre() {
    for (int i = joueur_y-2; i <= joueur_y+2; i++) {
        for (int j = joueur_x-2; j <= joueur_x+2; j++) {
            if (i>=0 && i<45 && j>=0 && j<30) {}
            matrice_decouverte[i][j] = 100;
        }
    }

    for (int i = joueur_x-1; i <= joueur_x+1; i++) {
        for (int j = joueur_y-1; j <= joueur_y+1; j++) {
            if (i>=0 && i<45 && j>=0 && j<30) {}
            matrice_decouverte[j][i] = 1;
        }
    }
}
