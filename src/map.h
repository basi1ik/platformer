#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "entity.h"
#include "external/cute_tiled.h"

typedef struct {

    SDL_Texture *texture;
    int firstgid;
    int tilecount;
    int tileset_width;
    int tileset_height;
    Texture* next;

}Texture;