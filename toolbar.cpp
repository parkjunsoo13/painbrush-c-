#include "stdafx.h"
#include "toolbar.h"
#include "View.h"
#include "tbutton.h"
#include "Misc.h"
#include "figure.h"


// ������.
Toolbar::Toolbar() :Container() {}

void Toolbar::addComponent(Component *c, View *v) {
	Container::addComponent(c,v);
	c->setSize(btnNum * 32, 32, 32, 32);
	btnNum++;
}

void Toolbar::draw() {

	m_v->setPenColor(RGB(220, 220, 220));
	m_v->setFillColor(RGB(220, 220, 220));
	m_v->drawRectangle(0, 32, m_v->getWindowWidth(), 32);
	Container::draw();
}

void Toolbar::OnMouseMove(Event e) {

	for (list<Component *>::iterator c = CList.begin(); c != CList.end(); c++) {
		if ((*c)->Click_Check(e.x, e.y) && (*c)->check == false) { 
			(*c)->onMouse();
			(*c)->check = true;
		}
		else if (!(*c)->Click_Check(e.x, e.y) && (*c)->check == true) { 
			(*c)->draw();
			(*c)->check = false; 
		}
	}

}

bool Toolbar::decideLine(Event e) {
	//���콺�� ������ �� decideL���� ��ư�� ȸ�� �� ���� �ִ°�� decideL =1 �� �������ش�.
	if (Start_x < m_v->getWindowWidth() && Start_x > 0 && Start_y <= 64 && Start_y >= 0) {
		decideL = 1;
	}
	End_x = e.x;
	End_y = e.y;

	//���콺�� �����ų� ���� �� ��ư�� ȸ�� �� ���� �ִ°�� true�� ��ȯ���ش�.
	if (End_x <= m_v->getWindowWidth() && End_x > 0 && End_y <= 64 && End_y >= 0 || decideL == 1) {
		decideL = 0;//decideL�� �ٽ� �ʱ�ȭ ��Ų��.
		return true;
	}
	return false;
}

void Toolbar::OnLButtonDown(Event e) {
	
	Start_x = e.x;
	Start_y = e.y;
}

bool Toolbar::ButtonClick(Event e) {
	for (auto i : CList) {
		if (i->Click_Check(e.x, e.y)) {
			if (i->getName() == "R" || i->getName() == "E" || i->getName() == "L") {
				return true;
			}
		}
	}
	return false;
}

bool Toolbar::isOnToolbar(Event e) {
	
	if (Start_x <= m_v->getWindowWidth() && Start_x > 32 && Start_y <= 64 && Start_y >= 32) {
		return true;
	}
	
	if (e.x <= m_v->getWindowWidth() && e.x > 32 && e.y <= 64 && e.y >= 32) {
		return true;
	}

	return false;
}

Component* Toolbar::find(Event e) {
	Component *dp = Container::find(e);
	return (TButton *)dp; 
}
