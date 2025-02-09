#include "Player.h"
#include"Novice.h"

Player::Player(Vector2<float>pos){
	player_.pos = pos;
	player_.velocity = { 5.0f,5.0f };
	player_.radius = 10;
	shotCoolTime_ = 0;

	bullet = new Bullet();
}

Player::~Player() {
	delete bullet;
}

void Player::Update(char keys[256]) {
	if (keys[DIK_W]) {
		player_.pos.y -= player_.velocity.y;
	}
	if (keys[DIK_A]) {
		player_.pos.x -= player_.velocity.x;
	}
	if (keys[DIK_S]) {
		player_.pos.y += player_.velocity.y;
	}
	if (keys[DIK_D]) {
		player_.pos.x += player_.velocity.x;
	}
	shotCoolTime_--;
	if(keys[DIK_SPACE]){
		for (int i = 0; i < 10; i++) {
			if (shotCoolTime_ <= 0) {
				if (!bullet->GetIsShot(i)) {
					bullet->SetIsShot(i, true);
					bullet->SetPos(i, player_.pos);
					shotCoolTime_ = shotCoolTimeSet_;
				}
			}
		}
	}
	bullet->Update();
}

void Player::Draw() {
	Novice::DrawEllipse(int(player_.pos.x), int(player_.pos.y), player_.radius, player_.radius, 0.0f, RED, kFillModeSolid);
	bullet->Draw();
}
