#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <vector>

#include "animation/animation.hpp"
#include "GL/glew.h"

class Entity
{
public:
  virtual void update() = 0;
  virtual void render() = 0;
  virtual void apply_animation(Animation animation)
  {
    animation.start();
    animations.push_back(animation);
  };
  virtual GLint get_transformation_matrix()
  {
    return glGetUniformLocation(shaderProgram, "trans");
  };

protected:
  unsigned int vao;
  unsigned int shaderProgram;
  unsigned int arrays_size;
  std::vector<Animation> animations;
};
#endif