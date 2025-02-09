#include"HitJudge.h"

bool isHit(Object object1, Object object2) {
	if (powf(float(object1.radius + object2.radius), 2.0f) >=
		powf(object1.pos.x - object2.pos.x, 2.0f) +
		powf(object1.pos.y - object2.pos.y, 2.0f)) {
		return true;
	} else {
		return false;
	}
}