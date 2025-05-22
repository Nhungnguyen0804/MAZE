#include "Game_map.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;
void GameMap::LoadMap(const char* name)
{
    ifstream file(name);
    if (!file.is_open())
    {
        cout << "Failed to open map file: " << name << endl;
        return;
    }

    game_map_.max_x_ = 0;
    game_map_.max_y_ = 0;

    for (int i = 0; i < MAX_MAP_Y; ++i)
    {
        for (int j = 0; j < MAX_MAP_X; ++j)
        {
            file >> game_map_.tile[i][j];
            int val = game_map_.tile[i][j];
            if (val > 0)
            {
                game_map_.max_x_ = (max)(game_map_.max_x_, j);
                game_map_.max_y_ = (max)(game_map_.max_y_, i);
            }
        }
    }

    game_map_.max_x_ = (game_map_.max_x_ + 1) * TILE_SIZE;
    game_map_.max_y_ = (game_map_.max_y_ + 1) * TILE_SIZE;
    game_map_.start_x_ = 0;
    game_map_.start_y_ = 0;
    game_map_.file_name_ = name;
}

void GameMap::LoadTiles(SDL_Renderer* screen, int checkMap)
{
    string folder;
    switch (checkMap)
    {
    case 30: folder = "image/map1/"; break;
    case 31: folder = "image/map2/"; break;
    case 32: folder = "image/map3/"; break;
    case 33: folder = "image/map4/"; break;
    case 34: folder = "image/map5/"; break;
    default: folder = "image/map6/"; break;
    }

    for (int i = 0; i < MAX_TILES; ++i)
    {
        string filename = folder + to_string(i) + ".png";
        ifstream fcheck(filename);
        if (!fcheck.is_open()) continue;

        tile_mat[i].LoadImg(filename.c_str(), screen);
    }
}

void GameMap::DrawMap(SDL_Renderer* screen)
{
    int map_x = game_map_.start_x_ / TILE_SIZE;
    int map_y = game_map_.start_y_ / TILE_SIZE;

    int x1 = (game_map_.start_x_ % TILE_SIZE) * -1;
    int y1 = (game_map_.start_y_ % TILE_SIZE) * -1;

    int x2 = x1 + SCR_W + (x1 == 0 ? 0 : TILE_SIZE);
    int y2 = y1 + SCR_H + (y1 == 0 ? 0 : TILE_SIZE);

    for (int y = y1, i = map_y; y < y2 && i < MAX_MAP_Y; y += TILE_SIZE, ++i)
    {
        for (int x = x1, j = map_x; x < x2 && j < MAX_MAP_X; x += TILE_SIZE, ++j)
        {
            int val = game_map_.tile[i][j];
            if (val > 0 && val < MAX_TILES)
            {
                tile_mat[val].SetRect(x, y);
                tile_mat[val].Render(screen, nullptr);
            }
        }
    }
}
