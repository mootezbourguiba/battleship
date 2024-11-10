#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define GRID_SIZE 10 // Taille de la grille

pthread_mutex_t game_mutex; // Mutex pour synchroniser l'accès à la grille

// Initialisation des joueurs
void init_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        initialize_player(&players[i], i + 1);
    }
}

// Démarrage du jeu
void start_game(Player players[], int num_players) {
    create_player_threads(players, num_players);
}

// Affichage des résultats du jeu
void display_results(Player players[]) {
    for (int i = 0; i < 2; i++) {
        printf("Results for Player %d:\n", players[i].id);
        for (int j = 0; j < GRID_SIZE; j++) {
            for (int k = 0; k < GRID_SIZE; k++) {
                printf("%c ", players[i].grid.cells[j][k]);
            }
            printf("\n");
        }
    }
}

