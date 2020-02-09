/*
	Name: Daniel Repko
	Lab 4
*/
//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
    if(Event->type == SDL_QUIT||Event->type == SDL_KEYDOWN) {
        Running = false;
    }

	//move the alien with the mouse
	if (Event->type == SDL_MOUSEMOTION)
	{
		positions[0].y = Event->motion.y - (sprite_h[0] / 2);
	}

	//shoot a fireball from the alien after mouse click
	if (Event->type == SDL_MOUSEBUTTONDOWN && Event->button.button == 1)
	{
		positions[3].w = sprite_w[3];
		positions[3].h = sprite_h[3];

		positions[3].x = positions[0].x + sprite_w[3];
		positions[3].y = positions[0].y + (sprite_h[3] / 3);
	}

	//shoot the cannonball when the A button is pressed
	if (Event->jbutton.which == 0 && Event->jbutton.button == 0 && Event->jbutton.state == SDL_PRESSED)
	{
		positions[2].w = sprite_w[2];
		positions[2].h = sprite_h[2];

		positions[2].x = positions[1].x + sprite_w[2];
		positions[2].y = positions[1].y + (sprite_h[2] / 3);
	}
}

//==============================================================================
