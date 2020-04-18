#include "stdafx.h"
#include "mybutton.h"
#include "View.h"
#include "Misc.h"
#include "ActionListener.h"
#include "PlusActionListener.h"
#include <iostream>
using namespace std;

// 생성자.
MyButton::MyButton(){}

MyButton::MyButton(string s, View * v) :Component(s,v){}


// 버튼을 그리는 함수.
void MyButton::draw() {
	SIZE size;
	
	size = m_v->textSize(m_name);
	m_v->drawRectangle(Start_x, Start_y, End_x, End_y);
	m_v->drawText(m_name, Start_x + End_x / 2 - (size.cx / 2), Start_y + End_y / 2 - (size.cy / 2));
}


// 마우스 커서가 버튼 위에 있을 때 배경 색깔이 회색으로 변하게 하는 함수.
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