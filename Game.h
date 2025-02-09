#pragma once
#include"Player.h"
#include"Enemy.h"

class Game{
public:
	Game();

	~Game();

	void Update(char keys[256]);

	void HitJudge();

	void Draw();

	Player* player;

	Enemy* enemy;

	bool sceneChange;
};

