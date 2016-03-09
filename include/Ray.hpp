#ifndef __RAY_HPP__
#define __RAY_HPP__

#include <ngl/Vec3.h>

class Ray
{
public:
  Ray() = default;
  Ray(ngl::Vec3 _origin, ngl::Vec3 _direction);
  ngl::Vec3 m_origin;
  ngl::Vec3 m_direction;
};

#endif //__RAY_HPP__
