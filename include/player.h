#pragma once
#include "animation.h"
#include "engine.h"
#include "vec2.h"
#include "stats.h"
#include "capacite.h"
#include "define.h"

struct Player {
	/*current position of the player on the map - Tile*/
	struct Vec2 pos;
	/*current position of the player on the map - pixels */
	struct Vec2f pos_visual;

	const struct Stats base_stats;
	struct Stats stats;
	struct Move *moves[NB_PLAYER_MOVES];
	/*player mid - offset pixels*/
	int x_mid, y_mid;
	/*the direction the player facing to*/
	int direction;
	/*if the player is sprinting*/
	int sprint;
	/*current frame of the animation*/
	int frame;
	/*where to draw the player on the screen*/
	int show_x, show_y;
	/*the current animation*/
	int idle;
	struct AnimData anim;
};

struct LevelUp {
	int level;
	int id_move;
};

struct LevelUpPlayer {
	int nbLevelUp;
	struct LevelUp *levelup[];
};

/*return the info tile value the player is facing to*/
int player_facing(struct Game const *game);
struct Player init_player(void);
void add_move(struct Player *player, struct Move move);
void draw_player_moves(struct Player *player);
void replace_capacities(struct Player *player, struct Move move);
void draw_ui(struct Player *player);
int get_nb_moves(struct Player *player);
void reset_pp(struct Player *player);
void check_level(struct Player *player, int prec_level);