#include <chrono>
#include <iostream>

#include "generic_transformation.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

GenericTransformation::GenericTransformation(void (*transformation_ptr)(glm::mat4 &, double, double)) : transformation_pointer(transformation_ptr) {}

void GenericTransformation::apply(glm::mat4 &transformation_matrix, double delta, double duration)
{
  transformation_pointer(transformation_matrix, delta, duration);
}