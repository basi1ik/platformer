#include "player.h"

SDL_Texture* player_texture;
SDL_FRect sprite_frame = {17,14,15,18};
SDL_FRect player_position = {250,250,15,18};
static void quit(){

}

static void handle_events(){

}

static void update(){

}

static void render(SDL_Renderer* renderer){

    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);
    SDL_RenderTexture(renderer, player_texture, &sprite_frame, &player_position);
}
    
Entity init_player(SDL_Renderer* renderer){
    
    const char path[] = "src/assets/Char_Sprites/char_spritesheet.png";
    player_texture = IMG_LoadTexture(renderer, path);
    
    Entity player = {
        .quit = quit, 
        .handle_events = handle_events, 
        .update = update, 
        .render = render
    };
    return player;
}