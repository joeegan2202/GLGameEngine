#include "scene.hpp"

Scene::Scene(std::initializer_list<std::shared_ptr<Entity>> new_entities) : entities(new_entities) {}

void Scene::update()
{
  for (auto entity = entities.begin(); entity != entities.end(); entity++)
  {
    (*entity)->update();
  }
}

void Scene::render()
{
  for (auto entity = entities.begin(); entity != entities.end(); entity++)
  {
    (*entity)->render();
  }
}