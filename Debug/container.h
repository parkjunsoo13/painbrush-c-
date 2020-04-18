#pragma once
#include "component.h"
#include "Misc.h"
#include <list>
using namespace std;

// Component�� ��ӹ޴� Container Ŭ����. Component���� �����ϴ� list�� ������ �ִ�.
class Container :public Component {
protected:
	list<Component *> CList; // ������Ʈ ����Ʈ.
	Component *m_ButtonPoint = 0; // ��ư ������.
public:
	Container();
	Container(string s, View *v);

	virtual void addComponent(Component *, View *);
	virtual Component *find(Event e);
	void draw();
};

