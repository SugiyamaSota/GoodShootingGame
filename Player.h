#pragma once
#include"Struct.h"
#include"Bullet.h"

class Player{
public:	


	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">XY座標</param>
	Player(Vector2<float>pos);

	~Player();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(char keys[256]);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	Vector2<float> GetPos() { return player_.pos; };
	Vector2<float> GetVelocity() { return player_.velocity; };
	int GetRadius() { return player_.radius; };
	Object GetObject() { return player_; }

	Bullet* bullet;

private:
	// メンバ変数
	Object player_;
	int shotCoolTime_;
	const int shotCoolTimeSet_ = 10;
};

