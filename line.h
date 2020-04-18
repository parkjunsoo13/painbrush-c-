#pragma once
#include "figure.h"

// Figure를 상속받는 Line 클래스.
class Line :public Figure {
public:
	Line(int x, int y, int sizeX, int sizeY, int n, View *v);
	void draw(); // Overriding.
};