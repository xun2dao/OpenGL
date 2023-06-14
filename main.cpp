#include <iostream>


typedef void (*Callback)(int, void*); // 定义特定函数指针

struct GLFWwindow{
    struct { // 内置匿名结构体和对象
        bool surface;
        int platformId;
        Callback callback;

    }hint;

};
static GLFWwindow _glfw;

void GetPlatform(int platform , void *){
        std::cout<< "GetPlatform"<<std::endl;
}


int main() {
  // 1. 初始化
  // 2. 创建窗口
  // 3. 创建上下文
  std::cout << "Hello,World" << std::endl;

  _glfw.hint.callback = GetPlatform;
  _glfw.hint.callback(1,nullptr);

  return 0;
}
