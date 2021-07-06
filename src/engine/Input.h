#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

class Input{
public:
    bool isKeyPressed(int KeyCode = 72){
        if(m_EngineWindow == nullptr){
            std::cout << "Error the engine window has null var." << std::endl;
            return false;
        }

        int temp = glfwGetKey(m_EngineWindow,KeyCode);
        bool keyPressed = false;
        if(temp == GLFW_PRESS){
            keyPressed = true;
        } else{
            keyPressed = false;
        }
        return keyPressed;
    }


    static Input& getInstance(){
        static Input input;
        return input;
    }

    
    void SetWindow(GLFWwindow* window){
        m_EngineWindow = window;
    }

private:
    GLFWwindow* m_EngineWindow;

};