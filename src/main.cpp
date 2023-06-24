#include<iostream>
#include<GLFW/glfw3.h>
#include<glad/glad.h>
#include"internal.h"
#include"window.h"

int main(){
    WindowProps props{"OpenGL", 800, 600, true};
    Window* window = InitWindow(props);

    while(!window->IsStop()){

        // 渲染之旅
        window->Update();
    }
    
    delete window;

    return 0;
}

