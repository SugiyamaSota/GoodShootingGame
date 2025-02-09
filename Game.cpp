#include "Game.h"
#include "HitJudge.h"

Game::Game() {
	player = new Player(Vector2<float>{640.0f, 600.0f});
	enemy = new Enemy();

	sceneChange = false;
}

Game::~Game() {
	delete player;
	delete enemy;
}


void Game::Update(char keys[256]) {
	player->Update(keys);
	enemy->Update();

	if (enemy->GetHitPoint() <= 0) {
		sceneChange = true;
	}
}

void Game::HitJudge() {
	for (int i = 0; i < 10; i++) {
		if (isHit(player->bullet->GetObject(i), enemy->GetObject()) && player->bullet->GetIsShot(i) && enemy->GetIsAlive()) {
			enemy->SetIsAlive(false);
			player->bullet->SetIsShot(i, false);
			enemy->SetHitPoint(1);
		}
	}
	if (isHit(player->GetObject(), enemy->GetObject()) && enemy->GetIsAlive()) {
		sceneChange = true;
	}
}

void Game::Draw() {
	player->Draw();
	enemy->Draw();
}