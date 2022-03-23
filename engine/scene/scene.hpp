#ifndef __SCENE_H__
#define __SCENE_H__

#include <memory>
#include <vector>

#include "../entity.hpp"

class Scene
{
public:
  Scene(std::initializer_list<std::shared_ptr<Entity>>);
  virtual void update();
  virtual void render();

protected:
  std::vector<std::shared_ptr<Entity>> entities;
};

#endif