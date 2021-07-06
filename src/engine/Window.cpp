#include "Window.h"



Window::Window(const char* titleName,int width,int height){
    m_Height = height;
    m_Width = width;
    m_windowTitle = titleName;
    Window::Init();
}




bool Window::Init(){
    glfwInit();

    if(!glfwInit()){
        std::cout << "Failed to initalize GLFW." << std::endl;
        isInit = false;
    }
    m_Window = glfwCreateWindow(m_Width,m_Height,m_windowTitle,NULL,NULL);
    glfwMakeContextCurrent(m_Window);
    gladLoadGL();
    if(m_Window == nullptr){
        std::cout << "Failed to initialize Window." << std::endl;
        isInit = false;
        
    } else{
        isInit = true;
    }
    return false;
}

