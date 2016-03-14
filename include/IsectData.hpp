#ifndef __ISECTDATA_HPP__
#define __ISECTDATA_HPP__

#include <memory>

#include <ngl/Vec3.h>

#include "Material.hpp"

class IsectData
{
public:
  IsectData();
  float m_t;
  ngl::Vec3 m_pos;
  ngl::Vec3 m_n;
  std::shared_ptr<Material> m_material;

};

#endif//__ISECTDATA_HPP__
