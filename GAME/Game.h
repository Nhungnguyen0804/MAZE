#ifndef NORMAL_H
#define NORMAL_H
#include"Common.h"
#include"image.h"

using namespace std;




// nut PLAY
#define X_NUT_START 487// vi tri x
#define Y_NUT_START 476// vi tri y
#define W_NUT_START 270
#define H_NUT_START 139 

// nut HUONG DAN menu 
#define X_NUT_HD 20 // vi tri x
#define Y_NUT_HD 380 // vi tri y
#define W_NUT_HD 156
#define H_NUT_HD 70

// NOI DUNG: HUONG DAN menu 
#define X_HD 65 // vi tri x
#define Y_HD 33 // vi tri y
#define W_HD 990
#define H_HD 654

// nut AM THANH menu 
#define X_NUT_SOUND_MENU 20 // vi tri x
#define Y_NUT_SOUND_MENU 487 // vi tri y
#define W_NUT_SOUND_MENU 156
#define H_NUT_SOUND_MENU 70
// nut QUIT
#define X_NUT_QUIT 20 // vi tri x
#define Y_NUT_QUIT 594 // vi tri y
#define W_NUT_QUIT 156
#define H_NUT_QUIT 70


// nut AM THANH 
#define X_NUT_SOUND 10 // vi tri x
#define Y_NUT_SOUND 0 // vi tri y
#define W_NUT_SOUND 55
#define H_NUT_SOUND 55


// co 2 trang thai cua con chuot khi bam la up va down
enum class Button_Status {
	Up,
	Down
};

class Button // lop bam chuot
{
	int x = 0, y = 0;
	int w = 0, h = 0;
	SDL_Texture* Up_text = NULL; // hinh anh
	SDL_Texture* Down_text = NULL;
public:
	SDL_Renderer* renderer = NULL; // nen khai bao ngoai

	Button_Status status = Button_Status::Up; // dat trang thai cho nhan chuot la:tha
	SDL_Rect Button_rect = { x, y, w, h }; // vi tri cua chuot x y w h
	Button() {};
	Button(SDL_Renderer* _renderer, SDL_Rect rect) : renderer(_renderer), Button_rect(rect) {};// cai j day
	//co
	void create_text(const char* up, const char* down); // tao texture load anh nut chon len / down
	//co
	void render();
};
class Game {
	SDL_Renderer* renderer = NULL; // nen khai bao ngoai
	SDL_Event e;

	long point = 0, target_point = 0;
	int move = 0;
	Button game_button[5];
	Button select_map[6]; // mang trong ham result

	bool checkMenuLv = 0;
	bool quit_menu = 0;
	
	
public:
	Game();
	~Game();
	Game(SDL_Renderer* _renderer, SDL_Event _e) {
		renderer = _renderer; // ??
		e = _e;
	}
	int initMenu();
	int initSelectMap();
	int selectLevel();
	//int Gameplay();
	int result(bool res, int checkLv, Uint32 val_time, int checkMap);
	int check_menu_lv()const { return checkMenuLv; }
	

};
#endif 


