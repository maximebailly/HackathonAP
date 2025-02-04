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
            if (carre == 0) {
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);   // Carré noir
                SDL_Rect rect { .x = i*BLOCK_SIZE, .y = j*BLOCK_SIZE, .w = BLOCK_SIZE, .h = BLOCK_SIZE };
                SDL_RenderFillRect(renderer, &rect); // Envoie le carré au renderer
            }
            if (carre == 1) {
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);   // Carré blanc
                SDL_Rect rect { .x = i*BLOCK_SIZE, .y = j*BLOCK_SIZE, .w = BLOCK_SIZE, .h = BLOCK_SIZE };
                SDL_RenderFillRect(renderer, &rect); // Envoie le carré au renderer
            }
            if (carre == 2) {
                SDL_SetRenderDrawColor(renderer, 0xFF, 0x5B, 0x3A, 0xFF);   // Carré orange
                SDL_Rect rect { .x = i*BLOCK_SIZE, .y = j*BLOCK_SIZE, .w = BLOCK_SIZE, .h = BLOCK_SIZE };
                SDL_RenderFillRect(renderer, &rect); // Envoie le carré au renderer
            }
            if (carre == 3) {
                SDL_SetRenderDrawColor(renderer, 0x99, 0x99, 0x99, 0xFF);   // Carré gris
                SDL_Rect rect { .x = i*BLOCK_SIZE, .y = j*BLOCK_SIZE, .w = BLOCK_SIZE, .h = BLOCK_SIZE };
                SDL_RenderFillRect(renderer, &rect); // Envoie le carré au renderer
            }
            if (carre == 4) {
                SDL_SetRenderDrawColor(renderer, 0x00, 0x87, 0x31, 0xFF);   // Carré vert
                SDL_Rect rect { .x = i*BLOCK_SIZE, .y = j*BLOCK_SIZE, .w = BLOCK_SIZE, .h = BLOCK_SIZE };
                SDL_RenderFillRect(renderer, &rect); // Envoie le carré au renderer
            }
            if (carre == 9) {
                SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);   // Carré vert
                SDL_Rect rect { .x = i*BLOCK_SIZE, .y = j*BLOCK_SIZE, .w = BLOCK_SIZE, .h = BLOCK_SIZE };
                SDL_RenderFillRect(renderer, &rect); // Envoie le carré au renderer
            }
        }
    }
}

void decouvre() {
    for (int i = joueur_y-1; i <= joueur_y+1; i++) {
        for (int j = joueur_x-1; j <= joueur_x+1; j++) {
            matrice_decouverte[i][j] = 1;
        }
    }
}
