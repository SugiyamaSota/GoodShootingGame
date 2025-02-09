#pragma once
#include"Struct.h"

class Enemy{
public:
	Enemy();


	void Update();

	void Draw();

	void SetHitPoint(int damage);
	void SetIsAlive(bool which);

	int GetHitPoint() { return HitPoint_; }
	bool GetIsAlive() { return isAlive_; }
	Object GetObject() { return enemy_; }

private:
	Object enemy_;
	int HitPoint_;
	bool isAlive_;
	int respawnCoolTime_;
	const int respawnCoolTimeSet_ = 60;
};

