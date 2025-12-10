#pragma once

#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_

#include "StandardIncludes.h"
#include "ToolWindow.h"

class Font;
class Mesh;
class Camera;
class Skybox;
class Shader;
class TextController;
class PostProcessor;

class GameController
{
public:
	static GameController& GetInstance()
	{
		static GameController instance;
		return instance;
	}

	void Initialize();
	void RunGame();
	void Load();

	Shader* GetShader(const char* shaderName)
	{
		auto itr = shaders.find(shaderName);
		assert(itr != shaders.end());
		return itr->second;
	}

	std::map<std::string, Shader*>::iterator& GetIt() { return it; }
	PostProcessor* GetProcessor() { return postProcessor; }
	std::map<std::string, Shader*>& GetEffectShaders() { return effectShaders; }

	Font* GetFont(const char* fontName)
	{
		auto itr = fonts.find(fontName);
		assert(itr != fonts.end());
		return itr->second;
	}

	void RenderMesh(std::string meshName);
	void RenderMouseEventListener(OpenGL::ToolWindow^ toolWindow, Mesh* mesh, GLFWwindow* window, std::string meshKey, std::string shaderKey, std::string displayText);

private:
	std::map<std::string, Shader*> shaders;
	std::map<std::string, Shader*> effectShaders;
	std::map<std::string, Shader*>::iterator it;
	std::map<std::string, Font*> fonts;

	PostProcessor* postProcessor = nullptr;
	Skybox* skybox = nullptr;
	std::map<std::string, Mesh*> meshes;
	Mesh* light;

	TextController* textController = nullptr;
	Camera* camera = nullptr;

	glm::vec3 txtColor = {1.0f, 1.0f, 0.0f};
	double xpos, ypos;
	int meshCount = 100;
	GLuint vao;

	inline explicit GameController() = default;
	inline ~GameController() = default;
	inline explicit GameController(GameController const&) = delete;
	inline GameController& operator=(GameController const&) = delete;
};

#endif

