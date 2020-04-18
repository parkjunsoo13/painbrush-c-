#include "stdafx.h"
#include "Misc.h"
#include <cstdio>
void debugOutput(int n) {
	char buf[100];
	sprintf_s(buf, " %d ", n);
	OutputDebugStringA(buf);
}

void debugOutput(int n1, int n2, int n3, int n4) {
	char buf[100];
	sprintf_s(buf, "[ %d %d %d %d ]\n ", n1, n2, n3, n4);
	OutputDebugStringA(buf);
}

void debugOutput(const char *s) {
	OutputDebugStringA(s);
}

// »ý¼ºÀÚ.
Event::Event(long wp, int x, int y) {
	this->x = x;
	this->y = y;
	this->wParam = wp;
}



