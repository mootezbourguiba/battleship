#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

// Initialisation de la grille
void init_grid(Grid *grid, int width, int height) {
    grid->width = width;
    grid->height = height;
    grid->cells = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        grid->cells[i] = (char *)malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            grid->cells[i][j] = '~'; // '~' pour représenter l'eau
        }
    }
}

// Affichage de la grille
void display_grid(Grid *grid) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            printf("%c ", grid->cells[i][j]);
        }
        printf("\n");
    }
}

// Libération de la mémoire de la grille
void free_grid(Grid *grid) {
    for (int i = 0; i < grid->height; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
}

