/*
	Name: Daniel Repko
	Lab 4
*/
//==============================================================================
// SDL Tutorial 1
//==============================================================================
#include <iostream>
#ifndef _CAPP_H_
#define _CAPP_H_

#include "SDL.h"

#ifdef __NDS__
#define WINDOW_WIDTH    320
#define WINDOW_HEIGHT   240
#else
#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480
#endif

#define NUM_SPRITES     4

//==============================================================================
class CApp
{
private:
    bool            Running;

    SDL_Window *window;
    SDL_Renderer *renderer;
	SDL_Texture *alienSprite;
	SDL_Texture *cannonSprite;
	SDL_Texture *cannonBallSprite;
	SDL_Texture *fireBallSprite;

	SDL_Rect positions[NUM_SPRITES];
	int sprite_w[4], sprite_h[4];

	SDL_Joystick *joy = NULL;

	

public:
    CApp();

    int OnExecute();

public:
    bool OnInit();

    void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();
    int LoadSprite(char *file, SDL_Texture *&spriteToPopulate, SDL_Renderer *renderer, int widthIndex, int heightIndex);
    void MoveSprites();

    void OnCleanup();
};

//==============================================================================

#endif
