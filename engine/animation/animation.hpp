#ifndef __ANIMATION_H__
#define __ANIMATION_H__
#include <chrono>
#include <memory>
#include <vector>

#include "transformation.hpp"
#include <glm/glm.hpp>

class Animation
{
public:
  Animation(double duration, bool repeats);
  std::vector<std::shared_ptr<Transformation>>::iterator add_transformation(std::shared_ptr<Transformation>);
  void remove_transformation(std::vector<std::shared_ptr<Transformation>>::iterator index);
  void start();
  void stop();
  void reset();
  glm::mat4 apply_transformations(glm::mat4);

private:
  bool repeats;
  double duration;
  double elapsed;
  std::chrono::high_resolution_clock::time_point last_time;

  std::vector<std::shared_ptr<Transformation>> transformations;
};
#endif