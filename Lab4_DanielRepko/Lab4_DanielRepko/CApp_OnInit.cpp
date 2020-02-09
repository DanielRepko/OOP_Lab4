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
        return false;
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
        return false;

    if (LoadSprite("hts.bmp") < 0)
        return false;

    srand(time(NULL));
    for (i = 0; i < NUM_SPRITES; ++i) {
        positions[i].x = rand() % (WINDOW_WIDTH - sprite_w);
        positions[i].y = rand() % (WINDOW_HEIGHT - sprite_h);
        positions[i].w = sprite_w;
        positions[i].h = sprite_h;
        velocities[i].x = 0;
        velocities[i].y = 0;
        while (!velocities[i].x && !velocities[i].y) {
            velocities[i].x = (rand() % (MAX_SPEED * 2 + 1)) - MAX_SPEED;
            velocities[i].y = (rand() % (MAX_SPEED * 2 + 1)) - MAX_SPEED;
        }
    }

    return true;
}

//==============================================================================
