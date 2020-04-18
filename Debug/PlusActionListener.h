#pragma once
#include "ActionListener.h"
class MyView;
class Component;
class PlusActionListener : public ActionListener 
{
public:
	PlusActionListener(MyView* p);
	void actionPerformed(Component *p);
private:
	MyView* m_p = 0;
};
