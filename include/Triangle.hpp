#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include <ngl/Vec3.h>
#include <ngl/Util.h>

#include "Ray.hpp"
#include "IsectData.hpp"

//----------------------------------------------------------------------------------------------------------------------
/// @file Triangle.hpp
/// @brief The Triangle class represents triangles contained in a TriangleMesh
/// @author Quentin Corker-Marin
/// @version 1.0
/// @date 11/03/2016
/// @class Triangle
/// @brief a class to represent triangles andimplment ray/triangle intersections.
//----------------------------------------------------------------------------------------------------------------------

class Triangle
{
public:
  /// @brief ctor for triangle class that takes in positions and normals
  /// @param [in] _v0 first point in the triangle
  /// @param [in] _v1 second point in the triangle
  /// @param [in] _v2 third point in the triangle
  /// @param [in] _n0 normal corresponding to the first point in the triangle
  /// @param [in] _n1 normal corresponding to the second point in the triangle
  /// @param [in] _n2 normal corresponding to the third point in the triangle
  Triangle(ngl::Vec3 _v0, ngl::Vec3 _v1, ngl::Vec3 _v2,
           ngl::Vec3 _n0, ngl::Vec3 _n1, ngl::Vec3 _n2);

  /// @brief a second ctor for triangle class that only needs vertex positions
  /// @param [in] _v0 first point in the triangle
  /// @param [in] _v1 second point in the triangle
  /// @param [in] _v2 third point in the triangle
  Triangle(ngl::Vec3 _v2, ngl::Vec3 _v1, ngl::Vec3 _v0);

  /// @brief the intersect method for the triangle class
  /// @param [in] &_ray the ray that is being tested for intersections with the triangle
  /// @param [in] *_intersection a data structure th store information about the point of intersection if there is one
  /// @param [out] a boolean that indicates wehter the intersection was successfull
  bool intersect(const Ray &_ray, IsectData *_intersection);

  /// @brief a method for printing the information contained within the triangle
  /// can probably be taken out as it was only needed for debuging early on
  void printData();

  const ngl::Vec3 m_v0;
  const ngl::Vec3 m_v1;
  const ngl::Vec3 m_v2;
  const ngl::Vec3 m_n0;
  const ngl::Vec3 m_n1;
  const ngl::Vec3 m_n2;

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
