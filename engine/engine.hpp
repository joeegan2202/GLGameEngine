#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

GLuint loadVertexShader(std::string filename);
GLuint loadFragmentShader(std::string filename);

void testDraw(unsigned int vao, unsigned int arrays_size, unsigned int shaderProgram, GLenum mode);
unsigned int genVAO(unsigned int *shaderProgram, const GLfloat *vertex_buffer_data, u_int vertex_buffer_size, std::string vertex_shader_filename, std::string fragment_shader_filename);