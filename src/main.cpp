#include "internal.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

static const int Width = 800;
static const int Height = 600;
static const char *Title = "OpenGL";

extern void Init();

int main() {
    // 1. 初始化
    // 2. 创建窗口
    // 3. 创建上下文
    //

    Init();
    int success = glfwInit();
    DEBUG_ASSERT(success, "GLFW Init Failed!");

    GLFWwindow *window =
        glfwCreateWindow(Width, Height, Title, nullptr, nullptr);
    DEBUG_ASSERT(window, "Create Window Failed.");

    glfwMakeContextCurrent(window);
    bool glad_ret = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    DEBUG_ASSERT(glad_ret, "Glad Load Failed.");

    glfwSetScrollCallback(window, _glfw_callback._cursor_callback);
    glfwSetKeyCallback(window, _glfw_callback._key_callback);

    // OpenGL
    unsigned int VAO, VBO, VEO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(GL_VERTEX_ARRAY);

    float vertices[] = {-0.5f, -0.5f, 1.0f, 0.5f, -0.5f,
                        1.0f,  0.0f,  0.5f, 0.0f};
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int indexes[] = {0, 1, 2};

    glGenBuffers(1, &VEO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VEO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes,
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
