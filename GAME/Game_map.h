#ifndef GAME_MAP_H
#define GAME_MAP_H

#include"Common.h"
#include"Base.h"

#define MAX_TILES 20
class TileMat : public Base
{
public:
    TileMat() { ; }
    ~TileMat() { ; }
};

class GameMap
{
public:
    GameMap(){;}
    ~GameMap(){;}
    void LoadMap( char* name);
    void LoadTiles(SDL_Renderer* screen, int checkMap);
    void DrawMap(SDL_Renderer* screen);
    Map getMap()const { return game_map_; };
    void SetMap(Map& map_data)
    {
        game_map_ = map_data;
    };


private:
    Map game_map_;
    TileMat tile_mat[MAX_TILES];
};
#endif
