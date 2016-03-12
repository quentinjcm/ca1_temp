#include <ngl/Vec3.h>

#include "Ray.hpp"

///@file Ray.cpp
///@brief Implementation file for the Ray class

Ray::Ray(ngl::Vec3 _origin, ngl::Vec3 _direction):
  m_origin(_origin),
  m_direction(_direction)
{
  m_direction.normalize();
}
