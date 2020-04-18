#include "stdafx.h"
#include "tbutton.h"
#include "View.h"

// »ý¼ºÀÚ.
TButton::TButton(string s, View *v) :MyButton(s,v) {
}

void TButton::draw() {
	
	m_v->setPenColor(RGB(220, 220, 220));
	m_v->setFillColor(RGB(220, 220, 220));
	m_v->setTextBkColor(RGB(220, 220, 220));
	MyButton::draw();
}