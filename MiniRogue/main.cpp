#include <iostream>
#include <array>
#include <list>
#include "SDL.h"
#include "game.h"
#include "visuals.h"

using namespace std;

void renderState() ;
void render();


// renvoie "true" pour quitter le jeu
bool handleEvents() {

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return true;
        } else if (e.type == SDL_KEYDOWN) {
            int keyCode = e.key.keysym.scancode;
            if (keyCode == SDL_SCANCODE_ESCAPE) {
              return true;
            }
            if (keyCode == 40) { // Entree
                // Interaction avec environnement
                cout << "Entrée appuyé" << endl;
            }
            if (keyCode == 79) { //Droite
                // Si mouvement possible
                if (is_valid(joueur_x+1,joueur_y)) {
                    // TODO : remplacer l'ancienne case du joueur par la case du fond qui va bien
                    // Donc il faut avoir une matrice qui ne contient que les fonds ? Sans le perso ni les items, ennemis etc
                    plateau_decouvert[joueur_y][joueur_x]= 0;
                    // Maj pos joueur
                    joueur_x+=1;
                    plateau_decouvert[joueur_y][joueur_x]= 9;
                    change = true;
                }
            }
            if (keyCode == 80) { //Gauche
                // Si mouvement possible
                if (is_valid(joueur_x-1,joueur_y)) {
                    plateau_decouvert[joueur_y][joueur_x]= 0;
                    // Maj pos joueur
                    joueur_x-=1;
                    plateau_decouvert[joueur_y][joueur_x]= 9;
                    change = true;
                }
            }
            if (keyCode == 81) { //Bas
                // Si mouvement possible
                if (is_valid(joueur_x,joueur_y+1)) {
                    plateau_decouvert[joueur_y][joueur_x]= 0;
                    // Maj pos joueur
                    joueur_y+=1;
                    plateau_decouvert[joueur_y][joueur_x]= 9;
                    change = true;
                }
            }
            if (keyCode == 82) { //Haut
                // Si mouvement possible
                if (is_valid(joueur_x,joueur_y-1)) {
                    plateau_decouvert[joueur_y][joueur_x]= 0;
                    // Maj pos joueur
                    joueur_y-=1;
                    plateau_decouvert[joueur_y][joueur_x]= 9;
                    change = true;
                }
            }
        }
        else if (SDL_MOUSEBUTTONDOWN == e.type) {
            // Si le jeu est lancé
            int x, y ;
            int xf, yf ;

            if (SDL_BUTTON_LEFT == e.button.button) {
                SDL_GetMouseState(&x,&y);
            }
            int case_x, case_y ;
        }

            // Le jeu n'est pas encore lancé
        else {
            int x, y ;
            if (SDL_BUTTON_LEFT == e.button.button) {
                SDL_GetMouseState(&x,&y);
            }
        }
    }
    return false;
}


bool updateState() {
  return false;
}


void renderState() {
    // Si le jeu vient de commencer, on appelle la fonction game_init() pour def pieces de depart
    if (tour == 0) {
        // afficher ecran depart
        // Pour tester la conversion
        for (int i=0; i<W_HEIGHT; i++) {
            for (int j=0; j<W_WIDTH; j++) {
                plateau_decouvert[i][j] = 1; // 0,1,2,3,4,9
            }
        }

        // Appeler la fonction qui initalise un plateau

        // Le render
        dessine_plateau(plateau_decouvert);
        render();

        change = false; // Changement effectué donc on arrête de boucler sur le rendu graphique
        tour+=1;
        }
    //Sinon on dessine le plateau
    else {
        dessine_plateau(plateau_decouvert); // Dessine les éléments du plateau connu par le joueur
        render();
    }
}

void render() {
    SDL_RenderPresent(renderer);
}


int SDL_main(int argc, char *argv[]) {

    // Initialise SDL et ouvre une fenêtre
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow(
        "MiniRogue",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        W_WIDTH * BLOCK_SIZE,
        W_HEIGHT * BLOCK_SIZE,
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // notre "render loop" -> on boucle à l'infini tant que l'utilisateur n'a pas demandé à quitter le jeu
    for (bool quit = false; !quit;) {
        // Gestion des touches
        quit = handleEvents();

        if (change == true) { // Si y'a un changement dans le jeu
            // on efface l'écran actuel
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
            SDL_RenderClear(renderer);
            // on "dessine" nos éléments de jeu
            renderState();
        }

        quit = quit || updateState(); // true or false bool
    }

    // à la fin du jeu on ferme proprement la fenêtre et on libère les ressources utilisées par SDL
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0 ;
}