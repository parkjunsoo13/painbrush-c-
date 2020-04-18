#include "stdafx.h"
#include "ellip.h"
#include "View.h"

// Ellip(타원) 생성자.
Ellip::Ellip(int x, int y, int sizeX, int sizeY, int n, View *v) :Figure(x, y, sizeX, sizeY,n, v) {}


// 타원을 그리는 함수.
void Ellip::draw() {
	m_v->setPenColor(RGB(0, 0, 0));
	m_v->setFillColor(RGB(255, 255, 255));
	m_v->drawEllipse(m_x, m_y, m_sizeX, m_sizeY);
}
