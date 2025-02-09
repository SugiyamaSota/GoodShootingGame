#include "Enemy.h"
#include<Novice.h>

Enemy::Enemy() {
	enemy_.pos = { 50.0f,100.0f };
	enemy_.radius = 30;
	enemy_.velocity = { 3.0f,0.0f };
	HitPoint_ = 3;
	isAlive_ = true;
	respawnCoolTime_ = respawnCoolTimeSet_;
}

void Enemy::Update() {
	if (isAlive_) {
		enemy_.pos.x += enemy_.velocity.x;
		enemy_.pos.y += enemy_.velocity.y;
	}
	if (enemy_.pos.x <= float(enemy_.radius) || enemy_.pos.x >= float(1280 - enemy_.radius)) {
		enemy_.velocity.x *= -1;
	}
	if (!isAlive_) {
		respawnCoolTime_--;
	}
	if (respawnCoolTime_ <= 0) {
		isAlive_ = true;
		respawnCoolTime_ = respawnCoolTimeSet_;
	}
}

void Enemy::SetHitPoint(int damage) {
	HitPoint_ -= damage;
}

void Enemy::SetIsAlive(bool which) {
	isAlive_ = which;
}

void Enemy::Draw() {
	if (isAlive_) {
		Novice::DrawQuad(
			int(enemy_.pos.x - enemy_.radius), int(enemy_.pos.y - enemy_.radius),
			int(enemy_.pos.x + enemy_.radius), int(enemy_.pos.y - enemy_.radius),
			int(enemy_.pos.x - enemy_.radius), int(enemy_.pos.y + enemy_.radius),
			int(enemy_.pos.x + enemy_.radius), int(enemy_.pos.y + enemy_.radius),
			0, 0, 1, 1, 0, WHITE);
	}
	Novice::ScreenPrintf(0, 0, "HP:%d", HitPoint_);
}
