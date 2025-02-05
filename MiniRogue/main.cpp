#include <iostream>
#include <array>
#include <list>
#include <random>
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

            // Interaction avec environnement
            if (keyCode == 40) { // Entree
                cout << plateau_depart[joueur_y][joueur_x] << endl;
                if (plateau_depart[joueur_y][joueur_x] == 8) { // Pièce d'or
                    cout << "Vous ramassez une piece d'or !" << endl;
                    plateau_depart[joueur_y][joueur_x] = 1;
                }
                else if (plateau_depart[joueur_y][joueur_x] == 7 || plateau_depart[joueur_y-1][joueur_x] == 7
                    || plateau_depart[joueur_y+1][joueur_x] == 7 || plateau_depart[joueur_y][joueur_x-1] == 7
                    || plateau_depart[joueur_y][joueur_x+1] == 7) { // Méchant
                    cout << "Vous tapez l'ennemi !!" << endl;
                    plateau_depart[joueur_y][joueur_x] = 1;
                }
            }
            if (keyCode == 79) { //Droite
                // Si mouvement possible
                if (is_valid(joueur_x+1,joueur_y)) {
                    plateau[joueur_y][joueur_x]= plateau_depart[joueur_y][joueur_x];
                    // Maj pos joueur
                    joueur_x+=1;
                    decouvre();
                    plateau[joueur_y][joueur_x]= 9;
                    change = true;
                }
            }
            if (keyCode == 80) { //Gauche
                // Si mouvement possible
                if (is_valid(joueur_x-1,joueur_y)) {
                    plateau[joueur_y][joueur_x]= plateau_depart[joueur_y][joueur_x];
                    // Maj pos joueur
                    joueur_x-=1;
                    decouvre();
                    plateau[joueur_y][joueur_x]= 9;
                    change = true;
                }
            }
            if (keyCode == 81) { //Bas
                // Si mouvement possible
                if (is_valid(joueur_x,joueur_y+1)) {
                    plateau[joueur_y][joueur_x]= plateau_depart[joueur_y][joueur_x];
                    // Maj pos joueur
                    joueur_y+=1;
                    decouvre();
                    plateau[joueur_y][joueur_x]= 9;
                    change = true;
                }
            }
            if (keyCode == 82) { //Haut
                // Si mouvement possible
                if (is_valid(joueur_x,joueur_y-1)) {
                    plateau[joueur_y][joueur_x]= plateau_depart[joueur_y][joueur_x];
                    // Maj pos joueur
                    joueur_y-=1;
                    decouvre();
                    plateau[joueur_y][joueur_x]= 9;
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
        // Creer la matrice de découverte
        for (int i=0; i<W_HEIGHT; i++) {
            for (int j=0; j<W_WIDTH; j++) {
                // Rien n'est encore découvert
                matrice_decouverte[i][j] = 0;
            }
        }
        // Creer le plateau de jeu
        plateau = Plateau(plateau);
        plateau_travail(plateau);
        plateau_depart = plateau;

        // Place aléatoirement le joueur dans une salle
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib_height(0, W_HEIGHT - 1);
        std::uniform_int_distribution<> distrib_width(0, W_WIDTH - 1);

        while (plateau[joueur_y][joueur_x] != 1) {
            joueur_y = distrib_height(gen);
            joueur_x = distrib_width(gen);
        }

        // Eclairer ce qui se trouve autour du joueur
        decouvre();

        // Le render
        plateau_affiche = produit_termeterme(plateau,matrice_decouverte);
        dessine_plateau(plateau_affiche);
        render();

        change = false; // Changement effectué donc on arrête de boucler sur le rendu graphique
        tour+=1;
        }
    //Sinon on dessine le plateau
    else {
        plateau_affiche = produit_termeterme(plateau,matrice_decouverte);
        dessine_plateau(plateau_affiche); // Dessine les éléments du plateau connu par le joueur
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