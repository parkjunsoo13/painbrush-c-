#include "stdafx.h"
#include "container.h"
#include "component.h"
#include <string>
using namespace std;


// Constructor.
Container::Container() :Component() {

}

Container::Container(string s, View * v) :Component(s, v) {}

// Component add function.
void Container::addComponent(Component *c, View *v) {
	m_v = v;
	CList.push_back(c);
}

// draw().
void Container::draw() {

	for (list<Component *>::iterator c = CList.begin(); c != CList.end(); c++) {
		
		(*c)->draw();
		
	}
}

Component* Container::find(Event e) {
	list<Component *>::iterator c;
	for (c = CList.begin(); c != CList.end(); c++) {
		if ((*c)->Click_Check(e.x, e.y)) {
			m_ButtonPoint = (*c);
			break;
		}
	}

	return m_ButtonPoint;
}

