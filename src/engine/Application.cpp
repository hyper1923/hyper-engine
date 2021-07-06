#include "Application.h"
#include "Utility.h"


void Application::Run(){
    applicationWindow = new Window("HyperEngine",1280,720);
    gui = new Gui();
    gui->SetWindow(getWindow()->m_Window);
    gui->Init();
    input.getInstance().SetWindow(getWindow()->m_Window);
    app.getInstance().SetApplication(this);
    Start();
    UpdateApplication();
}




void Application::UpdateApplication(){
        while(applicationWindow->returnIsInit() == true){
            applicationWindow->Clear();
            Update();
            Stats::getInstance().m_frameCount ++;
            currentScene.SceneOnUpdate();
            gui->GuiUpdate();
            glfwSwapBuffers(applicationWindow->returnWindow());
            glfwPollEvents();
        }
}

void Application::EngineTerminate(int exitCode){
    exit(exitCode);
    glfwTerminate();
}