#include <iostream>

#include <ngl/Mat4.h>
#include <ngl/Vec3.h>
#include <ngl/Util.h>
#include <ngl/NGLStream.h>

#include "Camera.hpp"
#include "Film.hpp"
#include "Ray.hpp"

Camera::Camera(ngl::Vec3 _pos,
               ngl::Vec3 _lookAt,
               ngl::Vec3 _up,
               float _focalLength,
               Film *_film):
  m_film(_film),
  m_focalLength(_focalLength)
{
  //generating a transformation matrix to transform from
  //camera space to world space
  //generate an orthonormal frame:
  ngl::Vec3 d = _lookAt - _pos;
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

  m_rotate = rotate;

  m_camToWorld = translate * rotate ;

}

void Camera::generateRay(int _x, int _y, Ray *_ray)
{
  ngl::Vec4 origin(0, 0, 0, 1);

  float aspectRatio = m_film->m_filmWidth / m_film->m_filmHeight;//move to film

  float xNDC = ((float)_x + 0.5)/m_film->m_filmWidth;
  float yNDC = ((float)_y + 0.5)/m_film->m_filmHeight;

  float xScreen = ((xNDC * 2) - 1) * aspectRatio;
  float yScreen = 1 - (yNDC * 2);

  ngl::Vec4 direction(xScreen,
                      yScreen,
                      1,
                      1);


  origin = m_camToWorld * origin;
  direction = m_rotate * direction;

  direction.normalize();

  ngl::Vec3 originOut;
  ngl::Vec3 directionOut;

  originOut.set(origin);
  directionOut.set(direction);

  _ray->m_direction = directionOut;
  _ray->m_origin = originOut;
}
