#include <iostream>

#include <ngl/Vec3.h>
#include <ngl/NGLStream.h>

#include "BBox.hpp"

BBox::BBox()
{
  ngl::Vec3 temp(0.0, 0.0, 0.0);
  m_pMin = temp;
  m_pMax = temp;
  printData();
}

BBox::BBox(const ngl::Vec3 &_p):
  m_pMin(_p),
  m_pMax(_p)
{
  printData();
}

BBox::BBox(const ngl::Vec3 &_p1, ngl::Vec3 &_p2):
  m_pMin(_p1),
  m_pMax(_p1)
{
  addPoint(_p2);
}

void BBox::addPoint( const ngl::Vec3 &_p)
{
  for (int i: {0, 1, 2})
  if (_p[i] < m_pMin[i]){
    m_pMin[i] = _p[i];
  }
  else if (_p.m_x >  m_pMax.m_x){
    m_pMax[i] = _p[i];
  }
}

void BBox::printData()
{
  std::cout << "Printing BBox\n";
  std::cout << "min: "<< m_pMin << "\nmax: " << m_pMax << std::endl;
}
