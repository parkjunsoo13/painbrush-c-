#pragma once
#include "container.h"
#include <list>
using namespace std;

class TButton;
class View;
class Event;

// Toolbar Ŭ����.
class Toolbar :public Container {
protected:
	int btnNum = 0; // ��ư �� ����.
	int decideL;
public:
	Toolbar();
	void addComponent(Component *c, View *);
	void draw();
	void OnMouseMove(Event e);
	bool decideLine(Event e);
	void OnLButtonDown(Event e);
	bool ButtonClick(Event e);
	bool isOnToolbar(Event e);
	Component *find(Event e);
};

