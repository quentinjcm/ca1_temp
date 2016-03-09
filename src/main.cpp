#include <iostream>
#include <memory>
#include <vector>

#include <ngl/Vec3.h>
#include <ngl/Vec4.h>
#include <ngl/NGLStream.h>


#include "TriangleMesh.hpp"
#include "Triangle.hpp"
#include "IsectData.hpp"
#include "Film.hpp"
#include "Camera.hpp"

int main()
{
  ngl::Vec3 pos(1, 0, 1);
  ngl::Vec3 aim(1, 0, 1);
  ngl::Vec3  up(0, 1, 0);

  Film film(3, 3);

  Camera cam(pos, aim, up, 1, &film);

  Ray newRay;
  cam.generateRay(0, 0, &newRay);

  std::cout << newRay.m_origin << newRay.m_direction <<std::endl;







  /*
  Film myFilm(1080, 720);
  myFilm.setPixle(1, 1, 20, 20, 20, 1);
  myFilm.getPixel(1, 1);
  */
  /*
  //tri 1
  ngl::Vec3 v1(1, 1, 1);
  ngl::Vec3 v2(0, 1, 0);
  ngl::Vec3 v3(1, 1, 0);

  //tri 2
  ngl::Vec3 v4(1, 2, 1);
  ngl::Vec3 v5(0, 2, 0);
  ngl::Vec3 v6(1, 2, 0);


  ngl::Vec3 o(0, 0, 0);
  ngl::Vec3 d(0, 1, 0);

  Ray ray(o, d);

  Triangle tri1 = Triangle(v1, v2, v3, v1, v2, v3);
  Triangle tri2 = Triangle(v4, v5, v6, v4, v5, v6);

  IsectData intersection;




  TriangleMesh mesh;
  mesh.m_tris.push_back(tri1);
  mesh.m_tris.push_back(tri2);

  if (mesh.intersect(ray, &intersection)){
    std::cout << "intersection found at " << intersection.m_pos << " " << intersection.m_t << std::endl;
  }
*/

  return EXIT_SUCCESS;
}
