#ifndef GAME_H
#define GAME_H

#include "player.h"

// D�clare les fonctions utilis�es pour le jeu
void init_players(Player players[], int num_players);
void start_game(Player players[], int num_players);
void display_results(Player players[]);

#endif // GAME_H

