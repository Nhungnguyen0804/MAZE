#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "Common.h"
#include "Base.h"

#include <string>

constexpr int MAX_TILES = 20;

class TileMat : public Base {
public:
    TileMat() = default;
    ~TileMat() = default;
};

class GameMap {
public:
    GameMap() = default;
    ~GameMap() = default;

    void LoadMap(const char* name);                      // Load dữ liệu bản đồ từ file
    void LoadTiles(SDL_Renderer* screen, int checkMap);  // Load hình ảnh tile
    void DrawMap(SDL_Renderer* screen);                  // Vẽ bản đồ

    Map getMap() const { return game_map_; }
    void SetMap(const Map& map_data) { game_map_ = map_data; }

private:
    Map game_map_;                  // Dữ liệu bản đồ
    TileMat tile_mat[MAX_TILES];    // Mảng hình ảnh tile
};

#endif // GAME_MAP_H
