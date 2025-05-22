#include "Base.h"
#include "Common.h"

Base::Base()
    : p_object_(nullptr), rect_{ 0, 0, 0, 0 } {}

Base::~Base()
{
    Free();
}

bool Base::LoadImg(const std::string& path, SDL_Renderer* screen)
{
    SDL_Surface* load_surface = IMG_Load(path.c_str());
    if (!load_surface) return false;

    SDL_SetColorKey(load_surface, SDL_TRUE,
        SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));

    SDL_Texture* new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
    if (!new_texture)
    {
        SDL_FreeSurface(load_surface);
        return false;
    }

    rect_.w = load_surface->w;
    rect_.h = load_surface->h;

    SDL_FreeSurface(load_surface);
    p_object_ = new_texture;
    return true;
}

void Base::Render(SDL_Renderer* des, const SDL_Rect* clip)
{
    SDL_Rect render_quad = { rect_.x, rect_.y, rect_.w, rect_.h };
    SDL_RenderCopy(des, p_object_, clip, &render_quad);
}

void Base::Free()
{
    if (p_object_)
    {
        SDL_DestroyTexture(p_object_);
        p_object_ = nullptr;
        rect_.w = rect_.h = 0;
    }
}
