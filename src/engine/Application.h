#pragma once
#include "Window.h"
#include "Gui.h"
#include <iostream>
#include <vector>
#include "Entity2D.h"
#include "Scene.h"
#include "Input.h"
#include "ApplicationInfo.h"

class Application{
public:
    void Run();
    virtual void Update(){}
    virtual void Start() {} 
    Window* getWindow(){return applicationWindow;}
    Gui* getGui(){return gui;}
    void EngineTerminate(int exitCode);
    Scene& getCurrentScene(){return currentScene;}
    Entity2D* Instantiate(Entity2D* _entity){currentScene.m_entitiesInScene.push_back(_entity);Stats::getInstance().currentObjectsinScene = currentScene.m_entitiesInScene.size();return _entity;}
private:
    Input input = Input();
    ApplicationInfo app = ApplicationInfo();
    float m_RenderCalls;
    void UpdateApplication();
    Scene currentScene = Scene();
    Window* applicationWindow;
    Gui* gui = nullptr;
};
