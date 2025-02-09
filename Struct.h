#pragma once

template<typename T>
struct Vector2 {
	T x;
	T y;
};

struct Object {
	Vector2<float> pos;
	Vector2<float> velocity;
	int radius;
};