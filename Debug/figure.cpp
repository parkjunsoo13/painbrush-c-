#include "stdafx.h"
#include "figure.h"
#include "View.h"

// »ı¼ºÀÚ.
Figure::Figure(int x, int y, int sizeX, int sizeY, int n, View *v) {
	m_x = x;
	m_y = y;
	m_sizeX = sizeX;
	m_sizeY = sizeY;
	m_v = v;
	this->n = n;
}

void Figure::draw() {}

int Figure::Type(){
	return n;
}

int Figure::GetSx() {return m_x;}
int Figure::GetSy() {return m_y;}
int Figure::GetEx() {return m_sizeX;}
int Figure::GetEy() {return m_sizeY;}