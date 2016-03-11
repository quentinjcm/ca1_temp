#include <iostream>
#include <cmath>

#include <ngl/Vec3.h>
#include <ngl/NGLStream.h>

#include "Triangle.hpp"
#include "Ray.hpp"

Triangle::Triangle(ngl::Vec3 _v0, ngl::Vec3 _v1, ngl::Vec3 _v2,
                   ngl::Vec3 _n0, ngl::Vec3 _n1, ngl::Vec3 _n2):
  m_v0(_v0), m_v1(_v1), m_v2(_v2),
  m_n0(_n0), m_n1(_n1), m_n2(_n2)
{
  calcN();
  calcD();
  calcDominantAxis();
}

Triangle::Triangle(ngl::Vec3 _v2, ngl::Vec3 _v1, ngl::Vec3 _v0):
  m_v0(_v0), m_v1(_v1), m_v2(_v2),
  m_n0(0, 0, 0), m_n1(0, 0, 0), m_n2(0, 0, 0)
{
  calcN();
  calcD();
  calcDominantAxis();
}

bool Triangle::intersect(const Ray &_ray, IsectData *_intersection)
{
  /*
   * The intersection algorithm used here can be found at
   * http://graphics.stanford.edu/courses/cs348b-98/gg/intersect.html
   * accessed on 08/03/2016
   * Fistsly the intersection of the plane made form the 3 verticies
   * and the ray is found. Then this point is checked to see if is is
   * inside the triangle. This is done by projecting the triangle along
   * the major axis of the normal, reducing the problem to 2 dimensions.
   * Then the vector m_v0->p is written prametrically in terms of the
   * vectors alpha(m_v0->m_v1) and beta(m_v0->m_v2). If alpha > 0 and
   * beta > 0 and (alpha + beta < 1) then the point of intersection is
   * inside the triangle.
   */

  //std::cout << m_n << ", " << m_d << std::endl;
  //std::cout << "isect value: " << (_intersection->m_t) << std::endl;

  //first the ray is checked to se if it is parrallel to the plane
  float denominator = m_n.dot(_ray.m_direction);
  //if not parrallel, then check for intersection with plane
  if (denominator){
    float numerator = m_d + m_n.dot(_ray.m_origin);
    //t strores the parameter for the distance along the ray of the intersection: r(t) = O + Dt
    float t = -numerator/denominator;
    //if intersection point is behind the rays origin, the ray is rejected
    if (t <= 0){
      //std::cout << "T less than 0" << std::endl;
      return false;
    }
    //if a cloaser intersection has already been found, the ray is rejected
    if (t > _intersection->m_t){
      //std::cout << "intersection further away than closest intersection" << std::endl;
      return false;
    }
    //std::cout << "isect value 2: " << t << std::endl;
    //now the intersection point is calculated
    ngl::Vec3 p = _ray.m_origin + _ray.m_direction * t;
    //checking to see if the point is inside the triangle by
    //projecting the triangle along the major axis of the normal
    //[u0, v0] = vector from m_v0 to intersection point
    //std::cout << "axes: " << m_i1 << ", " << m_i2 << std::endl;
    //std::cout << "p: " << p << std::endl;
    float u0 = p[m_i1] - m_v0[m_i1];
    float v0 = p[m_i2] - m_v0[m_i2];
    //[u1, v1] = vector from m_v0 to m_v1
    float u1 = m_v1[m_i1] - m_v0[m_i1];
    float v1 = m_v1[m_i2] - m_v0[m_i2];
    //[u2, v2] = vector from m_v0 to m_v2
    float u2 = m_v2[m_i1] - m_v0[m_i1];
    float v2 = m_v2[m_i2] - m_v0[m_i2];

    //std::cout << "1->p: " << u0 << ", " << v0 << std::endl;
    //std::cout << "1->2: " << u1 << ", " << v1 << std::endl;
    //std::cout << "1->3: " << u2 << ", " << v2 << std::endl;

    float alpha = -1;
    float beta = -1;



    if (u1 == 0){
      beta = u0/u2;
      if (beta >= 0 & beta <= 1){
        alpha = (v0 - beta * v2)/v1;
      }
    }
    else{
      beta = (v0*u1 - u0*v1) / (v2*u1 - u2*v1);
      if (beta >= 0 and beta <= 1){
        alpha = (u0 - beta*u2) / u1;
      }
    }



    //std::cout << alpha << ", " << beta << std::endl;
    if (alpha >= 0 & beta >= 0 and (alpha + beta) <=1){
      _intersection->m_t = t;
      _intersection->m_pos = p;
      _intersection->m_n = m_n;
      //std::cout << "HIT: " << alpha << ", " << beta << std::endl;
      return true;
    }
    else{
      //std::cout << "intersection outside triangle" << std::endl;
      return false;
    }
  }
  else{
    //std::cout << "ray is parrallel to triangle" << std::endl;
    return false;
  }
}

void Triangle::printData()
{
  std::cout << "Printing triangle data:\n";
  std::cout << "points:\n";
  std::cout << m_v0 << "\n" << m_v1 << "\n" << m_v2 << std::endl;

  std::cout << "normals:\n";
  std::cout << m_n0 << "\n" << m_n1 << "\n" << m_n2 << std::endl;

  std::cout << "n: " << m_n << std::endl;

  std::cout << "d: " << m_d << std::endl;
 }

void Triangle::calcN()
{
  m_n = ngl::calcNormal(m_v0, m_v1, m_v2);
  m_n.normalize();
}

void Triangle::calcD()
{
  m_d = (m_n.dot(m_v0)) * -1;
}

void Triangle::calcDominantAxis()
{
  float x = fabs(m_n.m_x);
  float y = fabs(m_n.m_y);
  float z = fabs(m_n.m_z);
  if (x > y & x > z){
    //x is the dominant axis
    m_i1 = 1;
    m_i2 = 2;
  }
  else if (y > x & y > z){
    //y is the dominant axis
    m_i1 = 2;
    m_i2 = 0;
  }
  else{
    //z is the dominant axis
    m_i1 = 0;
    m_i2 = 1;
  }
}
