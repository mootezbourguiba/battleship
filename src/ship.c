#include "ship.h"

// Initialisation d'un navire
void init_ship(Ship *ship, int x, int y, int length, int orientation) {
    ship->x = x;
    ship->y = y;
    ship->length = length;
    ship->orientation = orientation;
}

// Placement d'un navire sur la grille
void place_ship(Grid *grid, Ship *ship) {
    for (int i = 0; i < ship->length; i++) {
        if (ship->orientation == 0) { // Orientation horizontale
            grid->cells[ship->y][ship->x + i] = 'S'; // 'S' pour représenter un navire
        } else { // Orientation verticale
            grid->cells[ship->y + i][ship->x] = 'S';
        }
    }
}

// Vérification si un navire peut être placé sur la grille
int can_place_ship(Grid *grid, Ship *ship) {
    for (int i = 0; i < ship->length; i++) {
        if (ship->orientation == 0) { // Orientation horizontale
            if (ship->x + i >= grid->width || grid->cells[ship->y][ship->x + i] != '~') {
                return 0; // Impossible de placer le navire
            }
        } else { // Orientation verticale
            if (ship->y + i >= grid->height || grid->cells[ship->y + i][ship->x] != '~') {
                return 0; // Impossible de placer le navire
            }
        }
    }
    return 1; // Possible de placer le navire
}

