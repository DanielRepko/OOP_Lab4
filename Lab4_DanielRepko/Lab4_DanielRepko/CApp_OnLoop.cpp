/*
	Name: Daniel Repko
	Lab 4
*/
//==============================================================================
#include "CApp.h"


void
CApp::MoveSprites()
{
	int window_w = WINDOW_WIDTH;
	int window_h = WINDOW_HEIGHT;
	SDL_Rect *position, *velocity;

	// Draw a gray background
	SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
	SDL_RenderClear(renderer);

	// Move the sprite, bounce at the wall, and draw
	for (int i = 0; i < NUM_SPRITES; ++i)
	{
		position = &positions[i];

		//Perform sprite-specific actions / Blit the sprite onto the screen
		switch (i)
		{
		case 0:
			//keep the sprite from moving past the top of the screen
			if ((positions[i].y + sprite_h[i]) > WINDOW_HEIGHT)
			{
				positions[i].y = WINDOW_HEIGHT - sprite_h[i];
			}
			//keep the sprite from moving past the bottom of the screen
			if (positions[i].y < 0)
			{
				positions[i].y = 0;
			}

			SDL_RenderCopy(renderer, alienSprite, NULL, position);
			break;
		case 1:
			//keep the sprite from moving past the top of the screen
			if ((positions[i].y + sprite_h[i]) > WINDOW_HEIGHT)
			{
				positions[i].y = WINDOW_HEIGHT - sprite_h[i];
			}
			//keep the sprite from moving past the bottom of the screen
			if (positions[i].y < 0)
			{
				positions[i].y = 0;
			}

			SDL_RenderCopy(renderer, cannonSprite, NULL, position);
			break;
		case 2:
			//render and add velocity to the cannonball
			positions[2].x -= 5;
			SDL_RenderCopy(renderer, cannonBallSprite, NULL, position);
			break;
		case 3:
			//render and add velocity to the fireball
			positions[3].x += 5;
			SDL_RenderCopy(renderer, fireBallSprite, NULL, position);
			break;
		}

	}
	// Update the screen!
	SDL_RenderPresent(renderer);
}


//==============================================================================
void CApp::OnLoop()
{
    MoveSprites();



}

//==============================================================================
