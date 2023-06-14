#pragma once
#include <GLFW/glfw3.h>

typedef void (*CursorCallbackFn)(GLFWwindow *, double, double);
typedef void (*KeyCallbackFn)(GLFWwindow *, int, int, int, int);

struct GLFWCallback {
  CursorCallbackFn _cursor_callback;
  KeyCallbackFn _key_callback;
};

extern struct GLFWCallback _glfw_callback;

#ifdef OPENGL_DEBUG
#define DEBUG_ASSERT(x, ...)                                                   \
  if (!(x)) {                                                                  \
    std::cerr << __VA_ARGS__;                                                  \
  }
#endif
