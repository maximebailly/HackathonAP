//
// Created by maxim on 04/02/2025.
//

#include "game.h"
#include "visuals.h"

bool is_valid(int arrx, int arry) {
    // si c'est du vide ou un mur on return false, interdit
    if (plateau_decouvert[arry][arrx] == '0' || plateau_decouvert[arry][arrx] == '2') {
        return false;
    }
    return (arrx >= 0 && arrx < W_WIDTH && arry >= 0 && arry < W_HEIGHT);
}
