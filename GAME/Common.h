#ifndef COMMON_H
#define COMMON_H


#include <stdio.h>
#include <stdlib.h>
#include<string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include<windows.h>
#include<time.h>

static Mix_Music* gNen = NULL;
static Mix_Chunk* g_eat = NULL;
static Mix_Chunk* g_dora = NULL;
static Mix_Chunk* g_chuong = NULL;


static SDL_Window* gWin = NULL;
static SDL_Renderer* gRen = NULL;
static SDL_Event gE;
// screen
const int SCR_W = 1120;
const int SCR_H = 720;
const int SCR_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0xff;

// fps timer
const int FRAME_PER_SECOND = 55;

#define SO_GIAY_CUA_CANDY 5
#define SO_GIAY_CUA_DORAYAKI 15
#define TILE_SIZE 80
#define MAX_MAP_X 61
#define MAX_MAP_Y 61

#define BLANK_TILE 0
#define GACH 1
#define STATE_DICH 2
#define CANDY 3
#define DORAYAKI 4
#define CHUONG 6

#define VE_MENU 50
typedef struct Input
{
    int left_, right_, up_, down_, jump_;
};
typedef struct Map
{
    int start_x_;
    int start_y_;
    int max_x_;
    int max_y_;

    int tile[MAX_MAP_Y][MAX_MAP_X];
    char* file_name_;
};
#endif // COMMON_H

