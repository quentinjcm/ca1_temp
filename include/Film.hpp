#ifndef __FILM_HPP__
#define __FILM_HPP__

#include <vector>

#include <SDL2/SDL.h>

class Film
{
public:
  Film(int _w, int _h);
  void setPixle(int _x, int _y, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a);
  void getPixel(int _x, int _y);

  int m_filmWidth;
  int m_filmHeight;

private:
  std::vector<SDL_Color> m_pixelArr;
};





#endif//__FILM_HPP__
