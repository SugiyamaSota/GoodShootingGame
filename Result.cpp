#include "Result.h"
#include<Novice.h>

Result::Result() {
	sceneChange = false;
}

void Result::Update(char keys[256], char preKeys[256]) {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneChange = true;
	}
}

void Result::Draw() {
	Novice::ScreenPrintf(550, 250, "!Thankyou For Playing!");
	Novice::ScreenPrintf(620, 300, "SPACE");
}
