#pragma once
#include "mybutton.h"
#include <list>
using namespace std;

class MenuItem :public MyButton {
public:
	MenuItem();
	MenuItem(string s, View *v);
	void draw();
	void addActionListener(ActionListener * l);
	void mouseClick();
	
};

