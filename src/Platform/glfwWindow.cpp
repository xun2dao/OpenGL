#include "glfwWindow.h"
#include "../internal.h"
#include "GLFW/glfw3.h"

#ifdef PLATFORM_WINDOW_GLFW
Window *InitWindow(WindowProps &props) {
    return static_cast<Window *>(new GlfwWindow(props));
}
#endif

GlfwWindow::GlfwWindow(WindowProps &props) : Window(props){
    int success = glfwInit();
    DEBUG_ASSERT(success, "glfw init failed.");
    // m_Window = glfwCreateWindow(m_Props.Width, m_Props.Height,
    //                             m_Props.Title.c_str(), nullptr, nullptr);
    m_Window = glfwCreateWindow(m_Props.Width,m_Props.Height, m_Props.Title.c_str(), nullptr, nullptr);
    DEBUG_ASSERT(m_Window, "glfw Can't obtain window.");
    glfwMakeContextCurrent(m_Window);
    // 加载渲染器
}

int GlfwWindow::GetWidth() const {
    return m_Props.Width;
}
int GlfwWindow::GetHeight() const {
    return m_Props.Height;
}
void GlfwWindow::Update() const {
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
}
bool GlfwWindow::IsSync() const {
    return m_Props.VSync;
}
void GlfwWindow::SetSync(bool flag) {
}
void *GlfwWindow::GetNativeWindow() const {
    return m_Window;
}
std::string GlfwWindow::GetTitle() const {
    return m_Props.Title;
}
void GlfwWindow::SetTitle(std::string title) {
    m_Props.Title = title;
}

bool GlfwWindow::IsStop() const {
    return glfwWindowShouldClose(m_Window);
}
