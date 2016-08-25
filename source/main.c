#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <3ds.h>
#include <sf2d.h>
#include <stdbool.h>

#include "../include/application_controller.h"
#include "../include/types/game_states.h"



/**
 * Initializes general 3DS libraries for the application to use.
 */
void application_init(void)
{
	// Set the random seed based on the time
	srand(time(NULL));

	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
	sf2d_set_3D(1);
}

/**
 * Ends all general 3DS libraries that were setup by application_init()
 */
int application_finish(void)
{
	sf2d_fini();
	return 0;
}


int main(void)
{
	application_init();
	ApplicationController *application_controller = application_controller_init();



	while (aptMainLoop() && application_controller_is_running(application_controller))
	{
		sf2d_start_frame(GFX_TOP, GFX_LEFT);

		sf2d_draw_rectangle(0, 20, 360, 10, RGBA8(0x00, 0x00, 0x00, 0xFF));
		sf2d_draw_rectangle(0, 20, sf2d_get_fps() * 6, 10, RGBA8(0xFF, 0x00, 0x00, 0xCC));

		sf2d_end_frame();

		update_application_controller(application_controller);
	}

	return application_finish();
}
