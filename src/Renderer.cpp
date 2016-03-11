#include <iostream>

#include "Renderer.hpp"
#include "Camera.hpp"
#include "Film.hpp"
#include "IsectData.hpp"

Renderer::Renderer(Camera *_cam, std::shared_ptr<TriangleMesh> _mesh):
  m_cam(_cam),
  m_mesh(_mesh)
{
  std::cout << "Renderer cresated" << std::endl;
}


void Renderer::renderImage()
{
  for (int x = 0; x < m_cam->m_film->m_filmWidth; x++){
    for (int y = 0; y < m_cam->m_film->m_filmHeight; y++){
      //generate ray
      //std::cout << " rendering pixel " << x << ", " << y << std::endl;
      Ray newRay;
      IsectData intersection;
      m_cam->generateRay(x, y, &newRay);

      //intersect ray with scene
      if (m_mesh->intersect(newRay, &intersection)){
        m_cam->m_film->setPixle(x, y, intersection.m_n[0]*254,
                                intersection.m_n[1]*254,
                                intersection.m_n[2]*254, 255);
      }
      else{
        m_cam->m_film->setPixle(x, y, 255, 255, 255, 255);
      }
    }
  }
}
