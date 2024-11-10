#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define GRID_SIZE 10 // Définir la taille de la grille

extern pthread_mutex_t game_mutex; // Déclarer game_mutex comme externe

// Initialisation d'un joueur
void initialize_player(Player *player, int id) {
    player->id = id;
    // Initialisation de la grille du joueur
    player->grid.width = GRID_SIZE;
    player->grid.height = GRID_SIZE;
    player->grid.cells = (char **)malloc(player->grid.height * sizeof(char *));
    for (int i = 0; i < player->grid.height; i++) {
        player->grid.cells[i] = (char *)malloc(player->grid.width * sizeof(char));
        for (int j = 0; j < player->grid.width; j++) {
            player->grid.cells[i][j] = '~'; // '~' pour représenter l'eau
        }
    }
    player->is_active = 1; // Le joueur est actif
}

// Actions d'un joueur (tirer, etc.)
void *player_actions(void *arg) {
    Player *player = (Player *)arg;
    int x, y;
    while (player->is_active) {
        // Simulation des actions du joueur (tirer, etc.)
        printf("Player %d, enter coordinates to attack (x y): ", player->id);
        scanf("%d %d", &x, &y);

        pthread_mutex_lock(&game_mutex);
        if (player->grid.cells[x][y] == '~') {
            player->grid.cells[x][y] = 'O'; // 'O' pour tir manqué
            printf("Missed!\n");
        } else {
            player->grid.cells[x][y] = 'X'; // 'X' pour tir réussi
            printf("Hit!\n");
        }
        pthread_mutex_unlock(&game_mutex);
    }
    return NULL;
}

// Création des threads de joueurs
void create_player_threads(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        initialize_player(&players[i], i + 1);
        pthread_create(&players[i].thread, NULL, player_actions, (void *)&players[i]);
    }
    for (int i = 0; i < num_players; i++) {
        pthread_join(players[i].thread, NULL);
    }
}

