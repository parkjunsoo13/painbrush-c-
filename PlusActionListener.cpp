#include "stdafx.h"
#include "PlusActionListener.h"
#include "ActionListener.h"
#include "MyView.h"


PlusActionListener::PlusActionListener(MyView* p) {
	m_p = p;//MyView변수를 받는다.
}
void PlusActionListener::actionPerformed(Component *p) {
	m_p->SomethingAction(p);//도형을 그리는 경우에대한 조건이 들어있는 함수를 호출해준다.
}
