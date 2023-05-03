#ifndef HINH_HOC_H
#define HINH_HOC_H

#include"Common.h"

typedef struct FormatHinhHoc
{
public:
	FormatHinhHoc(int left, int top, int width, int height)
	{
		left_ = left; top_ = top; width_ = width; height_ = height;
	};

	int left_;
	int top_;
	int width_;
	int height_;
};

typedef struct ColorData
{
public:
	ColorData(Uint8 r, Uint8 g, Uint8 b)
	{
		red_ = r; green_ = g; blue_ = b;
	};

	Uint8 red_;
	Uint8 green_;
	Uint8 blue_;
};
class HinhHoc
{
public:
	static void RenderRectangle(const FormatHinhHoc& geo_size, const ColorData& color_data, SDL_Renderer* screen);
	static void RenderOutline(const FormatHinhHoc& geo_size, const ColorData& color_data, SDL_Renderer* screen);

};
#endif

