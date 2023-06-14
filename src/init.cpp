
#include "internal.h"
#include <iostream>

struct GLFWCallback _glfw_callback;

void CursorCallback(GLFWwindow *window, double x, double y) {
#ifdef OPENGL_DEBUG
  std::cout << "Cursor Pos: [" << x << ", " << y << "]"<<std::endl;
#endif
}

void KeyCallback(GLFWwindow *window, int keycode, int scancode, int action,
                 int mod) {
#ifdef OPENGL_DEBUG
  if (action == GLFW_PRESS)
    std::cout << "key pressed : " << keycode << std::endl;
#endif
}

void Init() {
  _glfw_callback._cursor_callback = CursorCallback;
  _glfw_callback._key_callback = KeyCallback;
}
