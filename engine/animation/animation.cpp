#include <chrono>
#include <cmath>

#include "animation.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Animation::Animation(double duration, bool repeats) : duration(duration), repeats(repeats) {}

std::vector<std::shared_ptr<Transformation>>::iterator Animation::add_transformation(std::shared_ptr<Transformation> transformation)
{
  transformations.push_back(transformation);
  return transformations.end();
}

void Animation::remove_transformation(std::vector<std::shared_ptr<Transformation>>::iterator index)
{
  transformations.erase(index);
}

void Animation::start()
{
  last_time = std::chrono::high_resolution_clock::now();
}

void Animation::stop()
{
  elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - last_time).count();
}

void Animation::reset()
{
  elapsed = 0;
  last_time = std::chrono::high_resolution_clock::now();
}

glm::mat4 Animation::apply_transformations(glm::mat4 transformation_matrix)
{
  double delta = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - last_time).count() + elapsed;

  if (delta > duration && !repeats)
  {
    // If the animation does not repeat, it returns the original matrix
    return transformation_matrix;
  }
  else
  {
    // Essentially a % operator on the double types
    // meant to automatically 'loop' the animation
    // so the transformation doesn't have to deal with it.
    delta -= floor(delta / duration) * duration;
  }

  for (auto transformation = transformations.begin(); transformation != transformations.end(); transformation++)
  {
    (*transformation)->apply(transformation_matrix, delta, duration);
  }

  return transformation_matrix;
}