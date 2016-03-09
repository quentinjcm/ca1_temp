#include <ngl/Vec3.h>
#include <ngl/NGLStream.h>
#include "Ray.hpp"

Ray::Ray(ngl::Vec3 _origin, ngl::Vec3 _direction):
  m_origin(_origin),
  m_direction(_direction)
{
  m_direction.normalize();
  std::cout << "ray created at " << m_origin << " with direction " << m_direction << std::endl;
}
