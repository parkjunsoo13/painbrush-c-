#include "stdafx.h"
#include "mybutton.h"
#include "View.h"
#include "Misc.h"
#include "ActionListener.h"
#include "PlusActionListener.h"
#include <iostream>
using namespace std;

// ������.
MyButton::MyButton(){}

MyButton::MyButton(string s, View * v) :Component(s,v){}


// ��ư�� �׸��� �Լ�.
void MyButton::draw() {
	SIZE size;
	
	size = m_v->textSize(m_name);
	m_v->drawRectangle(Start_x, Start_y, End_x, End_y);
	m_v->drawText(m_name, Start_x + End_x / 2 - (size.cx / 2), Start_y + End_y / 2 - (size.cy / 2));
}


// ���콺 Ŀ���� ��ư ���� ���� �� ��� ������ ȸ������ ���ϰ� �ϴ� �Լ�.
void MyButton::onMouse() {
	Component::onMouse();
}

void MyButton::addActionListener(ActionListener* l) {
	m_Actionlist.push_back(l);
}
void MyButton::mouseClick() {
	for (auto i : m_Actionlist) {
		i->actionPerformed(this);
		debugOutput("!!!ActionListener!!!\n");
	}
}