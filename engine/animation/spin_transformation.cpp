#include <chrono>
#include <iostream>

#include "spin_transformation.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

SpinTransformation::SpinTransformation()
{
}

void SpinTransformation::apply(glm::mat4 &transformation_matrix, double delta, double duration)
{
  transformation_matrix = glm::rotate(transformation_matrix, static_cast<float>(delta / duration * glm::radians(360.0f)), glm::vec3(0.0f, 0.0f, 1.0f));
}