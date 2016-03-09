#ifndef __ISECTDATA_HPP__
#define __ISECTDATA_HPP__

#include <ngl/Vec3.h>

class IsectData
{
public:
  IsectData();
  float m_t;
  ngl::Vec3 m_pos;
};

#endif//__ISECTDATA_HPP__