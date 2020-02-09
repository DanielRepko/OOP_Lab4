/*
	Name: Daniel Repko
	Lab 4
*/
//==============================================================================
#include "CApp.h"

//==============================================================================
CApp::CApp() {
    //Surf_Display = NULL;

    Running = true;
}


int
CApp::LoadSprite(char *file, SDL_Texture *&spriteToPopulate, SDL_Renderer *renderer, int widthIndex, int heightIndex)
{
    SDL_Surface *temp;

    /* Load the sprite image */
    temp = SDL_LoadBMP(file);
    if (temp == NULL) {
        fprintf(stderr, "Couldn't load %s: %s", file, SDL_GetError());
        return (-1);
    }
	sprite_w[widthIndex] = temp->w;
	sprite_h[heightIndex] = temp->h;

    /* Set transparent pixel as the pixel at (0,0) */
    if (temp->format->palette) {
        SDL_SetColorKey(temp, SDL_TRUE, *(Uint8 *) temp->pixels);
    } else {
        switch (temp->format->BitsPerPixel) {
        case 15:
            SDL_SetColorKey(temp, SDL_TRUE,
                            (*(Uint16 *) temp->pixels) & 0x00007FFF);
            break;
        case 16:
            SDL_SetColorKey(temp, SDL_TRUE, *(Uint16 *) temp->pixels);
            break;
        case 24:
            SDL_SetColorKey(temp, SDL_TRUE,
                            (*(Uint32 *) temp->pixels) & 0x00FFFFFF);
            break;
        case 32:
            SDL_SetColorKey(temp, SDL_TRUE, *(Uint32 *) temp->pixels);
            break;
        }
    }

    /* Create textures from the image */
    spriteToPopulate = SDL_CreateTextureFromSurface(renderer, temp);
    if (!spriteToPopulate) {
        //fprintf(stderr, "Couldn't create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(temp);
        return (-1);
    }
    SDL_FreeSurface(temp);

    /* We're ready to roll. :) */
    return (0);
}



//------------------------------------------------------------------------------
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

		//move the cannon | put this here instead of in OnEvent to prevent jittery movement
		if (joy)
		{
			positions[1].y += SDL_JoystickGetAxis(joy, 1) / 6000;
		}

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

//==============================================================================
int main(int argc, char* argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}

//==============================================================================
