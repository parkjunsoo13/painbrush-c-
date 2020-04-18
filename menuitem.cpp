#include "stdafx.h"
#include "menuitem.h"
#include "View.h"


MenuItem::MenuItem() {}

MenuItem::MenuItem(string s, View * v) :MyButton(s, v) {}

void MenuItem::draw() {
	MyButton::draw();
}
void MenuItem::addActionListener(ActionListener* l) {
	MyButton::addActionListener(l);
}
void MenuItem::mouseClick() {
	MyButton::mouseClick();
}