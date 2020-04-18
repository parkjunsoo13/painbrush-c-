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
		if ((*c)->Click_Check(e.x, e.y) && (*c)->check == false) { // 마우스커서가 특정 버튼 위에 있다면,
			(*c)->onMouse(); // 버튼 색 칠함.
			(*c)->check = true; // 특정 버튼 위에 있음을 체크.
		}
		else if (!(*c)->Click_Check(e.x, e.y) && (*c)->check == true) { // 마우스커서가 특정 버튼 위에 없다면, 그리고 버튼 위에 있었었다면,
			(*c)->draw(); // 다시 그림.
			(*c)->check = false; // 특정 버튼 위에 없음을 체크함으로써 버튼이 들어갈 때와 나갈 때만 다시 그림.
		}
	}
}

void Menubar::OnLButtonDown(Event e) {
	Start_x = e.x;
	Start_y = e.y;
}


bool Menubar::isOnMenubar(Event e) {
	// Down시 툴바 부분이 포함되면 그리지 않음.
	if (Start_x <= m_v->getWindowWidth() && Start_x > 0 && Start_y <= 32 && Start_y >= 0) {
		return true;
	}
	// Up시 툴바 부분이 포함 되면 그리지 않음.
	if (e.x <= m_v->getWindowWidth() && e.x > 0 && e.y <= 32 && e.y >= 0) {
		return true;
	}

	return false;
}

// 버튼을 눌렀을 경우 어떤 버튼을 눌렀는지 확인하는 함수.
Component * Menubar::find(Event e) {
	Component *dp = Container::find(e);
	return (Menu *)dp;
}

bool Menubar::ButtonOn(Event e) {
	for (auto c : CList) {
		if (c->Click_Check(e.x, e.y) && c->getName() == "파일") {
			return true;
		}
		if (c->Click_Check(e.x, e.y) && c->getName() == "도형") {
			return true;
		}
	}
	return false;
}