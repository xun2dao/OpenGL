#pragma once

#include"../window.h"
#include<GLFW/glfw3.h>


class GlfwWindow : public Window{
public:
    GlfwWindow(WindowProps& props);
    virtual int GetWidth() const override;
    virtual int GetHeight() const override;
    virtual void Update() const override;
    virtual bool IsSync() const override;
    virtual void SetSync(bool flag) override;
    virtual void* GetNativeWindow() const override;
    virtual std::string GetTitle() const override;
    virtual void SetTitle(std::string) override;
    virtual bool IsStop() const override;
    virtual ~GlfwWindow(){
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }
private:
    GLFWwindow* m_Window;
};


