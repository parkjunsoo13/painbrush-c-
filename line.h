#pragma once
#include "figure.h"

// Figure�� ��ӹ޴� Line Ŭ����.
class Line :public Figure {
public:
	Line(int x, int y, int sizeX, int sizeY, int n, View *v);
	void draw(); // Overriding.
};