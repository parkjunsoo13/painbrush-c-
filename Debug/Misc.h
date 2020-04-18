#pragma once
#include "stdafx.h"
//#include "Proj2018.h"
// 잡다한 것들을 넣기 위한 헤더 파일
void debugOutput(int n);
void debugOutput(int n1, int n2, int n3, int n4);
void debugOutput(const char *s);

// x, y 좌표와 ctrl, shift를 판별하는 Event 클래스.
class Event {
public:
	Event(long wp, int x, int y); // 생성자.
	int x, y; // x,y 좌표.
	long wParam; 
};

