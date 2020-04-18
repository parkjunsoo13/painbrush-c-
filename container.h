#pragma once
#include "component.h"
#include "Misc.h"
#include <list>
using namespace std;

// Component를 상속받는 Container 클래스. Component들을 포함하는 list를 가지고 있다.
class Container :public Component {
protected:
	list<Component *> CList; // 컴포넌트 리스트.
	Component *m_ButtonPoint = 0; // 버튼 포인터.
public:
	Container();
	Container(string s, View *v);

	virtual void addComponent(Component *, View *);
	virtual Component *find(Event e);
	void draw();
};

