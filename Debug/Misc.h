#pragma once
#include "stdafx.h"
//#include "Proj2018.h"
// ����� �͵��� �ֱ� ���� ��� ����
void debugOutput(int n);
void debugOutput(int n1, int n2, int n3, int n4);
void debugOutput(const char *s);

// x, y ��ǥ�� ctrl, shift�� �Ǻ��ϴ� Event Ŭ����.
class Event {
public:
	Event(long wp, int x, int y); // ������.
	int x, y; // x,y ��ǥ.
	long wParam; 
};

