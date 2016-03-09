#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include <ngl/Vec3.h>
#include <ngl/Util.h>

#include "Ray.hpp"
#include "IsectData.hpp"

class Triangle
{
public:
  Triangle(ngl::Vec3 _v1, ngl::Vec3 _v2, ngl::Vec3 _v3,
           ngl::Vec3 _n1, ngl::Vec3 _n2, ngl::Vec3 _n3);
  bool intersect(const Ray &_ray, IsectData *_intersection);
  void printData();

  const ngl::Vec3 m_v1;
  const ngl::Vec3 m_v2;
  const ngl::Vec3 m_v3;
  const ngl::Vec3 m_n1;
  const ngl::Vec3 m_n2;
  const ngl::Vec3 m_n3;

  private:
  ngl::Vec3 m_n;
  float m_d;
  int m_i1;
  int m_i2;

  void calcN();
  void calcD();
  void calcDominantAxis();
};


#endif //__TRIANGLE_HPP__
