#pragma once
#include "figure.h"

// Figure�� ��ӹ޴� Ellip Ŭ����.
class Ellip :public Figure {
public:
	Ellip(int Start_x, int Start_y, int End_x, int End_y, int n, View *v);
	void draw(); // Overriding.
	int Type();
	int GetSx();
	int GetSy();
	int GetEx();
	int GetEy();
};