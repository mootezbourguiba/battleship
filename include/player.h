#ifndef PLAYER_H
#define PLAYER_H

#include "grid.h"
#include <pthread.h>

// Structure repr�sentant un joueur
typedef struct {
    int id; // Identifiant du joueur
    Grid grid; // Grille du joueur
    int is_active; // Indicateur d'activit� du joueur
    pthread_t thread; // Thread du joueur
} Player;

// D�clare les fonctions utilis�es pour g�rer les joueurs
void initialize_player(Player *player, int id);
void *player_actions(void *arg);
void create_player_threads(Player players[], int num_players);

#endif // PLAYER_H

