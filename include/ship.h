#ifndef SHIP_H
#define SHIP_H

#include "grid.h"

// Structure repr�sentant un navire
typedef struct {
    int x; // Position x du navire
    int y; // Position y du navire
    int length; // Longueur du navire
    int orientation; // Orientation du navire (0 = horizontal, 1 = vertical)
} Ship;

// D�clare les fonctions utilis�es pour g�rer les navires
void init_ship(Ship *ship, int x, int y, int length, int orientation);
void place_ship(Grid *grid, Ship *ship);
int can_place_ship(Grid *grid, Ship *ship);

#endif // SHIP_H

