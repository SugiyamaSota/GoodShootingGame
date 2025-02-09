#pragma once
#include"Struct.h"

class Bullet{
public:
	Bullet();

	void Update();

	void Draw();

	void SetPos(int i, Vector2<float>pos);
	void SetIsShot(int i, bool which);

	Vector2<float> GetPos(int i) { return bullet_[i].pos; };
	Vector2<float> GetVelocity(int i) { return bullet_[i].velocity; };
	int GetRadius(int i) { return bullet_[i].radius; };
	bool GetIsShot(int i) { return isShot_[i]; };
	Object GetObject(int i) { return bullet_[i]; }

private:
	Object bullet_[10];
	bool isShot_[10];

};

