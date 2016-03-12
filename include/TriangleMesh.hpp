#ifndef __TRIANGLE_MESH_HPP__
#define __TRIANGLE_MESH_HPP__

#include <iostream>
#include <vector>

#include "Triangle.hpp"
#include "Ray.hpp"
#include "BBox.hpp"

/// @file TriangleMesh.hpp
/// @brief File contaiing the TriangleMesh class
/// @author Quentin Corker-Marin
/// @version 1.0
/// @date 12/03/2016
/// @class TriangleMesh
/// @brief The TriangleMesh class holds all of the triangles that make up
/// a mesh. It also contains a bounding box that is checked for intersection
/// before the triangles are, if the bounding box is not intersected, then
/// the triangles are not checked

class TriangleMesh
{
public:
  /// @brief cto for the TriangleMesh class using the default ctor
  TriangleMesh() = default;

  /// @brief checks to see if the given ray intersects the mesh, if it
  /// intersects the bounding box, then the function checks for intersection
  /// with each triangle in the mesh.
  /// @param [in] &_ray is the ray being cheked for intersections
  /// @param [in] *_intersection is a data structure that will store all of the information about the intersection point.
  /// @param [out] a boolean to indicate wether or not the ray intersecte the mesh
  bool intersect(const Ray &_ray, IsectData *_intersection);

  /// @brief adds a triangle to the mesh. It is used to build the mesh and maintain
  /// the bounding box as it is built up
  /// @param [in] _tri is the triangle being added to the mesh
  void addTri(const Triangle _tri);

  /// @brief a function for printing out the contentse of the mesh, can
  /// probably be removed as it was used for debuging while writing the class
  void printData();

  /// @brief a vector to hold the triangles that make up the mesh
  /// will be made private once the addTri() is written and Meshes are updated
  std::vector<Triangle> m_tris;

  /// @brief a bounding box that contains the mesh
  /// will be made private once the addTri() is written and Meshes are updated
  BBox m_meshBound;

private:
  /// @brief a method that checks to see if the ray intersects the bbox. currently always returns true
  /// @param [in] &_ray is the ray to be checked for intersection with the bbox
  /// @param [out] a bool to indicate if the bbox is intersected by the ray or not
  bool intersectBBox(const Ray&_ray);

  /// @brief amethod that checks to see if the ray intersects the triangles in the mesh
  /// @param [in] &_ray is the ray to be checked for intersection with the triangles
  /// @param [in] *_intersection is a container to be filled up with information about the point of intersection
  /// @param [out] a bool to indicate if the triangles are intersected by the ray
  bool intersectMesh(const Ray&_ray, IsectData *_intersection);
};

#endif //__TRIANGLE_MESH_HPP__
