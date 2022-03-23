#include "square.hpp"
#include "../engine/engine.hpp"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/gl.h>

Square::Square()
{
  arrays_size = 6;
  GLfloat *g_vertex_buffer_data{new GLfloat[arrays_size * 3]{
      -0.5f, -0.5f, 0.0f,
      0.5f, -0.5f, 0.0f,
      0.5f, 0.2f, 0.0f,
      0.5f, 0.2f, 0.0f,
      -0.5f, 0.2f, 0.0f,
      -0.5f, -0.5f, 0.0f}};

  vao = genVAO(&shaderProgram, g_vertex_buffer_data, arrays_size * 3 * sizeof(*g_vertex_buffer_data), "assets/testvert.txt", "assets/testfrag.txt");
}

void Square::update()
{
}

void Square::render()
{
  glm::mat4 transformation_matrix(1.0f);

  for (auto animation = animations.begin(); animation != animations.end(); animation++)
  {
    transformation_matrix = (*animation).apply_transformations(transformation_matrix);
  }

  glUniformMatrix4fv(get_transformation_matrix(), 1, GL_FALSE, glm::value_ptr(transformation_matrix));

  testDraw(vao, arrays_size, shaderProgram, GL_TRIANGLES);
}