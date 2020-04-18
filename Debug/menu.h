#pragma once
#include "container.h"

class Menubar;

class Menu :public Container {
protected:
	int itemNum = 0;
	int CheckName;
public:
	Menu();
	Menu(string s,View *v);
	Component *find(Event e);
	void addComponent(Component *c, View *v);
	void OnLButtonDown(Event e);
	void setCheckName(int s);
	void CloseMenu();
	void onMouse();
	void draw();
};

