#pragma once
#include"Title.h"
#include"Game.h"
#include"Result.h"
#include"Enum.h"

class Scene{
public:
	Scene();

	void Update(char keys[256], char preKeys[256]);

	void Draw();

	Title* title;
	Game* game;
	Result* result;

	SceneName nowScene;
};

