#include "stdafx.h"
#include "component.h"
#include "View.h"



Component::Component() {}


Component::Component(string s, View * v) {
	m_name = s;
	m_v = v;
}

void Component::draw() {

}

void Component::addActionListener(ActionListener * l)
{
}

void Component::mouseClick()
{
}


void Component::setSize(int x, int y, int sizeX, int sizeY) {
	Start_x = x;
	Start_y = y;
	End_x = sizeX;
	End_y = sizeY;
}

bool Component::Click_Check(int x, int y) {
	return (x >= Start_x && x <= Start_x + End_x && y >= Start_y && y <= Start_y + End_y);
}

string Component::getName() {
	return m_name;
}


void Component::onMouse() {
	SIZE size;

	size = m_v->textSize(m_name);
	m_v->setFillColor(RGB(200, 200, 200));
	m_v->drawRectangle(Start_x, Start_y, End_x, End_y);
	m_v->setTextBkColor(RGB(200, 200, 200));
	m_v->drawText(m_name, Start_x + End_x / 2 - (size.cx / 2), Start_y + End_y / 2 - (size.cy / 2));
}
