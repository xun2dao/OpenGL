#include <GLFW/glfw3.h>
#include <iostream>
#include <new>

#define DEBUG_ASSERT(x, ...)                                                   \
  if (!(x)) {                                                                  \
    std::cerr << __VA_ARGS__;                                                  \
  }

static const int Width = 800;
static const int Height = 600;
static const char *Title = "OpenGL";

int main() {
  // 1. 初始化
  // 2. 创建窗口
  // 3. 创建上下文
  //
  int success = glfwInit();
  DEBUG_ASSERT(success, "GLFW Init Failed!");

  GLFWwindow *window = glfwCreateWindow(Width, Height, Title, nullptr, nullptr);
  DEBUG_ASSERT(window, "Create Window Failed.");

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  return 0;
}
