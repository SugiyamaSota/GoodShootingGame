#include "Title.h"
#include<Novice.h>

Title::Title() {
	sceneChange = false;
}

void Title::Update(char keys[256], char preKeys[256]) {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneChange = true;
	}
}

void Title::Draw() {
	Novice::ScreenPrintf(550, 250, "!Good Shooting Game!");
	Novice::ScreenPrintf(620, 300, "SPACE");
}
