#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <ngl/Vec3.h>
#include <ngl/Vec4.h>
#include <ngl/Mat4.h>

#include "Ray.hpp"
#include "Film.hpp"

class Camera
{
public:
  Camera(ngl::Vec3 _pos,
         ngl::Vec3 _aim,
         ngl::Vec3 _up,
         float _focalLength,
         Film *_film);
  void generateRay(int _x, int _y, Ray *_ray);
  ngl::Mat4 m_camToWorld;
private:
  float m_focalLength;
  Film *m_film;


};

#endif//__CAMERA_HPP__
