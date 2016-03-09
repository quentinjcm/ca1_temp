#include <iostream>

#include <ngl/Mat4.h>
#include <ngl/Vec3.h>
#include <ngl/NGLStream.h>

#include "Camera.hpp"
#include "Film.hpp"
#include "Ray.hpp"

Camera::Camera(ngl::Vec3 _pos,
               ngl::Vec3 _aim,
               ngl::Vec3 _up,
               float _focalLength,
               Film *_film):
  m_focalLength(_focalLength),
  m_film(_film)
{
  //generating a transformation matrix to transform from
  //camera space to world space
  //generate an orthonormal frame:
  ngl::Vec3 d = _aim;
  ngl::Vec3 r = _up.cross(d);
  ngl::Vec3 u = d.cross(r);
  d.normalize();
  r.normalize();
  u.normalize();
  //generate a matrix that can transform from points in the
  //cameras frame to points in world space

  //matrix to allign roataions
  ngl::Mat4 rotate(r[0], u[0], d[0], 0,
                   r[1], u[1], d[1], 0,
                   r[2], u[2], d[2], 0, //-d[2] to do with handedness of the coordinate system
                   0,    0,    0,    1);
  //rotate.transpose();

  //matrix for position transformations
  ngl::Mat4 translate(1, 0, 0, _pos[0],
                      0, 1, 0, _pos[1],
                      0, 0, 1, _pos[2],
                      0, 0, 0,  1);

  //combining transformation and roataion
  m_camToWorld = translate * rotate ;

}

void Camera::generateRay(int _x, int _y, Ray *_ray)
{
  ngl::Vec4 origin(0, 0, 0, 1);
  ngl::Vec4 direction(_x - m_film->m_filmWidth/2,
                      _y- m_film->m_filmHeight/2,
                      m_focalLength);


  origin = m_camToWorld * origin;
  direction = m_camToWorld * direction;
  direction.normalize();

  ngl::Vec3 originOut;
  ngl::Vec3 directionOut;

  originOut.set(origin);
  directionOut.set(direction);

  _ray->m_direction = directionOut;
  _ray->m_origin = originOut;
}
