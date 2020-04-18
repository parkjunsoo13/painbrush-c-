#include "stdafx.h"
#include "menu.h"
#include "View.h"
#include "mybutton.h"
#include "menubar.h"
#include "menuitem.h"
#include <string>
#include <iostream>
using namespace std;



Menu::Menu() {}
Menu::Menu(string s, View *v) :Container(s, v) {}


void Menu::addComponent(Component * c, View *v) {
	Container::addComponent(c, v);
	c->setSize(Start_x, End_y + itemNum * 32, End_x, End_y);
	itemNum++;
}

void Menu::draw() {
	SIZE size;
	size = m_v->textSize(m_name);

	m_v->setPenColor(RGB(220, 220, 220));
	m_v->setFillColor(RGB(220, 220, 220));
	m_v->setTextBkColor(RGB(220, 220, 220));
	m_v->drawRectangle(Start_x, Start_y, End_x, End_y);
	m_v->drawText(m_name, Start_x + End_x / 2 - (size.cx / 2), Start_y + End_y / 2 - (size.cy / 2));

	if (CheckName == 1) {
		Container::draw();
	}
	if (CheckName == 2) {
		Container::draw();
	}
	
}

void Menu::OnLButtonDown(Event e)
{
	Start_x = e.x;
	Start_y = e.y;
}

void Menu::onMouse() {
	Component::onMouse();
}

// 버튼을 눌렀을 경우 어떤 버튼을 눌렀는지 확인하는 함수.
Component * Menu::find(Event e) {
	Component *bp = Container::find(e);
	return (MenuItem *)bp; // MenuItem으로 캐스팅 후 반환.
}

void Menu::CloseMenu() {
	
	m_v->invalidate();
	
}

void Menu::setCheckName(int s) {
	CheckName = s;
}
