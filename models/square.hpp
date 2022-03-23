#include "../engine/entity.hpp"
#include "GL/gl.h"

class Square : public Entity
{
public:
  Square();
  void update();
  void render();
};