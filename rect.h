#pragma once
#include "figure.h"

// Figure를 상속받는 Rect 클래스.
class Rect :public Figure {
public:
	Rect(int x, int y, int sizeX, int sizeY, int n, View *v);
	void draw(); // Overriding.
};
