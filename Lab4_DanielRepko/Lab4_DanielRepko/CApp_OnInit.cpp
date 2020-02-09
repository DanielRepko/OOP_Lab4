/*
	Name: Daniel Repko
	Lab 4
*/
//==============================================================================
#include "CApp.h"
#include <stdlib.h>
#include <time.h>
//==============================================================================
bool CApp::OnInit()
{

    int i;

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK)<0)
    {
        return false;
    }
    window = SDL_CreateWindow("Basic SDL 2.0 Sprites",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT,
                              SDL_WINDOW_SHOWN);
	if (!window)
	{
		return false;
	}        
    renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		return false;
	}        

	//load the sprites
	if (LoadSprite("alien.bmp", alienSprite, renderer, 0, 0) < 0)
	{
		return false;
	}
	if (LoadSprite("cannon.bmp", cannonSprite, renderer, 1, 1) < 0)
	{
		return false;
	}
	if (LoadSprite("cannonball.bmp", cannonBallSprite, renderer, 2, 2) < 0)
	{
		return false;
	}
	if (LoadSprite("fireball.bmp", fireBallSprite, renderer, 3, 3) < 0)
	{
		return false;
	}

	//set the joystick
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	if (SDL_NumJoysticks() > 0)
	{
		joy = SDL_JoystickOpen(0);
	}

	positions[0].x = 0;
	positions[0].y = WINDOW_HEIGHT / 2 - (sprite_h[0] / 2);
	positions[0].w = sprite_w[0];
	positions[0].h = sprite_h[0];

	positions[1].x = WINDOW_WIDTH - sprite_w[1];
	positions[1].y = WINDOW_HEIGHT / 2 - (sprite_h[1] / 2);
	positions[1].w = sprite_w[1];
	positions[1].h = sprite_h[1];

    return true;
}

//==============================================================================
