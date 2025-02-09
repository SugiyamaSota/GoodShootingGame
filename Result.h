#pragma once
class Result{
public:
	Result();

	void Update(char keys[256], char preKeys[256]);

	void Draw();

	bool sceneChange;
};

