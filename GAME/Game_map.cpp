#include"Game_map.h"

void GameMap::LoadMap( char* name)
{
    FILE* fp = NULL;
    fopen_s(&fp, name, "rb");
    if (fp == NULL)
    {
        printf(" file fp null / game map cpp / load map "); return;
    }

    game_map_.max_x_ = 0;
    game_map_.max_y_ = 0;

    for (int i = 0; i < MAX_MAP_Y; i++)
    {
        for (int j = 0; j < MAX_MAP_X; j++)
        {
            fscanf_s(fp, "%d", &game_map_.tile[i][j]);

            int val = game_map_.tile[i][j];
            if (val > 0)
            {
                if (j > game_map_.max_x_)
                {
                    game_map_.max_x_ = j;
                }

                if (i > game_map_.max_y_)
                {
                    game_map_.max_y_ = i;
                }
            }
        }
    }


    game_map_.max_x_ = (game_map_.max_x_ + 1) * TILE_SIZE;
    game_map_.max_y_ = (game_map_.max_y_ + 1) * TILE_SIZE;

    game_map_.start_x_ = 0;
    game_map_.start_y_ = 0;

    game_map_.file_name_ = name;
    fclose(fp);
}

void GameMap::LoadTiles(SDL_Renderer* screen, int checkMap)
{
    char file_img[30];
    FILE* fp = NULL;
    if (checkMap == 30)
    {
        for (int i = 0; i < MAX_TILES; i++)
        {

            sprintf_s(file_img, "map1/%d.png", i);

            fopen_s(&fp, file_img, "rb");

            if (fp == NULL) { continue; }

            fclose(fp);
            tile_mat[i].LoadImg(file_img, screen);
        }
    }
    else if (checkMap == 31)
    {
        for (int i = 0; i < MAX_TILES; i++)
        {

            sprintf_s(file_img, "map2/%d.png", i);

            fopen_s(&fp, file_img, "rb");

            if (fp == NULL) { continue; }

            fclose(fp);
            tile_mat[i].LoadImg(file_img, screen);
        }
    }
    else if (checkMap == 32)
    {
        for (int i = 0; i < MAX_TILES; i++)
        {

            sprintf_s(file_img, "map3/%d.png", i);

            fopen_s(&fp, file_img, "rb");

            if (fp == NULL) { continue; }

            fclose(fp);
            tile_mat[i].LoadImg(file_img, screen);
        }
    }
    else if (checkMap == 33)
    {
        for (int i = 0; i < MAX_TILES; i++)
        {

            sprintf_s(file_img, "map4/%d.png", i);

            fopen_s(&fp, file_img, "rb");

            if (fp == NULL) { continue; }

            fclose(fp);
            tile_mat[i].LoadImg(file_img, screen);
        }
    }
    else if (checkMap == 34)
    {
        for (int i = 0; i < MAX_TILES; i++)
        {

            sprintf_s(file_img, "map5/%d.png", i);

            fopen_s(&fp, file_img, "rb");

            if (fp == NULL) { continue; }

            fclose(fp);
            tile_mat[i].LoadImg(file_img, screen);
        }
    }
    else 
    {
        for (int i = 0; i < MAX_TILES; i++)
        {

            sprintf_s(file_img, "map6/%d.png", i);

            fopen_s(&fp, file_img, "rb");

            if (fp == NULL) { continue; }

            fclose(fp);
            tile_mat[i].LoadImg(file_img, screen);
        }
    }
}

void GameMap::DrawMap(SDL_Renderer* screen)
{
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    int map_x = 0, map_y = 0;

    map_x = game_map_.start_x_ / TILE_SIZE;
    x1 = (game_map_.start_x_ % TILE_SIZE) * -1;
    x2 = x1 + SCR_W + (x1 == 0 ? 0 : TILE_SIZE);

    map_y = game_map_.start_y_ / TILE_SIZE;
    y1 = (game_map_.start_y_ % TILE_SIZE) * -1;
    y2 = y1 + SCR_H + (y1 == 0 ? 0 : TILE_SIZE);

    for (int i = y1; i < y2; i += TILE_SIZE)
    {
        map_x = game_map_.start_x_ / TILE_SIZE;
        for (int j = x1; j < x2; j += TILE_SIZE)
        {
            int val = game_map_.tile[map_y][map_x];
            if (val > 0)
            {
                tile_mat[val].SetRect(j, i);
                tile_mat[val].Render(screen, NULL);
            }
            map_x++;
        }
        map_y++;
    }
}


