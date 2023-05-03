#include"Game.h"
#include"Common.h"
#include<iostream>
#include "SDL_mixer_function.h"
#include"TextObj.h"
using namespace std;
TTF_Font* font_score = NULL;
const char* menu_start_image = "image/menuStart.png"; //menu
// nut start o menu 1
const char* start_button_up = "image/start_button_up.png";
const char* start_button_down = "image/start_button_down.png";

// anh sound o menu 1
const char* menu_sound_up = "image/menu_sound_on.png";
const char* menu_sound_down = "image/menu_sound_off.png";

// anh huong dan o menu 1
const char* huong_dan_up = "image/menu_huong_dan_up.png";
const char* huong_dan_down = "image/menu_huong_dan_down.png";
const char* huong_dan = "image/huong_dan.png";
// anh quit o menu 1
const char* menu_quit_up = "image/menu_quit_up.png";
const char* menu_quit_down = "image/menu_quit_up.png";

//select map
const char* nen_select_map = "image/selectMap.png";
const char* forest_up = "image/forest_up.png";
const char* forest_down = "image/forest_down.png";
const char* city_up = "image/city_up.png";
const char* city_down = "image/city_down.png";
const char* home_up = "image/home_up.png";
const char* home_down = "image/home_down.png";
const char* sea_up = "image/sea_up.png";
const char* sea_down = "image/sea_down.png";
const char* bac_cuc_up = "image/bac_cuc_up.png";
const char* bac_cuc_down = "image/bac_cuc_down.png";
const char* sky_up = "image/sky_up.png";
const char* sky_down = "image/sky_down.png";

//MENU LEVEL
const char* menu_level = "image/menu_level.png"; //menu chon level

const char* easybutton = "image/easy.png";
const char* easybuttondown = "image/easyDown.png";
const char* mediumbutton = "image/medium.png";
const char* mediumbuttondown = "image/mediumDown.png";
const char* hardbutton = "image/hard.png";
const char* hardbuttondown = "image/hardDown.png";
const char* superhardbutton = "image/superhard.png";
const char* superhardbuttondown = "image/superhardDown.png";

const char* soundOnbutton = "image/soundOn.png";
const char* soundOffbutton = "image/soundOff.png";

//tai menu cuoi cung
const char* menu_cuoi_win = "image/you win.png";
const char* menu_cuoi_lose = "image/you lose.png";

const char* soundOnbutton_Result_win = "image/soundOn_Result_win.png";
const char* soundOffbutton_Result_win = "image/soundOff_Result_win.png";

const char* soundOnbutton_Result_lose = "image/soundOn_Result_lose.png";
const char* soundOffbutton_Result_lose = "image/soundOff_Result_lose.png";

//x,y,w,h
SDL_Rect background_rect = { 0, 0, SCR_W,SCR_H };

SDL_Rect start_rect = { X_NUT_START, Y_NUT_START, W_NUT_START, H_NUT_START };

SDL_Rect huong_dan_rect = { X_NUT_HD , Y_NUT_HD ,  W_NUT_HD, H_NUT_HD };
SDL_Rect noi_dung_huong_dan_rect = { X_HD , Y_HD ,  W_HD, H_HD };
SDL_Rect sound_menu_rect = { X_NUT_SOUND_MENU , Y_NUT_SOUND_MENU ,  W_NUT_SOUND_MENU, H_NUT_SOUND_MENU  };
SDL_Rect menu_quit_rect = { X_NUT_QUIT , Y_NUT_QUIT ,  W_NUT_QUIT, H_NUT_QUIT };


SDL_Rect sound_rect = { X_NUT_SOUND , Y_NUT_SOUND ,  W_NUT_SOUND, H_NUT_SOUND };
SDL_Rect Result_rect = { 900 / 2 + 50, 600 / 2 - 20, 200, 60 };
SDL_Rect Title_rect = { 256, 523, 200, 50 };

void Button::create_text(const char* up, const char* down) {

    // load anh up or down
    SDL_Surface* image = NULL;
    image = IMG_Load(up);
    Up_text = SDL_CreateTextureFromSurface(renderer, image);
    image = IMG_Load(down);
    Down_text = SDL_CreateTextureFromSurface(renderer, image);
}

void Button::render() {
    if (Up_text == NULL || Down_text == NULL) cout << "loi load" << SDL_GetError() << endl; // loi load anh up or down
    // neu k = null
    // neu trang thai status cua chuot up -> tai anh up len
    if (status == Button_Status::Up) SDL_RenderCopy(renderer, Up_text, NULL, &Button_rect);
    // neu k tai anh down
    else SDL_RenderCopy(renderer, Down_text, NULL, &Button_rect);
}

int Game::initMenu() {
  
   
    
 //show anh mh, = background.png ,SDL_Rect back_rect = { 0, 0, 900, 600 };
    Show_image(renderer, menu_start_image, background_rect);
   
 //show anh , mh,= play , rect  ,SDL_Rect play_rect = { 700, 500, 150, 80 };
    Show_image(renderer, start_button_up, start_rect);
 // show sound o menu 1
     Show_image(renderer, menu_sound_up , sound_menu_rect);
 //show bieu tuong sound o menu
    Show_image(renderer, huong_dan_up , huong_dan_rect);
//Show QUIT menu
    Show_image(renderer, menu_quit_up, menu_quit_rect);
 // nhac nen
    

    
  

    // t tu 
    bool quit = false;
    bool checkHD = 0;
    bool checkSound = 0;
    while (!quit) {
        if (SDL_PollEvent(&e))
        {
            
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                { // bam chuot trai


                    SDL_Rect start_rect = { X_NUT_START, Y_NUT_START, W_NUT_START, H_NUT_START };
                    //chuot<=  x+w , chuot >= x , chuot <= y+h , chuot >= y 
                    bool startBut = (e.button.x <= X_NUT_START + W_NUT_START) && (e.button.x >= X_NUT_START) && (e.button.y <= Y_NUT_START+H_NUT_START) && (e.button.y >= Y_NUT_START);
                    // neu bam nut play cua menu start :
                    if (startBut)
                    {
                        Show_image(renderer, start_button_down, start_rect); 
       
                        SDL_Delay(50);
                        quit = true;
                        break;
                       
                        
                    }
                    
                    SDL_Rect quit_menu_rect = { X_NUT_QUIT, Y_NUT_QUIT, W_NUT_QUIT, H_NUT_QUIT };
                    //chuot bam<=  x+w , chuot bam >= x , chuot bam <= y+h , chuot bam >= y 
                    bool quitBut = (e.button.x <= X_NUT_QUIT + W_NUT_QUIT) && (e.button.x >= X_NUT_QUIT) && (e.button.y <= Y_NUT_QUIT + H_NUT_QUIT) && (e.button.y >= Y_NUT_QUIT);
                    // neu bam nut play cua menu start :
                    if (quitBut)
                    {
                        Show_image(renderer, menu_quit_down, menu_quit_rect);
                        SDL_Delay(50);
                        return 1;
                    }
                    // bam bieu tuong sound ->tat am
                    // bam ngoai sound ->bat am
                    SDL_Rect sound_menu_rect = { X_NUT_SOUND_MENU , Y_NUT_SOUND_MENU ,  W_NUT_SOUND_MENU, H_NUT_SOUND_MENU };
                    bool soundBut  = (e.button.x <= X_NUT_SOUND_MENU + W_NUT_SOUND_MENU) && (e.button.x >= X_NUT_SOUND_MENU) && (e.button.y <= Y_NUT_SOUND_MENU + H_NUT_SOUND_MENU) && (e.button.y >= Y_NUT_SOUND_MENU);
                    if (soundBut)// neu bam
                    {

                       
                        Show_image(renderer, menu_sound_down, sound_menu_rect);
                        Mix_PauseMusic(); // bam vao thi tam dung nhac
                        Mix_Pause(-1);
                        checkSound = 1;

                    }
                    else

                    {
                        checkSound = 0;
                        Show_image(renderer, menu_sound_up, sound_menu_rect);
                        Mix_ResumeMusic();
                        Mix_Resume(-1);
                       

                    }
                    
                    
                    SDL_Rect huong_dan_rect = { X_NUT_HD , Y_NUT_HD ,  W_NUT_HD, H_NUT_HD };
                    bool huongDanBut = (e.button.x <= X_NUT_HD + W_NUT_HD) && (e.button.x >= X_NUT_HD) && (e.button.y <= Y_NUT_HD + H_NUT_HD) && (e.button.y >= Y_NUT_HD);
                    // neu bam nut play cua menu start :
                    if (huongDanBut)
                    {
                        Show_image(renderer, huong_dan_down, huong_dan_rect); // nen doi mau anh thanh do
                        SDL_Delay(50);
                        checkHD = 1;



                    }
                    else { checkHD = 0; }
                    
                  
                    
                    
                }
                
            }
            else if (e.type == SDL_MOUSEBUTTONUP)
            {
                Show_image(renderer, start_button_up, start_rect);
                Show_image(renderer, huong_dan_up, huong_dan_rect);
                Show_image(renderer, menu_quit_up, menu_quit_rect);
                if (checkHD == 1)
                {
                    Show_image(renderer, huong_dan, noi_dung_huong_dan_rect);

                }
                else
                {
                    SDL_RenderClear(renderer);
                    // show anh mh, = background.png, SDL_Rect back_rect = { 0, 0, 900, 600 };
                    Show_image(renderer, menu_start_image, background_rect);

                    //show anh , mh,= play , rect  ,SDL_Rect play_rect = { 700, 500, 150, 80 };
                    Show_image(renderer, start_button_up, start_rect);
                    Show_image(renderer, menu_quit_up, menu_quit_rect);
                    // show sound o menu 1
                    if (checkSound == 1)
                    {
                        Show_image(renderer, menu_sound_down, sound_menu_rect);
                    }
                   if( checkSound==0)
                    {
                        Show_image(renderer, menu_sound_up, sound_menu_rect);
                    }
                    //show bieu tuong sound o menu
                    Show_image(renderer, huong_dan_up, huong_dan_rect);
                    // nhac nen
                }
                

            }
            
            
            
        
        }
    
        
    }
}
Game::Game()
{
    
   
    
}
Game::~Game(){}

int Game::initSelectMap()
{
  
    for (int i = 0; i < 3; i++) {
        select_map[i].Button_rect = { 37, 53 + i * (120+50), 210, 120};
        select_map[i].renderer = renderer; 
        
    }
    for (int i = 3; i < 6; i++) {
        select_map[i].Button_rect = { 876, 53 + (i-3) * (120 + 50), 210, 120 };
        select_map[i].renderer = renderer;

    }
    select_map[0].create_text(forest_up, forest_down);
    select_map[1].create_text(city_up, city_down);
    select_map[2].create_text(home_up, home_down);
    select_map[3].create_text(sea_up, sea_down);
    select_map[4].create_text(bac_cuc_up, bac_cuc_down);
    select_map[5].create_text(sky_up, sky_down);
    bool quit = false;
    for (int i = 0; i < 6; i++)
    {
        select_map[i].status = Button_Status::Up;
    }
    Show_image(renderer, nen_select_map, background_rect);
    for (int i = 0; i < 6; i++) {
        select_map[i].status == Button_Status::Up;
        select_map[i].render();

    }
    SDL_RenderPresent(renderer);
    while (!quit) {
        if (SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
           
            for (int i = 0; i < 6; i++)
            {
                if (e.button.x <= select_map[i].Button_rect.x + select_map[i].Button_rect.w
                    && e.button.x >= select_map[i].Button_rect.x
                    && e.button.y <= select_map[i].Button_rect.y + select_map[i].Button_rect.h
                    && e.button.y >= select_map[i].Button_rect.y) {
                    if (select_map[i].status == Button_Status::Up)
                    {
                        select_map[i].status = Button_Status::Down;
                    }
                    else  select_map[i].status = Button_Status::Up;

                    select_map[i].render();
                    SDL_RenderPresent(renderer);
                    SDL_Delay(50);
                    switch (i) {
                    case 0:// EASY
                        return 30;
                        quit = true;
                        break;
                    case 1://MEDIUM
                        return 31;
                        quit = true;
                        break;
                    case 2: // HARD
                        return 32;
                        quit = true;
                        break;
                    case 3: // VERY HARD
                        return 33;
                        quit = true;
                        break;
                    case 4: // VERY HARD
                        return 34;
                        quit = true;
                        break;
                    case 5: // VERY HARD
                        return 35;
                        quit = true;
                        break;
                    }

                    
                    select_map[i].status = Button_Status::Up;
                    SDL_Delay(50);
                    break;
                }
            }
        }
        else if (e.type == SDL_MOUSEBUTTONUP)
        {
            for (int i = 0; i < 4; i++)
                select_map[i].status = Button_Status::Up;
        }
    }
    for (int i = 0; i < 4; i++)
        select_map[i].status = Button_Status::Up;
}

int Game::selectLevel() {

    game_button[4].Button_rect = { X_NUT_SOUND , Y_NUT_SOUND ,  W_NUT_SOUND, H_NUT_SOUND };// bieu tuong loa phai man hinh chon level //{ 0, 0, 55, 55 };//
    game_button[4].renderer = renderer;


    for (int i = 0; i < 4; i++) {
        game_button[i].Button_rect = { 327, 85 + i * 142, 262, 85 }; // vi tri cua nut bam
        game_button[i].renderer = renderer; // hien len,Button(SDL_Renderer* _renderer, SDL_Rect rect) : renderer(_renderer)
        //, Button_rect(rect) {};// cai j day
    }
    game_button[0].create_text(easybutton, easybuttondown); // nut easy 
    game_button[1].create_text(mediumbutton, mediumbuttondown); // nut medium
    game_button[2].create_text(hardbutton, hardbuttondown); // nut hard
    game_button[3].create_text(superhardbutton, superhardbuttondown); // nut super 
    game_button[4].create_text(soundOnbutton, soundOffbutton); // bieu tuong bat tat am thanh
    bool quit = false;
    for (int i = 0; i < 4; i++)
    {
        game_button[i].status = Button_Status::Up;
    }
    Show_image(renderer, menu_level , background_rect);
        for (int i = 0; i < 5; i++) {
            game_button[i].status == Button_Status::Up;
            game_button[i].render();
            
        }
        //LoadFont("Select Level", renderer, Title_rect);
        SDL_RenderPresent(renderer);
        while (!quit) {
            if (SDL_PollEvent(&e) == 0) continue;
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                  if (!Mix_Paused(-1))Mix_PlayChannel(-1, reverse_sound, 0);
                for (int i = 0; i < 5; i++) 
                {
                    if (e.button.x <= game_button[i].Button_rect.x + game_button[i].Button_rect.w
                        && e.button.x >= game_button[i].Button_rect.x
                        && e.button.y <= game_button[i].Button_rect.y + game_button[i].Button_rect.h
                        && e.button.y >= game_button[i].Button_rect.y) {
                        if (game_button[i].status == Button_Status::Up)
                        {
                            game_button[i].status = Button_Status::Down;
                        }
                        else  game_button[i].status = Button_Status::Up;

                        game_button[i].render();
                        SDL_RenderPresent(renderer);
                        SDL_Delay(50);
                        switch (i) {
                        case 0:// EASY
                            return 20;
                            quit = true;
                            break;
                        case 1://MEDIUM
                            return 21;
                            quit = true;
                            break;
                        case 2: // HARD
                            return 22;
                            quit = true;
                            break;
                        case 3: // VERY HARD
                            return 23;
                            quit = true;
                            break;
                        }
                   
                        if (i == 4) {
                            // k bam vao bieu tuong nen no up
                            if (game_button[i].status == Button_Status::Up) {
                                Mix_ResumeMusic();
                                Mix_Resume(-1);
                            }
                            else {
                                Mix_PauseMusic(); // bam vao thi tam dung nhac
                                Mix_Pause(-1);
                            }
                        }
                        else game_button[i].status = Button_Status::Up;
                        SDL_Delay(50);
                        break;
                    }
                }
            }
            else if (e.type == SDL_MOUSEBUTTONUP)
            {
                for (int i = 0; i < 4; i++)
                game_button[i].status = Button_Status::Up;
            }
        }
        for (int i = 0; i < 4; i++)
            game_button[i].status = Button_Status::Up;

}


// hien ket qua
int Game::result(bool res, int checkLV, Uint32 val_time, int checkMap)
{
    // menu ket qua sau khi choi thang/ thua

    TextObj hien_diem;
    //Button game_button[5]; o game.h
    for (int i = 0; i < 4; i++) {
        game_button[i].Button_rect = { 40 + 373 * i, 250, 300, 100 }; // vi tri cua nut bam
        game_button[i].renderer = renderer; // hien len,Button(SDL_Renderer* _renderer, SDL_Rect rect) : renderer(_renderer)
        //, Button_rect(rect) {};// cai j day
    }
    //void create_text(const char* up, const char* down);  game.h
    game_button[0].create_text("image/playAgain.png", "image/playAgainDown.png");// tai anh play again
    game_button[1].create_text("image/menu.png", "image/menuDown.png"); //tai anh chon menu
    game_button[2].create_text("image/quit.png", "image/quitDown.png"); // tai anh con quit

    if (res)
    {
        Show_image(renderer, menu_cuoi_win, background_rect);
        game_button[4].create_text(soundOnbutton_Result_win, soundOffbutton_Result_win); // bieu tuong bat tat am thanh
        hien_diem.SetColor(TextObj::WHITE_TEXT);
    }
    else
    {
        Show_image(renderer, menu_cuoi_lose, background_rect);
        game_button[4].create_text(soundOnbutton_Result_lose, soundOffbutton_Result_lose); // bieu tuong bat tat am thanh
        hien_diem.SetColor(TextObj::BLACK_TEXT);
    }
    for (int i = 0; i < 4; i++)
    {
        game_button[i].status = Button_Status::Up;
    }
    for (int i = 0; i < 3; i++) {
        game_button[i].status == Button_Status::Up;
        game_button[i].render(); // hien thi nut chon
        
    }
   
    game_button[4].render();// bieu tuong am thanh

    
    
    std::string ten_nhan = "Score:";
    std::string so_diem = std::to_string(val_time);
    ten_nhan += so_diem;
    hien_diem.SetText(ten_nhan);
    hien_diem.LoadFromRenderText(font_score, renderer);
    hien_diem.RenderText(renderer, 402, 173, NULL, NULL, NULL, SDL_FLIP_NONE);
    
    // update mh

    SDL_RenderPresent(renderer);


    while (true) {
        if (SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
            //   if (!Mix_Paused(-1)) Mix_PlayChannel(-1, reverse_sound, 0);
            for (int i = 0; i < 5; i++) {
                if (e.button.x <= game_button[i].Button_rect.x + game_button[i].Button_rect.w
                    && e.button.x >= game_button[i].Button_rect.x
                    && e.button.y <= game_button[i].Button_rect.y + game_button[i].Button_rect.h
                    && e.button.y >= game_button[i].Button_rect.y) {
                    if (game_button[i].status == Button_Status::Up) { game_button[i].status = Button_Status::Down; }
                    else  game_button[i].status = Button_Status::Up;
                    game_button[i].render();
                    SDL_RenderPresent(renderer);
                    SDL_Delay(50);
                    if (i == 0) return checkLV;
                    else if (i == 1) return checkMap;


                    if (i == 4) {
                        if (game_button[i].status == Button_Status::Up) 
                        {
                            Mix_ResumeMusic();
                            Mix_Resume(-1);
                        }
                        else 
                        {
                            Mix_PauseMusic(); // bam vao thi tam dung nhac
                            Mix_Pause(-1);
                        }
                    }
                    else {
                        game_button[i].status = Button_Status::Up;
                        if (i == 2) return -1;
                        else return i;
                    }
                }
            }
        }
        else if(e.type == SDL_MOUSEBUTTONUP)
        {
            for (int i = 0; i < 4; i++)
            game_button[i].status = Button_Status::Up;
        }
    }
    for (int i = 0; i < 4; i++)
        game_button[i].status = Button_Status::Up;
}


