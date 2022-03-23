#include "engine.hpp"
#include <fstream>
#include <string>

GLFWwindow *window;

GLuint loadVertexShader(std::string filename)
{
  std::ifstream shaderFile;
  shaderFile.open(filename);

  std::string shaderSource = "";
  std::string line;

  while (getline(shaderFile, line))
  {
    shaderSource.append(line + "\n");
  }

  const char *shaderCString = shaderSource.c_str();

  GLuint vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &shaderCString, NULL);
  glCompileShader(vertexShader);

  // check for shader compile errors
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  shaderFile.close();

  return vertexShader;
}

GLuint loadFragmentShader(std::string filename)
{
  std::ifstream shaderFile;
  shaderFile.open(filename);

  std::string shaderSource = "";
  std::string line;

  while (getline(shaderFile, line))
  {
    shaderSource.append(line + "\n");
  }

  const char *shaderCString = shaderSource.c_str();

  GLuint fragmentShader;

  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &shaderCString, NULL);
  glCompileShader(fragmentShader);

  // check for shader compile errors
  int success;
  char infoLog[512];
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  shaderFile.close();

  return fragmentShader;
}

GLuint genVAO(GLuint *shaderProgram, const GLfloat *vertex_buffer_data, u_int vertex_buffer_size, std::string vertex_shader_filename, std::string fragment_shader_filename)
{
  // Initialize objects
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  GLuint vertexbuffer;
  glGenBuffers(1, &vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, vertex_buffer_size, vertex_buffer_data, GL_STATIC_DRAW);

  GLuint vertShader = loadVertexShader(vertex_shader_filename);
  GLuint fragShader = loadFragmentShader(fragment_shader_filename);

  *shaderProgram = glCreateProgram();

  glAttachShader(*shaderProgram, vertShader);
  glAttachShader(*shaderProgram, fragShader);
  glLinkProgram(*shaderProgram);

  glDeleteShader(vertShader);
  glDeleteShader(fragShader);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(0);

  return vao;
}

void testDraw(GLuint vao, GLuint arrays_size, GLuint shader_program, GLenum mode)
{
  glUseProgram(shader_program);

  glBindVertexArray(vao);

  glDrawArrays(mode, 0, arrays_size);
}