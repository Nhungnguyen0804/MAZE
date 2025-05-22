
#include "Common.h"
#include "Base.h"
#include "Game_map.h"

#include"MainObject.h"
#include"ImpTimer.h"

#include"TextObj.h"
#include"HinhHoc.h"

#include"image.h"
#include"Game.h"

#include<iostream>
using namespace std;

Base g_background;

TTF_Font* font_time = NULL;
extern TTF_Font* font_score;

const char* back_ground = NULL;


bool InitData()
{
    bool suc = 1;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0) { cout <<"rec init <0" << endl; return 0; }
    else
    {

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

        gWin = SDL_CreateWindow("MAZE",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCR_W,
            SCR_H,
            SDL_WINDOW_SHOWN
        );

        if (gWin == NULL) { cout << "gWin null" << endl; return 0; }
        else
        {
            gRen = SDL_CreateRenderer(gWin, -1, SDL_RENDERER_ACCELERATED);
            if (gRen == NULL)
            {
                cout << "gRen null" << endl;
                return 0;
            }
            else
            {
                SDL_SetRenderDrawColor(gRen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
                int imgFlags = IMG_INIT_PNG;
                if (!IMG_Init(imgFlags) and imgFlags) suc = 0;


            }

            if (TTF_Init() == -1) { suc = 0; }
            // chinh kich thuoc font
            font_time = TTF_OpenFont("font//li.ttf", 24);
            font_score = TTF_OpenFont("font//li.ttf", 72);
            if (font_time == NULL and font_score == NULL)
            if (font_time == NULL)
            {
                suc = 0;
            }

            if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
            {
                    cout <<"k the init mix" << endl;suc = 0;
            }

            gNen = Mix_LoadMUS("audio//nen_dora.mp3");
            g_eat = Mix_LoadWAV("audio//coin.wav");
            g_dora = Mix_LoadWAV("audio//dorayaki.wav");
            g_chuong = Mix_LoadWAV("audio//chuong.wav");
            if (gNen == NULL or g_eat == NULL or g_dora == NULL or g_chuong == NULL)
            {
                cout << "k co file nhac" << endl;
                return 0;
                
            }
           
        }
    }
    return suc;
}


bool LoadBackground()
{
    bool ret = 1;
    //bool ret = g_background.LoadImg(back_ground, gRen);
    return ret;
}

void close()
{
    g_background.Free();
    SDL_DestroyRenderer(gRen);
    gRen = NULL;
    SDL_DestroyWindow(gWin);
    gWin = NULL;
    IMG_Quit();
    SDL_Quit();
}
int main(int argc, char* argv[])
{
    // fps timer
    ImpTimer fps_timer;


    if (InitData() == 0) { printf("initdata =0"); return -1; }
    if (LoadBackground() == 0) { printf("load background = 0 "); return -1; }

   
    cout << "main ok";
   


    
   

    //nhac nen
    Mix_PlayMusic(gNen, -1);

    bool checkDich = 0;

    clock_t start , startMenu, endMenu, useMenu;
    bool quit = 0;
    
    
    while (!quit)
    {
       
        // thoi gian bat dau mo menu
        startMenu = clock()/1000;
        // menu start
        Game GameH(gRen, gE);
        quit = GameH.initMenu(); 
        if (!quit)
        {
            bool quit_choose_map = 0;
            while (!quit_choose_map)
            {
                int checkMap = GameH.initSelectMap();
                if (checkMap == 30)
                {
                    back_ground = "image//background_forest.png";
                    g_background.LoadImg(back_ground, gRen);
                }
                else if (checkMap == 31)
                {
                    back_ground = "image//background_city.png";
                    g_background.LoadImg(back_ground, gRen);
                }
                else if (checkMap == 32)
                {
                    back_ground = "image//background_home.png";
                    g_background.LoadImg(back_ground, gRen);
                }
                else if (checkMap == 33)
                {
                    back_ground = "image//background_sea.png";
                    g_background.LoadImg(back_ground, gRen);
                }
                else if (checkMap == 34)
                {
                    back_ground = "image//background_ice.png";
                    g_background.LoadImg(back_ground, gRen);
                }
                else
                {
                    back_ground = "image//background_sky.png";
                    g_background.LoadImg(back_ground, gRen);
                }
                bool quit_level = 0;
                while (!quit_level)
                {
                    // menu st = 10 
                    // menu level
                    GameMap game_map;
                    int checkLV = GameH.selectLevel();
                    if (checkLV == 20)
                    {
                        char gm[] = "image/map/map01.dat";
                        game_map.LoadMap(gm);
                        game_map.LoadTiles(gRen, checkMap);
                    }
                    else if (checkLV == 21)
                    {
                        char gm[] = "image/map/map02.dat";
                        game_map.LoadMap(gm);
                        game_map.LoadTiles(gRen, checkMap);
                    }
                    else if (checkLV == 22)
                    {
                        char gm[] = "image/map/map03.dat";
                        game_map.LoadMap(gm);
                        game_map.LoadTiles(gRen, checkMap);
                    }
                    else
                    {
                        char gm[] = "image/map/map04.dat";
                        game_map.LoadMap(gm);
                        game_map.LoadTiles(gRen, checkMap);
                    }
                    MainObject p_player;
                    p_player.LoadImg("image//dora_right.png", gRen);
                    p_player.set_clips();



                    // gio moi bat dau tro choi
                   // int CheckMenu = GameH.check_menu_lv();

                    // thoi gian end menu
                    endMenu = clock() / 1000;
                    // thoi gian sd menu
                    useMenu = endMenu - startMenu;

                    bool quit_play = 0;

                    // doi mau Time:
                    TextObj time_game;
                    time_game.SetColor(TextObj::WHITE_TEXT);
                    Uint32 thoi_gian_luc_ve_dich = 0;

                    while (!quit_play)
                    {

                        start = clock() / 1000;

                        // fps timer bat dau la may gio

                       // fps_timer.start();

                        while (SDL_PollEvent(&gE))
                        {
                            if (gE.type == SDL_QUIT)
                            {
                                quit = 1;
                            }

                            p_player.HandelInputAction(gE, gRen);
                        }

                        SDL_SetRenderDrawColor(gRen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);

                        SDL_RenderClear(gRen);

                        g_background.Render(gRen, NULL);



                        Map map_data = game_map.getMap();




                        p_player.SetMapXY(map_data.start_x_, map_data.start_y_);

                        p_player.DoPlayer(map_data, g_eat, g_dora, g_chuong);

                        // SHOW DORA
                        p_player.Show(gRen);

                        // DAT MAP
                        game_map.SetMap(map_data);
                        //ve map
                        game_map.DrawMap(gRen);






                        // show hinh hoc
                        // hcn la khung chua time: 
                        FormatHinhHoc rectangle_size(0, 0, SCR_W, 40);
                        ColorData color_data(83, 144, 173);
                        HinhHoc::RenderRectangle(rectangle_size, color_data, gRen);
                        // outline cho hcn
                        FormatHinhHoc outLineSize(1, 1, SCR_W - 1, 38);
                        ColorData color_data2(255, 255, 255);
                        HinhHoc::RenderOutline(outLineSize, color_data2, gRen);

                        int count_candy = p_player.getCandyCount();
                        int time_khi_an_candy = count_candy * SO_GIAY_CUA_CANDY;

                        int count_dorayaki = p_player.getDorayakiCount();
                        int time_khi_an_dorayaki = count_dorayaki * SO_GIAY_CUA_DORAYAKI;
                        //fps timer bat dau la may gio

                        fps_timer.start();
                        //hien time
                        std::string str_time = "Time: "; // nhãn


                        Uint32 time_val = SDL_GetTicks() / 1000;

                        Uint32 val_time = 50 + useMenu - start + time_khi_an_candy + time_khi_an_dorayaki; // dem nguoc tu ... s tro xuong

                        if (val_time <= 10)
                        {
                            time_game.SetColor(TextObj::RED_TEXT);
                        }

                        if (val_time <= 0 or val_time > 1000)
                        {
                            // end game : game over
                            quit_play = 1;
                            break;
                            GameH.result(checkDich, checkLV, val_time, checkMap);
                        }
                        else
                        {
                            quit_play = 0;
                            std::string str_val = std::to_string(val_time);
                            str_time += str_val;
                            time_game.SetText(str_time);
                            time_game.LoadFromRenderText(font_time, gRen);
                            time_game.RenderText(gRen, SCR_W - 150, 10, NULL, NULL, NULL, SDL_FLIP_NONE);
                        }


                        // t thuc te da troi qua
                        int real_imp_time = fps_timer.get_ticks();
                        // 1 frame chay mat bao lau
                        int time_one_frame = 1000 / FRAME_PER_SECOND;
                        // so sanh thoi gian
                        if (real_imp_time < time_one_frame)
                        {
                            int delay_time = time_one_frame - real_imp_time;
                            if (delay_time >= 0)
                            {
                                SDL_Delay(delay_time); // tao ra do tre
                            }
                        }
                        SDL_RenderPresent(gRen);

                        checkDich = p_player.den_dich_chua(); // den dich no tra gia tri true
                        if (checkDich)
                        {
                            thoi_gian_luc_ve_dich = val_time;
                            quit_play = 1;
                            break;
                            GameH.result(checkDich, checkLV, val_time, checkMap);
                        } // end chtrinh


                    }
                    quit_play = 0;
                    int checkResult = GameH.result(checkDich, checkLV, thoi_gian_luc_ve_dich,checkMap);
                    if (checkResult >= 20 and checkResult <= 23) { checkLV = GameH.selectLevel(); }
                    else if (checkResult >= 30 and checkResult <= 35) 
                    { quit = GameH.initMenu();  checkMap = GameH.initSelectMap();
                    if (checkMap == 30)
                    {
                        back_ground = "image//background_forest.png";
                        g_background.LoadImg(back_ground, gRen);
                    }
                    else if (checkMap == 31)
                    {
                        back_ground = "image//background_city.png";
                        g_background.LoadImg(back_ground, gRen);
                    }
                    else if (checkMap == 32)
                    {
                        back_ground = "image//background_home.png";
                        g_background.LoadImg(back_ground, gRen);
                    }
                    else if (checkMap == 33)
                    {
                        back_ground = "image//background_sea.png";
                        g_background.LoadImg(back_ground, gRen);
                    }
                    else if (checkMap == 34)
                    {
                        back_ground = "image//background_ice.png";
                        g_background.LoadImg(back_ground, gRen);
                    }
                    else
                    {
                        back_ground = "image//background_sky.png";
                        g_background.LoadImg(back_ground, gRen);
                    }
                    }
                    else
                    {
                        quit = 1; quit_choose_map = 1; quit_level = 1;

                    }
                }
            }
           
        }

    }
    close();
    return 0;
}
