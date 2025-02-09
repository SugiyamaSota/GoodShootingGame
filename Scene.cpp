#include "Scene.h"

Scene::Scene() {
	nowScene = TitleScene;
	title = new Title();
}

void Scene::Update(char keys[256], char preKeys[256]) {
	switch (nowScene) {
	case TitleScene:
		title->Update(keys, preKeys);
		if (title->sceneChange) {
			game = new Game();
			nowScene = GameScene;
			delete title;
		}
		break;
	case GameScene:
		game->Update(keys);
		game->HitJudge();
		if (game->sceneChange) {
			result = new Result();
			nowScene = ResultScene;
			delete game;
		}
		break;
	case ResultScene:
		result->Update(keys, preKeys);
		if (result->sceneChange) {
			title = new Title();
			nowScene = TitleScene;
			delete result;
		}
		break;
	}
}

void Scene::Draw() {
	switch (nowScene) {
	case TitleScene:
		title->Draw();
		break;
	case GameScene:
		game->Draw();
		break;
	case ResultScene:
		result->Draw();
		break;
	}
}
