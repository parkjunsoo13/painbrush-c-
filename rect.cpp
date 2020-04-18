#include "stdafx.h"
#include "rect.h"
#include "View.h"

// Rect 생성자.
Rect::Rect(int x, int y, int sizeX, int sizeY, int n, View *v) :Figure(x, y, sizeX, sizeY,n, v) {}

// 사각형을 그리는 함수.

void Rect::draw() {
	m_v->setPenColor(RGB(0, 0, 0));
	m_v->setFillColor(RGB(255, 255, 255));
	m_v->drawRectangle(m_x, m_y, m_sizeX, m_sizeY);
}
