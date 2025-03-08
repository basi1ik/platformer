#include "init.h"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv){

    AppState *state = SDL_malloc(sizeof(AppState));
    *appstate = state;

    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("Error initializing SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("SDL 3 Game", 800, 600, 0, &state->window, &state->renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    entities[entities_count++] = init_player(state->renderer);

    return SDL_APP_CONTINUE;  

}