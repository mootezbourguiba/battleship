#ifndef GRID_H
#define GRID_H

// Structure repr�sentant une grille
typedef struct {
    int width; // Largeur de la grille
    int height; // Hauteur de la grille
    char **cells; // Cellules de la grille
} Grid;

// D�clare les fonctions utilis�es pour g�rer la grille
void init_grid(Grid *grid, int width, int height);
void display_grid(Grid *grid);
void free_grid(Grid *grid);

#endif // GRID_H

