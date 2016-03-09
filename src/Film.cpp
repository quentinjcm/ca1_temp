#include <iostream>

#include <SDL2/SDL.h>

#include "Film.hpp"

Film::Film(int _w, int _h):
  m_filmWidth(_w),
  m_filmHeight(_h),
  m_pixelArr(_w * _h)
{
  std::cout << "film created: " << _w << ", " << _h << std::endl;
}

void Film::setPixle(int _x, int _y, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a)
{
  SDL_Color temp{_r, _g, _b, _a};
  m_pixelArr[_x + m_filmWidth * _y] = temp;
}

void Film::getPixel(int _x, int _y)
{
  Uint8 r = m_pixelArr[_x + m_filmWidth * _y].r;
  Uint8 g = m_pixelArr[_x + m_filmWidth * _y].g;
  Uint8 b = m_pixelArr[_x + m_filmWidth * _y].b;
  Uint8 a = m_pixelArr[_x + m_filmWidth * _y].a;

  std::cout << "colour is " << unsigned(r) << " " << unsigned(g) << " " << unsigned(b) << " " << unsigned(a) << std::endl;
}
