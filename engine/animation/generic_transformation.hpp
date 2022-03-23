#include "transformation.hpp"

class GenericTransformation : public Transformation
{
public:
  GenericTransformation(void (*transformation_ptr)(glm::mat4 &, double, double));
  void apply(glm::mat4 &transformation_matrix, double delta, double duration);

private:
  void (*transformation_pointer)(glm::mat4 &, double, double);
};