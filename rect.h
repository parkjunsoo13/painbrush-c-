#pragma once
#include "figure.h"

// Figure�� ��ӹ޴� Rect Ŭ����.
class Rect :public Figure {
public:
	Rect(int x, int y, int sizeX, int sizeY, int n, View *v);
	void draw(); // Overriding.
};
