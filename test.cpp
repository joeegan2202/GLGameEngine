#include <iostream>
#include <iomanip>
#include <chrono>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "models/square.hpp"
#include "setup/setup.hpp"
#include "engine/engine.hpp"
#include "engine/scene/scene.hpp"
#include "engine/animation/animation.hpp"
#include "engine/animation/spin_transformation.hpp"
#include "engine/animation/generic_transformation.hpp"

extern GLFWwindow *window;

const int FPS = 60;
const double TIME_PER_FRAME = 1000.0 / FPS;

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

int main()
{
  if (!initializeGL())
  {
    return 1;
  }

  glfwSetKeyCallback(window, key_callback);

  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);

  std::shared_ptr<Entity> test_square(new Square());
  std::shared_ptr<Entity> duplicate_square(new Square());

  std::shared_ptr<Transformation> spin_trans(new SpinTransformation());
  Animation test_animation(4000, true);
  test_animation.add_transformation(spin_trans);
  test_square->apply_animation(test_animation);

  std::shared_ptr<Transformation> rotate_trans(new GenericTransformation(
      [](glm::mat4 &transformation_matrix, double delta, double duration)
      {
        transformation_matrix = glm::translate(
            transformation_matrix,
            glm::vec3(glm::cos(delta * glm::radians(360.0f) / duration), glm::sin(delta * glm::radians(360.0f) / duration), 0.0f));
      }));
  test_animation.add_transformation(rotate_trans);
  duplicate_square->apply_animation(test_animation);

  std::shared_ptr<Scene> test_scene(new Scene{test_square, duplicate_square});

  std::chrono::high_resolution_clock::time_point lastTime = std::chrono::high_resolution_clock::now();
  std::chrono::high_resolution_clock::time_point firstTime = lastTime;
  double delta = 0.0;
  while (!glfwWindowShouldClose(window))
  {
    if (delta >= TIME_PER_FRAME)
    {
      lastTime = std::chrono::high_resolution_clock::now();

      if (delta > 17)
        std::cout << "Delta time: " << std::setprecision(4) << delta << std::endl;

      glClear(GL_COLOR_BUFFER_BIT);

      test_scene->update();
      test_scene->render();

      glfwSwapBuffers(window);

      glfwPollEvents();
    }

    delta = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - lastTime).count() / 1000.0;
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}
