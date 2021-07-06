#pragma once
#include <GLFW/glfw3.h>
#include "Vertex2.h"
#include <vector>
#include <iostream>
#include "Vector2.h"
#include "Stats.h"
#include "ECS.h"
#include <memory>
#include "Input.h"


class Entity2D{
public: 




    Entity2D(float xPos = 0,float yPos = 0, bool loadDefault = true){
        position.m_PositionX = xPos;
        position.m_PositionY = yPos;
        if(loadDefault){
            LoadSquare();
        }
    }

    void Render(){

        if(!canRender){
            return;
        }

        if(vertex.size() == 0){
            std::cout << "Render process has failed." << std::endl;
            canRender = false;
            exit(0);
        } else if (vertex.size() > 0){canRender == true;}
        glLoadIdentity();
        for(int i = 0; i < Components.size() ; i++) {
            Components[i]->OnUpdate();
        }
        glTranslatef(position.m_PositionX,position.m_PositionY,0);
        glBegin(GL_POLYGON);
        for(int i = 0; i < vertex.size() ; i++){
            glVertex2f(vertex[i].vertexX,vertex[i].vertexY);
        }

        glEnd();
        glFlush();
        Stats::getInstance().m_RenderCalls += 1;   
    }

    Vector2 *getPosition(){return &position;}


    void LoadSquare(){
        vertex.clear();
        AddVertex(0,0);
        AddVertex(1,0);
        AddVertex(1,1);
        AddVertex(0,1);
    }

    void AddVertex(float x,float y){
        vertex.push_back(Vertex2D(x,y));
    }


    template <typename T>
    T& AddComponent(){
        T* t = new T();
        std::unique_ptr<ECS> ptr {t};
        t->OnStart();
        t->SetPosition(&position);
        Components.push_back(std::move(ptr));
        return *t;
    }
private:
    std::vector<std::unique_ptr<ECS>> Components;
    bool canRender = true;
    Vector2 position = Vector2(0,0);
    std::vector<Vertex2D> vertex;
};