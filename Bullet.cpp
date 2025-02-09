#include "Bullet.h"
#include<Novice.h>

Bullet::Bullet() {
	for (int i = 0; i < 10; i++) {
		bullet_[i].pos = {};
		bullet_[i].radius = 10;
		bullet_[i].velocity = { 0.0f,-5.0f };
		isShot_[i] = false;

	}
}

void Bullet::Update() {
	for (int i = 0; i < 10; i++) {
		if (isShot_[i]) {
			bullet_[i].pos.x += bullet_[i].velocity.x;
			bullet_[i].pos.y += bullet_[i].velocity.y;
		}
		if (bullet_[i].pos.y <= bullet_[i].radius) {
			isShot_[i] = false;
		}
	}
}

void Bullet::SetPos(int i, Vector2<float>pos) {
	bullet_[i].pos.x = pos.x;
	bullet_[i].pos.y = pos.y;
}

void Bullet::SetIsShot(int i, bool which) {
	isShot_[i] = which;
}


void Bullet::Draw() {
	for (int i = 0; i < 10; i++) {
		if (isShot_[i]) {
			Novice::DrawEllipse(int(bullet_[i].pos.x), int(bullet_[i].pos.y), bullet_[i].radius, bullet_[i].radius, 0.0f, WHITE, kFillModeSolid);
		}
	}
}