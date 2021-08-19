#include <gint/keyboard.h>
#include "util.h"

void wait_for_input(int input) {
	int buffer = 1;
	while(1) {
		clearevents();
		if(keydown(input)) {
			if(buffer) buffer = 0;
			else break;
		}
		while(keydown(input)) clearevents();
	}
}