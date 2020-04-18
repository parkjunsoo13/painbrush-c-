#include "stdafx.h"
#include "View.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "Misc.h"
#include "Figure.h"
#include "CEllipse.h"


CEllipse::CEllipse(int S_x, int S_y, int E_x, int E_y, View *v) :Figure(S_x, S_y, E_x, E_y, v) {} // 생성자 초기화 


void CEllipse::Draw() {
	m_v->setFillColor(RGB(255, 255, 255));
	m_v->setPenColor(RGB(0, 0, 0));
	m_v->drawEllipse(Sx, Sy, Ex, Ey); // 원을 그린다.
}