#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include"Common.h"
#include"Base.h"



#define PLAYER_SPEED 7 //

#define NUM_FRAME 6


class MainObject : public Base
{
public: MainObject();
	  ~MainObject();

	  enum WalkType
	  {
		  WALK_RIGHT =0,
		  WALK_LEFT =1,
		  WALK_UP =2,
		  WALK_DOWN =3,
	  };

	  virtual bool LoadImg(std::string path, SDL_Renderer* screen);
	  void Show(SDL_Renderer* des);
	  void HandelInputAction(SDL_Event events, SDL_Renderer* screen);
	  void set_clips();
	  void DoPlayer(Map& map_data, Mix_Chunk* g_eat, Mix_Chunk* g_dora, Mix_Chunk* g_chuong);
	  void CheckToMap(Map& map_data, Mix_Chunk* g_eat, Mix_Chunk* g_dora, Mix_Chunk* g_chuong);
	  void SetMapXY(const int map_x, const int map_y)
	  {
		  map_x_ = map_x;
		  map_y_ = map_y;
	  }

	  void CenterEntityOnMap(Map& map_data);
	  int den_dich_chua()const { return check_dich; }
	
	  void IncreaseCandy() { candy_count++; }
	  int getCandyCount()const { return candy_count; }

	  void IncreaseDorayaki() { dorayaki_count++; }
	  int getDorayakiCount()const { return dorayaki_count; }
private:
//ktra den dich chua
	bool check_dich;
	float x_val_;
	float y_val_;

	float x_pos_, y_pos_;

	int width_frame_;
	int height_frame_;

	SDL_Rect frame_clip_[6];//

	Input input_type_;
	int frame_;
	int status_;

	bool on_ground_;

	int map_x_;
	int map_y_;

	int candy_count;
	int dorayaki_count;
};
#endif