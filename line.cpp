#include "stdafx.h"
#include "line.h"
#include "View.h"

// Line ������.
Line::Line(int x, int y, int sizeX, int sizeY,int n, View *v) :Figure(x, y, sizeX, sizeY,n, v) {}

// ������ �׸��� �Լ�.
void Line::draw() {
	m_v->setPenColor(RGB(0, 0, 0));
	m_v->drawLine(m_x, m_y, m_sizeX, m_sizeY);
}