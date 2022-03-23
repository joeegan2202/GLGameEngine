#include "transformation.hpp"

class SpinTransformation : public Transformation
{
public:
  SpinTransformation();
  void apply(glm::mat4 &transformation_matrix, double delta, double duration);

private:
};