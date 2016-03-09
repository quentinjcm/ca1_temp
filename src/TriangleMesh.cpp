#include <iostream>
#include <vector>

#include <ngl/Vec3.h>

#include "TriangleMesh.hpp"
#include "Triangle.hpp"
#include "Ray.hpp"
#include "BBox.hpp"

bool TriangleMesh::intersect(const Ray &_ray, IsectData *_intersection)
{
  std::cout << "Calculating mesh intetrsection" << std::endl;
  if (intersectBBox(_ray)){
    return intersectMesh(_ray, _intersection);
  }
  else return false;
}

bool TriangleMesh::intersectBBox(const Ray &_ray)
{
  std::cout << "Intersecting bbox" << std::endl;
  return true;
}

bool TriangleMesh::intersectMesh(const Ray &_ray, IsectData *_intersection)
{
  std::cout << "Intersecting mesh" << std::endl;
  bool hasIntersected = false;
  for (Triangle i: m_tris){
    if (i.intersect(_ray, _intersection)){
      hasIntersected = true;
    }
  }
  return hasIntersected;
}

void TriangleMesh::addTri(const Triangle _tri)
{
  m_meshBound.addPoint(_tri.m_v1);
  m_meshBound.addPoint(_tri.m_v2);
  m_meshBound.addPoint(_tri.m_v3);
}

void TriangleMesh::printData()
{
  for(Triangle i: m_tris) i.printData();
}
