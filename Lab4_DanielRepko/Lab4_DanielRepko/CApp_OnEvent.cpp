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
}

//==============================================================================
