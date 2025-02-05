#include <random>
#include <iostream>
#include <array>
#include <vector>

// Définir les dimensions de la matrice
const int W_WIDTH = 45;
const int W_HEIGHT = 30;

const int nb_pieces = 10;
const int nb_mechant = 3;

// Fonction pour générer une matrice remplie de zéros
std::array<std::array<int, W_WIDTH>, W_HEIGHT> Plateau()
{
    std::array<std::array<int, W_WIDTH>, W_HEIGHT> plateau = {};

    return plateau;
}

// fonction pour créer un rectangle et le remplir
void placeRectangle(std::array<std::array<int, W_WIDTH>, W_HEIGHT>& plateau, int n, int m, int x, int y) {
    // Vérifier que le rectangle peut être placé dans la matrice
    // on part du coint bas gauche
    if (x + n > W_HEIGHT || y + m - 1 > W_WIDTH) {
        std::cerr << "Le rectangle dépasse les limites de la matrice." << std::endl;
        return;
    }

    // Initialisation du rectangle dans la matrice
    for (int i = x; i < x + n; ++i) {
        for (int j = y; j < y + m; ++j) {
            plateau[i][j] = 2; // 2 représente le mur
        }
    }

    // remplissage du rectangle par la valeur 1 (case salle)
    for (int i = x + 1; i < x + n - 1; ++i){
        for (int j = y + 1; j < y + m - 1; ++j){
            plateau[i][j] = 1; // représente la salle
        }
    }
}

void ajout_piece(std::array<std::array<int, W_WIDTH>, W_HEIGHT>& plateau) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib_height(0, W_HEIGHT - 1);
    std::uniform_int_distribution<> distrib_width(0, W_WIDTH - 1);

    for (int i = 0; i < nb_pieces; ++i) {
        int a = 0;
        int b = 0;
        do {
            a = distrib_height(gen);
            b = distrib_width(gen);
        } while (plateau[a][b] != 1 && plateau[a][b] != 3);
        plateau[a][b] = 8;
    }
}

// item méchant, que dans une salle. Si on le rencontre, le jeu est fini

void mechant(std::array<std::array<int, W_WIDTH>, W_HEIGHT>& plateau){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib_height(0, W_HEIGHT - 1);
    std::uniform_int_distribution<> distrib_width(0, W_WIDTH - 1);

    for (int i = 0; i < nb_mechant; ++i) {
        int A = 0;
        int B = 0;
        do {
            A = distrib_height(gen);
            B = distrib_width(gen);
        } while (plateau[A][B] != 1 && plateau[A][B] != 3);
        plateau[A][B] = 7;
    }
}

// Fonction réalisant le plateau de travail (non aléatoirement)
void plateau_travail (std::array<std::array<int, W_WIDTH>, W_HEIGHT>& plateau){
    // placement des rectangles
    int n = 4; //ligne
    int m = 9; //colonne
    int x = 1; //LIGNE
    int y = 1; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    n = 5;
    m = 6;
    x = 1;
    y = 13;
    placeRectangle(plateau, n, m, x, y);

    n = 9;
    m = 9;
    x = 1;
    y = 22;
    placeRectangle(plateau, n, m, x, y);

    n = 6; //ligne
    m = 8; //colonne
    x = 1; //LIGNE
    y = 34; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    n = 8; //ligne
    m = 9; //colonne
    x = 6; //LIGNE
    y = 1; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    n = 4; //ligne
    m = 3; //colonne
    x = 8; //LIGNE
    y = 14; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    n = 6; //ligne
    m = 8; //colonne
    x = 8; //LIGNE
    y = 37; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    n = 7; //ligne
    m = 17; //colonne
    x = 15; //LIGNE
    y = 1; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    n = 6; //ligne
    m = 8; //colonne
    x = 12; //LIGNE
    y = 23; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    n = 8; //ligne
    m = 9; //colonne
    x = 15; //LIGNE
    y = 35; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    n = 5; //ligne
    m = 9; //colonne
    x = 23; //LIGNE
    y = 0; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    n = 6; //ligne
    m = 10; //colonne
    x = 23; //LIGNE
    y = 13; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    n = 9; //ligne
    m = 4; //colonne
    x = 20; //LIGNE
    y = 25; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    n = 5; //ligne
    m = 12; //colonne
    x = 24; //LIGNE
    y = 31; //COLONNE
    placeRectangle(plateau, n, m, x, y);

    // placement des portes
    plateau[4][4] = 5;
    plateau[3][9] = 5;
    plateau[3][13] = 5;
    plateau[5][15] = 5;
    plateau[14][30] = 5;
    plateau[9][37] = 5;
    plateau[8][43] = 5;
    plateau[3][41] = 5;
    plateau[3][34] = 5;
    plateau[3][30] = 5;
    plateau[7][22] = 5;
    plateau[9][16] = 5;
    plateau[8][15] = 5;
    plateau[6][4] = 5;
    plateau[12][9] = 5;
    plateau[17][17] = 5;
    plateau[31][3] = 5;
    plateau[33][3] = 5;
    plateau[25][8] = 5;
    plateau[25][13] = 5;
    plateau[23][20] = 5;
    plateau[22][25] = 5;
    plateau[21][28] = 5;
    plateau[24][32] = 5;
    plateau[26][42] = 5;
    plateau[19][43] = 5;
    plateau[21][3] = 5;
    plateau[23][3] = 5;

    // placement des chemins
    // chemin 1
    plateau[14][31] = 3;
    plateau[14][32] = 3;
    plateau[13][32] = 3;
    plateau[12][32] = 3;
    plateau[11][32] = 3;
    plateau[10][32] = 3;
    plateau[9][32] = 3;
    plateau[9][33] = 3;
    plateau[9][34] = 3;
    plateau[9][35] = 3;
    plateau[9][36] = 3;

    // CHEMIN 2
    plateau[7][43] = 3;
    plateau[6][43] = 3;
    plateau[5][43] = 3;
    plateau[4][43] = 3;
    plateau[3][43] = 3;
    plateau[3][42] = 3;

    // CHEMIN 3
    plateau[3][33] = 3;
    plateau[3][32] = 3;
    plateau[3][31] = 3;

    // CHEMIN 4
    plateau[7][21] = 3;
    plateau[7][20] = 3;
    plateau[8][20] = 3;
    plateau[9][20] = 3;
    plateau[9][19] = 3;
    plateau[9][18] = 3;
    plateau[9][17] = 3;

    // CHEMIN 5
    plateau[7][15] = 3;
    plateau[6][15] = 3;

    // CHEMIN 6
    plateau[3][12] = 3;
    plateau[3][11] = 3;
    plateau[3][10] = 3;

    // CHEMIN 7
    plateau[5][4] = 3;

    // CHEMIN 8
    plateau[12][10] = 3;
    plateau[12][11] = 3;
    plateau[13][11] = 3;
    plateau[13][12] = 3;
    plateau[13][13] = 3;
    plateau[13][14] = 3;
    plateau[13][15] = 3;
    plateau[13][16] = 3;
    plateau[13][17] = 3;
    plateau[13][18] = 3;
    plateau[13][19] = 3;
    plateau[13][20] = 3;
    plateau[14][20] = 3;
    plateau[15][20] = 3;
    plateau[16][20] = 3;
    plateau[17][20] = 3;
    plateau[17][19] = 3;
    plateau[17][18] = 3;

    // CHMEIN 9
    plateau[22][3] = 3;

    // CHEMIN 10
    plateau[25][9] = 3;
    plateau[25][10] = 3;
    plateau[25][11] = 3;
    plateau[25][12] = 3;

    // CHEMIN 11
    plateau[22][20] = 3;
    plateau[21][20] = 3;
    plateau[21][21] = 3;
    plateau[21][22] = 3;
    plateau[21][23] = 3;
    plateau[22][23] = 3;
    plateau[22][24] = 3;

    // CHEMIN 12
    plateau[21][29] = 3;
    plateau[21][30] = 3;
    plateau[21][31] = 3;
    plateau[21][32] = 3;
    plateau[22][32] = 3;
    plateau[23][32] = 3;

    // CHEMIN 13
    plateau[26][43] = 3;
    plateau[26][44] = 3;
    plateau[25][44] = 3;
    plateau[24][44] = 3;
    plateau[23][44] = 3;
    plateau[22][44] = 3;
    plateau[21][44] = 3;
    plateau[20][44] = 3;
    plateau[19][44] = 3;

    mechant(plateau);
    ajout_piece(plateau);
    
    return ;
}

int main() {
    std::array<std::array<int, W_WIDTH>, W_HEIGHT> plateau = Plateau();

    plateau_travail(plateau);

    // Affichage de la matrice
    for (const auto& row : plateau) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
