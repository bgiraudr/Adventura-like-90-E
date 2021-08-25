#pragma once
#include "map.h"
struct Talkable {
	/*the position of the tile*/
	int x, y;
	/*the name*/
	char *name;
	/*the text to display*/
	char *text;
};

/*draw the dialog of a specified talkable tile*/
void draw_dialog(struct Talkable *character);
/*find the talkable tile using the player's position*/
struct Talkable* get_dialog_xy(struct Map *map, int x, int y);