#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <memory>

#include "Camera.hpp"
#include "TriangleMesh.hpp"

class Renderer
{
public:
  Renderer(Camera *_cam, std::shared_ptr<TriangleMesh> _mesh);
  void renderImage();
private:
  Camera *m_cam;
  std::shared_ptr<TriangleMesh> m_mesh;
};

#endif//__RENDERER_HPP__