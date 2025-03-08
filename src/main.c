#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "entity.h"
#include "player.h"

#define HANDLE_EVENTS_ENTITIES(entities, entity_count, event) \
    for (int i = 0; i < entity_count; i++) { \
        entities[i].handle_events(event); \
    }

#define QUIT_ENTITIES(entities, entity_count) \
    for (int i = 0; i < entity_count; i++) { \
        entities[i].quit(); \
    }

#define UPDATE_ENTITIES(entities, entity_count) \
    for (int i = 0; i < entity_count; i++) { \
        entities[i].update(); \
    }

#define RENDER_ENTITIES(entities, entity_count, renderer) \
    for (int i = 0; i < entity_count; i++) { \
        entities[i].render(renderer); \
    }

SDL_Window* window;
SDL_Renderer* renderer;

Entity entities[MAX_ENTITIES];
int entity_count = 0;


void SDL_AppQuit(void *appstate, SDL_AppResult){
    QUIT_ENTITIES(entities, entity_count);
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;  
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
    if(event->type == SDL_EVENT_QUIT){
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

void update(){
    UPDATE_ENTITIES(entities, entity_count);
}

void render(){
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    
    RENDER_ENTITIES(entities, entity_count, renderer);

    SDL_RenderPresent(renderer);
}

SDL_AppResult SDL_AppIterate(void *appstate){
    update();
    render();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv){

    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("Error initializing SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("SDL 3 Game", 800, 600, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    entities[entity_count++] = init_player(renderer);

    return SDL_APP_CONTINUE;  

}