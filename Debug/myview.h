#pragma once
#include "iostream"
#include "Proj2018.h"
#include "Misc.h"
#include "View.h"
#include "ActionListener.h"
#include <list>
using namespace std;

// View를 상속받는 MyView 클래스.
class MyView :public View, ActionListener{
protected:
	list<Figure *> mList; // Figure list.
public:
	MyView(HINSTANCE);
	MyView(HWND);
	~MyView();
	void OnLButtonDown(Event e);
	void OnLButtonUp(Event e);
	void OnRButtonDown(Event e);
	void OnRButtonUp(Event e);
	void OnChar(long ch);
	void OnMouseMove(Event e);
	void redrawAll();
	void onInitialize();
	void actionPerformed(Component * p);
	void SomethingAction(Component *p);
};

