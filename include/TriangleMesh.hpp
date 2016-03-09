#ifndef __TRIANGLE_MESH_HPP__
#define __TRIANGLE_MESH_HPP__

#include <iostream>
#include <vector>

#include "Triangle.hpp"
#include "Ray.hpp"
#include "BBox.hpp"

class TriangleMesh
{
public:
  TriangleMesh() = default;
  bool intersect(const Ray &_ray, IsectData *_intersection);
  void addTri(const Triangle _tri);
  void printData();

  std::vector<Triangle> m_tris;
  BBox m_meshBound;

private:
  bool intersectBBox(const Ray&_ray);
  bool intersectMesh(const Ray&_ray, IsectData *_intersection);
};

#endif //__TRIANGLE_MESH_HPP__
