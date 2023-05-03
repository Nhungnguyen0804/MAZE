#include"MainObject.h"

MainObject::MainObject()
{
	frame_ = 0;
	x_pos_ = 0;
	y_pos_ = 80 + 10; 
	x_val_ = 0;
	y_val_ = 0;
	width_frame_ = 0;
	height_frame_ = 0;
	status_ = -1;

	input_type_.left_ = 0;
	input_type_.right_ = 0;
	input_type_.jump_ = 0;
	input_type_.up_ = 0;
	input_type_.down_ = 0;

	on_ground_ = false; // tam bo k co

	map_x_ = 0;
	map_y_ = 0;

	check_dich = 0; // chua den dich
	candy_count = 0;
	dorayaki_count = 0;
}

MainObject::~MainObject()
{
}

bool MainObject::LoadImg(std::string path, SDL_Renderer* screen)
{
	bool ret = Base::LoadImg(path, screen);
	if (ret == true)
	{
		width_frame_ = rect_.w / NUM_FRAME;// 
		height_frame_ = rect_.h;
	}
	return ret;
}

void MainObject::set_clips()
{
	if (width_frame_ > 0 and height_frame_ > 0)
	{
		frame_clip_[0].x = 0;
		frame_clip_[0].y = 0;
		frame_clip_[0].w = width_frame_;
		frame_clip_[0].h = height_frame_;

		frame_clip_[1].x = width_frame_;
		frame_clip_[1].y = 0;
		frame_clip_[1].w = width_frame_;
		frame_clip_[1].h = height_frame_;

		frame_clip_[2].x = 2*width_frame_;
		frame_clip_[2].y = 0;
		frame_clip_[2].w = width_frame_;
		frame_clip_[2].h = height_frame_;

		frame_clip_[3].x = 3*width_frame_;
		frame_clip_[3].y = 0;
		frame_clip_[3].w = width_frame_;
		frame_clip_[3].h = height_frame_;

		frame_clip_[4].x = 4 * width_frame_;
		frame_clip_[4].y = 0;
		frame_clip_[4].w = width_frame_;
		frame_clip_[4].h = height_frame_;

		frame_clip_[5].x = 5 * width_frame_;
		frame_clip_[5].y = 0;
		frame_clip_[5].w = width_frame_;
		frame_clip_[5].h = height_frame_;//

		
	}
}

void MainObject::Show(SDL_Renderer* des)
{
	// load anh khi di chuyen trai phai
	if (status_ == WALK_LEFT)
	{
		LoadImg("image//dora_left.png", des);
	}
	else if( status_ == WALK_RIGHT)
	{
		LoadImg("image//dora_right.png", des);
	}
	// load anh khi di chuyen len xuong
	else if (status_ == WALK_UP)
	{
		LoadImg("image//dora_right.png", des);
	}
	else
	{
		LoadImg("image//dora_right.png", des);
	}
	if (input_type_.left_ == 1 or input_type_.right_ == 1 or input_type_.up_ ==1 or input_type_.down_ ==1 )
	{
		frame_++;
	}
	else
	{
		frame_ = 0;
	}

	if (frame_ >= 6) { frame_ = 0; }//
	rect_.x = x_pos_ - map_x_;
	rect_.y = y_pos_ - map_y_;

	SDL_Rect* current_clip = &frame_clip_[frame_];
	SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };
	SDL_RenderCopy(des, p_object_, current_clip, &renderQuad);


}

void MainObject::HandelInputAction(SDL_Event events, SDL_Renderer* screen)
{
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_RIGHT:
		{
			status_ = WALK_RIGHT;
			input_type_.right_ = 1;
			input_type_.left_ = 0;
		} 
		break;

		case SDLK_LEFT:
		{
			status_ = WALK_LEFT;
			input_type_.left_ = 1;
			input_type_.right_ = 0;
		}
		break;
// di chuyen len
		case SDLK_UP:
		{
			
			input_type_.up_ = 1;
			input_type_.down_ = 0;
		}
		break;
// di chuyen xuong
		case SDLK_DOWN:
		{

			input_type_.up_ = 0;
			input_type_.down_ = 1;
		}
		break;
		}
		
	}
// nha phim
	else if (events.type == SDL_KEYUP)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_RIGHT:
		{
			
			input_type_.right_ = 0;
		}
		break;

		case SDLK_LEFT:
		{
			
			input_type_.left_ = 0;
		}
		break;

		case SDLK_UP:
		{

			input_type_.up_ = 0;
		}
		break;

		case SDLK_DOWN:
		{

			input_type_.down_ = 0;
		}
		break;
		}
	}
}

void MainObject::DoPlayer(Map& map_data, Mix_Chunk* g_eat, Mix_Chunk* g_dora, Mix_Chunk * g_chuong)
{
	

	x_val_ = 0;
	y_val_ =0;

	
	if (input_type_.left_ == 1)
	{
		x_val_ -= PLAYER_SPEED;
	}
	else if (input_type_.right_ == 1)
	{
		x_val_ += PLAYER_SPEED;
	}
	else if (input_type_.up_ == 1)
	{
		y_val_ -= PLAYER_SPEED;
	}
	else if (input_type_.down_ == 1)
	{
		y_val_ += PLAYER_SPEED;
	}
	CheckToMap(map_data, g_eat, g_dora, g_chuong);
	CenterEntityOnMap(map_data);
}
void MainObject::CenterEntityOnMap(Map& map_data)
{
	map_data.start_x_ = x_pos_ - (SCR_W / 2);
	if (map_data.start_x_ < 0)
	{
		map_data.start_x_ = 0;
	}
	else if (map_data.start_x_ + SCR_W >= map_data.max_x_)
	{
		map_data.start_x_ = map_data.max_x_ - SCR_W;
	}

	map_data.start_y_ = y_pos_ - (SCR_H / 2);
	if (map_data.start_y_ < 0)
	{
		map_data.start_y_ = 0;
	}
	else if (map_data.start_y_ + SCR_H >= map_data.max_y_)
	{
		map_data.start_y_ = map_data.max_y_ - SCR_H;
	}
}
void MainObject::CheckToMap(Map& map_data, Mix_Chunk* g_eat, Mix_Chunk* g_dora, Mix_Chunk* g_chuong)
{
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	
   // check chieu ngang


	int height_min = height_frame_ < TILE_SIZE ? height_frame_ : TILE_SIZE;

	x1 = (x_pos_ + x_val_) / TILE_SIZE;
	x2 = (x_pos_ + x_val_ + width_frame_ - 1) / TILE_SIZE;

	y1 = (y_pos_) / TILE_SIZE;
	y2 = (y_pos_ + height_min - 1) / TILE_SIZE;

	if (x1 >= 0 and x2 < MAX_MAP_X and y1 >= 0 and y2 < MAX_MAP_Y)
	{
		if (x_val_ > 0)
		{
			int val1 = map_data.tile[y1][x2];
			int val2 = map_data.tile[y2][x2];

			if (val1 == STATE_DICH or val2 == STATE_DICH)
			{
				val1 = BLANK_TILE;
				val2 = BLANK_TILE;
				
				check_dich = 1;

			}
			else if ((val1 == CANDY and val1 != 1) or (val2 == CANDY and val2 != 1))
			{
				map_data.tile[y1][x2] = 0;
				map_data.tile[y2][x2] = 0;
				Mix_PlayChannel(-1, g_eat, 0);
				Mix_PlayChannel(-1, g_dora, 0);
				
				IncreaseCandy();
			}
			else if ((val1 == DORAYAKI and val1 != 1) or (val2 == DORAYAKI and val2 != 1))
			{
				map_data.tile[y1][x2] = 0;
				map_data.tile[y2][x2] = 0;
				Mix_PlayChannel(-1, g_eat, 0);
				Mix_PlayChannel(-1, g_dora, 0);

				IncreaseDorayaki();
			}
			else if ((val1 == CHUONG and val1 != 1) or (val2 == CHUONG and val2 != 1))
			{
				map_data.tile[y1][x2] = 0;
				map_data.tile[y2][x2] = 0;
				Mix_PlayChannel(-1, g_eat, 0);
				Mix_PlayChannel(-1, g_chuong, 0);

				
			}
			else
			{
				if (val1 == GACH or val2 == GACH)
				{
					x_pos_ = x2 * TILE_SIZE;
					x_pos_ -= (width_frame_ + 1);
					x_val_ = 0;
					
				}
			}
		}
		else if (x_val_ < 0)
		{
			int val1 = map_data.tile[y1][x1];
			int val2 = map_data.tile[y2][x1];

			if (val1 == STATE_DICH or val2 == STATE_DICH)
			{
				val1 = BLANK_TILE;
				val2 = BLANK_TILE;
				
				check_dich = 1;
			}
			else if ((val1 == CANDY and val1 != 1) or (val2 == CANDY and val2 != 1))
			{
				 map_data.tile[y1][x1] = 0;
				 map_data.tile[y2][x1] = 0;
				 Mix_PlayChannel(-1, g_eat, 0);
				 Mix_PlayChannel(-1, g_dora, 0);
				IncreaseCandy();
			}
			else if ((val1 == DORAYAKI and val1 != 1) or (val2 == DORAYAKI and val2 != 1))
			{
				 map_data.tile[y1][x1] = 0;
				 map_data.tile[y2][x1] = 0;
				 Mix_PlayChannel(-1, g_eat, 0);
				 Mix_PlayChannel(-1, g_dora, 0);
				 IncreaseDorayaki();
			}
			else if ((val1 == CHUONG and val1 != 1) or (val2 == CHUONG and val2 != 1))
			{
				map_data.tile[y1][x1] = 0;
				map_data.tile[y2][x1] = 0;

				Mix_PlayChannel(-1, g_eat, 0);
				Mix_PlayChannel(-1, g_chuong, 0);
			}
			else
			{
				if (val1 == GACH or val2 == GACH)
				{
					x_pos_ = (x1 + 1) * TILE_SIZE;
					x_val_ = 0;
				}
			}
		}
	}

	// check chieu doc
	int width_min = width_frame_ < TILE_SIZE ? width_frame_ : TILE_SIZE;
	x1 = (x_pos_) / TILE_SIZE;
	x2 = (x_pos_ + width_min) / TILE_SIZE;

	y1 = (y_pos_ + y_val_) / TILE_SIZE;
	y2 = (y_pos_ + y_val_ + height_frame_ - 1) / TILE_SIZE;

	if (x1 >= 0 and x2 < MAX_MAP_X and y1 >= 0 and y2 < MAX_MAP_Y)
	{
		if (y_val_ > 0)
		{
			int val1 = map_data.tile[y2][x1];
			int val2 = map_data.tile[y2][x2];

			if (val1 == STATE_DICH or val2 == STATE_DICH)
			{
				val1 = BLANK_TILE;
				val2 = BLANK_TILE;
				check_dich = 1;
			}

			else if ((val1 == CANDY and val1!=1) or (val2 == CANDY and val2 !=1))
			{
				map_data.tile[y2][x1] = 0;
				map_data.tile[y2][x2] = 0;
				Mix_PlayChannel(-1, g_eat, 0);
				Mix_PlayChannel(-1, g_dora, 0);
				IncreaseCandy();
			}
			else if ((val1 == DORAYAKI and val1 != 1) or (val2 == DORAYAKI and val2 != 1))
			{
				map_data.tile[y2][x1] = 0;
				map_data.tile[y2][x2] = 0;
				Mix_PlayChannel(-1, g_eat, 0);
				Mix_PlayChannel(-1, g_dora, 0);
				IncreaseDorayaki();
			}
			else if ((val1 == CHUONG and val1 != 1) or (val2 == CHUONG and val2 != 1))
			{
				map_data.tile[y2][x1] = 0;
				map_data.tile[y2][x2] = 0;
				Mix_PlayChannel(-1, g_eat, 0);
				Mix_PlayChannel(-1, g_chuong, 0);
			}
			else
			{
				if (val1 == GACH or val2 == GACH)
				{
					y_pos_ = y2 * TILE_SIZE;
					y_pos_ -= (height_frame_ + 1);
					y_val_ = 0;

					
				}
		    }
		}
		else if (y_val_ < 0)
		{
			int val1 = map_data.tile[y1][x1];
			int val2 = map_data.tile[y1][x2];
			if (val1 == STATE_DICH or val2 == STATE_DICH)
			{
				val1 = BLANK_TILE;
				val2 = BLANK_TILE;
				check_dich = 1;
				
			}
			else if ((val1 == CANDY and val1 != 1) or (val2 == CANDY and val2 != 1))
			{
				 map_data.tile[y1][x1] = 0;
				 map_data.tile[y1][x2] = 0;
				 Mix_PlayChannel(-1, g_eat, 0);
				 Mix_PlayChannel(-1, g_dora, 0);
				IncreaseCandy();

			}
			else if ((val1 == DORAYAKI and val1 != 1) or (val2 == DORAYAKI and val2 != 1))
			{
				map_data.tile[y1][x1] = 0;
				map_data.tile[y1][x2] = 0;
				Mix_PlayChannel(-1, g_eat, 0);
				Mix_PlayChannel(-1, g_dora, 0);
				IncreaseDorayaki();

			}
			else if ((val1 == CHUONG and val1 != 1) or (val2 == CHUONG and val2 != 1))
			{
				map_data.tile[y1][x1] = 0;
				map_data.tile[y1][x2] = 0;
				Mix_PlayChannel(-1, g_eat, 0);
				Mix_PlayChannel(-1, g_chuong, 0);

			}
			else
			{
				if (val1 ==GACH or val2 == GACH)
				{
					y_pos_ = (y1 + 1) * TILE_SIZE;
					y_val_ = 0;

				}
			}
		}
	}

	x_pos_ += x_val_;
	y_pos_ += y_val_;

	if (x_pos_ < 0)
	{
		x_pos_ = 0;
	}
	else if (x_pos_ + width_frame_ > map_data.max_x_)
	{
		x_pos_ = (map_data.max_x_ - width_frame_ - 1);

	}
}

	
