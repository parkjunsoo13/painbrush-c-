#include "stdafx.h"
#include "menubar.h"
#include "View.h"
#include "menu.h"


Menubar::Menubar() {}

void Menubar::addComponent(Component * c, View *v) {
	Container::addComponent(c, v);
	c->setSize(menuNum * 64 , 0, 64, 32);
	menuNum++;
}

void Menubar::draw() {
	m_v->setPenColor(RGB(220, 220, 220));
	m_v->setFillColor(RGB(220, 220, 220));
	m_v->drawRectangle(0, 0, m_v->getWindowWidth(), 32);
	Container::draw();
}


void Menubar::OnMouseMove(Event e) {
	for (list<Component *>::iterator c = CList.begin(); c != CList.end(); c++) {
		if ((*c)->Click_Check(e.x, e.y) && (*c)->check == false) { // ���콺Ŀ���� Ư�� ��ư ���� �ִٸ�,
			(*c)->onMouse(); // ��ư �� ĥ��.
			(*c)->check = true; // Ư�� ��ư ���� ������ üũ.
		}
		else if (!(*c)->Click_Check(e.x, e.y) && (*c)->check == true) { // ���콺Ŀ���� Ư�� ��ư ���� ���ٸ�, �׸��� ��ư ���� �־����ٸ�,
			(*c)->draw(); // �ٽ� �׸�.
			(*c)->check = false; // Ư�� ��ư ���� ������ üũ�����ν� ��ư�� �� ���� ���� ���� �ٽ� �׸�.
		}
	}
}

void Menubar::OnLButtonDown(Event e) {
	Start_x = e.x;
	Start_y = e.y;
}


bool Menubar::isOnMenubar(Event e) {
	// Down�� ���� �κ��� ���ԵǸ� �׸��� ����.
	if (Start_x <= m_v->getWindowWidth() && Start_x > 0 && Start_y <= 32 && Start_y >= 0) {
		return true;
	}
	// Up�� ���� �κ��� ���� �Ǹ� �׸��� ����.
	if (e.x <= m_v->getWindowWidth() && e.x > 0 && e.y <= 32 && e.y >= 0) {
		return true;
	}

	return false;
}

// ��ư�� ������ ��� � ��ư�� �������� Ȯ���ϴ� �Լ�.
Component * Menubar::find(Event e) {
	Component *dp = Container::find(e);
	return (Menu *)dp;
}

bool Menubar::ButtonOn(Event e) {
	for (auto c : CList) {
		if (c->Click_Check(e.x, e.y) && c->getName() == "����") {
			return true;
		}
		if (c->Click_Check(e.x, e.y) && c->getName() == "����") {
			return true;
		}
	}
	return false;
}