#pragma once
#include "component.h"
#include <iostream>
#include <list>
using namespace std;

class View;
class ActionListener;
class MyButton :public Component{
protected:
	list<ActionListener*> m_Actionlist;
public:
	
	MyButton();
	MyButton(string s, View *v);
	virtual void draw();
	void onMouse();
	virtual void addActionListener(ActionListener * l);
	virtual void mouseClick();

};