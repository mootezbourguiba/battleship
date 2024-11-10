#include "game.h"
#include <pthread.h>

#define NUM_PLAYERS 2 // Nombre de joueurs

pthread_mutex_t game_mutex; // Déclaration de game_mutex

int main() {
    Player players[NUM_PLAYERS];

    // Initialisation du mutex
    if (pthread_mutex_init(&game_mutex, NULL) != 0) {
        printf("Mutex init failed\n");
        return 1;
    }

    // Initialisation des joueurs
    init_players(players, NUM_PLAYERS);

    // Démarrage du jeu
    start_game(players, NUM_PLAYERS);

    // Affichage des résultats
    display_results(players);

    // Destruction du mutex
    pthread_mutex_destroy(&game_mutex);

    return 0;
}

