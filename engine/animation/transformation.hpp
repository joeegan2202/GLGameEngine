#ifndef __TRANSFORMATION_H__
#define __TRANSFORMATION_H__

#include "glm/glm.hpp"

class Transformation
{
public:
  virtual void apply(glm::mat4 &transformation_matrix, double delta, double duration) = 0;
};

#endif