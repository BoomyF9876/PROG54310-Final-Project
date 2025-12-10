#include "GameController.h"
#include "WindowController.h"
#include "TextController.h"
#include "PostProcessor.h"
#include "EngineTime.h"
#include "Skybox.h"
#include "Shader.h"
#include "Mesh.h"
#include "Font.h"
#include "Camera.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    GameController* gc = static_cast<GameController*>(glfwGetWindowUserPointer(window));
}

void GameController::RenderMesh(std::string meshName)
{
    meshes[meshName]->SetRotation(meshes[meshName]->GetRotation() + Time::Instance().DeltaTime() * glm::vec3(meshes[meshName]->GetRotationRate(), 0.0f, 0.0f));
    meshes[meshName]->Render(camera->GetProjection() * camera->GetView(), light, meshCount);
}

void GameController::RenderMouseEventListener(
    OpenGL::ToolWindow^ toolWindow,
    Mesh* mesh,
    GLFWwindow* window,
    std::string meshKey,
    std::string shaderKey,
    std::string displayText
)
{
    glm::vec3 cursorPos, displayPos;
    std::string leftPress = "Up", middlePress = "Up";
    Resolution res = WindowController::GetInstance().GetResolution();

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        cursorPos = glm::vec3(
            (xpos - res.width / 2) * Time::Instance().DeltaTime() * 0.005f,
            (res.height / 2 - ypos) * Time::Instance().DeltaTime() * 0.005f,
            0
        );

        mesh->SetPosition(mesh->GetPosition() + cursorPos);
        leftPress = "Down";
    }

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS)
    {
        cursorPos = glm::vec3(
            0,
            0,
            (res.height / 2 - ypos) * Time::Instance().DeltaTime() * -0.005f
        );

        mesh->SetPosition(mesh->GetPosition() + cursorPos);
        middlePress = "Down";
    }

    if (toolWindow->moveLight && toolWindow->isResetLightClicked)
    {
        mesh->SetPosition(glm::vec3(0, 0, 3.0f));
        toolWindow->isResetLightClicked = false;
    }

    if (toolWindow->transform && toolWindow->isResetTransClicked)
    {
        mesh->ResetTransform();
        toolWindow->isResetTransClicked = false;
    }

    textController->RenderText("Left Button: " + leftPress, 20, 130, 0.5f, txtColor);
    textController->RenderText("Middle Button: " + middlePress, 20, 160, 0.5f, txtColor);

    displayPos = meshes[meshKey]->GetPosition();
    textController->RenderText(
        "Fighter Position: {" + std::to_string(displayPos.x) + " " + std::to_string(displayPos.y) + " " + std::to_string(displayPos.z) + "}",
        20, 190, 0.5f, txtColor
    );

    displayPos = meshes[meshKey]->GetRotation();
    textController->RenderText(
        "Fighter Rotation: {" + std::to_string(displayPos.x) + " " + std::to_string(displayPos.y) + " " + std::to_string(displayPos.z) + "}",
        20, 220, 0.5f, txtColor
    );

    displayPos = meshes[meshKey]->GetScale();
    textController->RenderText(
        "Fighter Scale: {" + std::to_string(displayPos.x) + " " + std::to_string(displayPos.y) + " " + std::to_string(displayPos.z) + "}",
        20, 250, 0.5f, txtColor
    );
}

void GameController::Initialize()
{
    GLFWwindow* window = WindowController::GetInstance().GetWindow();

    M_ASSERT(glewInit() == GLEW_OK, "Unable");
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    /*glCullFace(GL_BACK);
    glFrontFace(GL_CW);*/
    srand(time(0));

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    Load();
}

void GameController::RunGame()
{
    GLFWwindow* window = WindowController::GetInstance().GetWindow();
    OpenGL::ToolWindow^ toolWindow = gcnew OpenGL::ToolWindow();
    toolWindow->Show();
    toolWindow->SetRotationRate(meshes["Fighter"]->GetRotationRate());
    toolWindow->SetSpecularStrength(meshes["Fighter"]->GetSpecularStrength());
    
    glm::vec3 color = meshes["Fighter"]->GetSpecularColor();
    toolWindow->SetColorRGB(color.x, color.y, color.z);

    Time::Instance().Initialize();

    it = effectShaders.begin();
    glfwSetKeyCallback(window, key_callback);
    glfwSetWindowUserPointer(window, this);

    do {
        Time::Instance().Update();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwGetCursorPos(window, &xpos, &ypos);

        if (postProcessor != nullptr) postProcessor->Start();

        if (skybox != nullptr && toolWindow->spaceScene)
        {
            camera->Rotate();
            glm::mat4 view = glm::mat4(glm::mat3(camera->GetView()));
            skybox->Render(camera->GetProjection() * view);
            RenderMesh("FishInstance");
        }

        if (toolWindow->moveLight) light->Render(camera->GetProjection() * camera->GetView(), light);

        textController->RenderText("Final Project", 20, 40, 0.5f, txtColor);
        textController->RenderText(std::to_string(Time::Instance().FPS()), 20, 70, 0.5f, txtColor);
        textController->RenderText("Mouse Pos: " + std::to_string(xpos) + " " + std::to_string(ypos), 20, 100, 0.5f, txtColor);

        meshes["Fighter"]->SetRotationRate(toolWindow->fighterRotation);
        meshes["Fighter"]->SetSpecularStrength(toolWindow->specularStrength);
        light->SetSpecularColor(toolWindow->specularColorR, toolWindow->specularColorG, toolWindow->specularColorB);

        if (toolWindow->moveLight) RenderMouseEventListener(toolWindow, light, window, "Fighter", "Diffuse", "");
        if (toolWindow->transform) RenderMouseEventListener(toolWindow, meshes["Fighter"], window, "Fighter", "Diffuse", "");
        
        RenderMesh("Fighter");
        
        if (postProcessor != nullptr) postProcessor->End();

        glfwSwapBuffers(window);
        glfwPollEvents();

    } while (
        glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0
        );

    for (auto& mesh : meshes)
    {
        delete mesh.second;
    }

    if (light != nullptr)
    {
        delete light;
    }

    for (auto& shader : shaders)
    {
        delete shader.second;
    }

    for (auto& font : fonts)
    {
        delete font.second;
    }

    if (textController != nullptr)
    {
        delete textController;
    }

    if (skybox != nullptr)
    {
        delete skybox;
    }

    if (postProcessor != nullptr)
    {
        delete postProcessor;
    }

    delete camera;
}

void GameController::Load()
{
#pragma region Settings
    const std::string str = "../Assets/settings.json";
    json::JSON document = LoadJson(str);
#pragma endregion

#pragma region Clear Color
    glm::vec3 ClearColor{ 0, 0, 0 };
    json::JSON& jsonClearColor = Get(document, "ClearColor");
    ClearColor.x = Get(jsonClearColor, "r").ToFloat();
    ClearColor.y = Get(jsonClearColor, "g").ToFloat();
    ClearColor.z = Get(jsonClearColor, "b").ToFloat();
    glClearColor(ClearColor.r, ClearColor.g, ClearColor.b, 0.0f);
#pragma endregion

#pragma region Camera    
    camera = new Camera(WindowController::GetInstance().GetResolution());
    if (document.hasKey("Camera"))
    {
        camera->Create(WindowController::GetInstance().GetResolution(), document["Camera"]);
    }
#pragma endregion

#pragma region Shader
    json::JSON& shadersJSON = Get(document, "Shaders");
    for (auto& shaderJSON : shadersJSON.ArrayRange())
    {
        assert(shaderJSON.hasKey("name"));
        assert(shaderJSON.hasKey("vertex"));
        assert(shaderJSON.hasKey("fragment"));
        Shader* shaderColor = new Shader();
        shaderColor->LoadShaders(shaderJSON["vertex"].ToString().c_str(), shaderJSON["fragment"].ToString().c_str());
        shaders.emplace(shaderJSON["name"].ToString().c_str(), shaderColor);
    }
#pragma endregion

#pragma region Effect Shader
    json::JSON& effectShadersJSON = Get(document, "EffectShaders");
    for (auto& shaderJSON : effectShadersJSON.ArrayRange())
    {
        assert(shaderJSON.hasKey("name"));
        assert(shaderJSON.hasKey("vertex"));
        assert(shaderJSON.hasKey("fragment"));
        Shader* effectShaderColor = new Shader();
        effectShaderColor->LoadShaders(shaderJSON["vertex"].ToString().c_str(), shaderJSON["fragment"].ToString().c_str());
        effectShaders.emplace(shaderJSON["name"].ToString().c_str(), effectShaderColor);
    }
#pragma endregion

#pragma region Scene
    M_ASSERT(document.hasKey("DefaultFile"), "Settings requires a default file");
    std::string defaultFile = document["DefaultFile"].ToString();

    document = LoadJson(defaultFile);

    json::JSON& lightJSON = Get(document, "Light");
    light = new Mesh();
    light->Create(lightJSON);
    light->SetCameraPosition(camera->GetPosition());

    for (auto& meshJSON : document.ObjectRange())
    {
        if (
            meshJSON.first == "Light" ||
            meshJSON.first == "Fonts" ||
            meshJSON.first == "Skybox" ||
            meshJSON.first == "TextController" ||
            meshJSON.first == "PostProcessor"
            ) continue;

        Mesh* mesh = new Mesh();
        mesh->Create(meshJSON.second);
        mesh->SetCameraPosition(camera->GetPosition());
        meshes.emplace(meshJSON.first, mesh);
    }
#pragma endregion

#pragma region Skyboxes
    if (document.hasKey("Skybox"))
    {
        skybox = new Skybox();
        skybox->Create(document["Skybox"]);
    }
#pragma endregion 


#pragma region Fonts
    if (document.hasKey("Fonts"))
    {
        json::JSON& fontsJSON = document["Fonts"];
        for (auto& fontJSON : fontsJSON.ArrayRange())
        {
            M_ASSERT(fontJSON.hasKey("Name"), "Font requires a name");
            std::string fontName = fontJSON["Name"].ToString();

            M_ASSERT(fontJSON.hasKey("Font"), "Font requires a Font node");

            Font* font = new Font();
            font->Create(fontJSON["Font"]);
            fonts.emplace(fontName, font);
        }
    }
#pragma endregion

#pragma region TextController
    if (document.hasKey("TextController"))
    {
        textController = new TextController();
        textController->Create(document["TextController"]);
    }
#pragma endregion

#pragma region Post Processing
    if (document.hasKey("PostProcessor"))
    {
        postProcessor = new PostProcessor();
        postProcessor->Create(document["PostProcessor"]);
    }
#pragma endregion
}
