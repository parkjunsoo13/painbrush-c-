#include "stdafx.h"
#include "line.h"
#include "View.h"

// Line 생성자.
Line::Line(int x, int y, int sizeX, int sizeY,int n, View *v) :Figure(x, y, sizeX, sizeY,n, v) {}

// 선분을 그리는 함수.
void Line::draw() {
	m_v->setPenColor(RGB(0, 0, 0));
	m_v->drawLine(m_x, m_y, m_sizeX, m_sizeY);
}