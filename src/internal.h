#pragma once
#include <GLFW/glfw3.h>

typedef void (*CursorCallbackFn)(GLFWwindow *, double, double); // 定义函数类型
typedef void (*KeyCallbackFn)(GLFWwindow *, int, int, int, int);

struct GLFWCallback {
  CursorCallbackFn _cursor_callback;
  KeyCallbackFn _key_callback;
};

extern struct GLFWCallback _glfw_callback; // 定义一个全局变量

#ifdef OPENGL_DEBUG
#define DEBUG_ASSERT(x, ...)                                                   \
  if (!(x)) {                                                                  \
    std::cerr << __VA_ARGS__;                                                  \
  }
#endif
