#pragma once
#include "container.h"

class Menu;
class MenuItem;

class Menubar :public Container {
protected:
	int menuNum = 0; // 메뉴 수 변수.
public:
	Menubar();
	void addComponent(Component *c, View *v);
	void draw();
	void OnMouseMove(Event e);
	void OnLButtonDown(Event e);
	bool isOnMenubar(Event e);
	Component *find(Event e);
	bool ButtonOn(Event e);
};

