#include "stdafx.h"
#include "PlusActionListener.h"
#include "ActionListener.h"
#include "MyView.h"


PlusActionListener::PlusActionListener(MyView* p) {
	m_p = p;//MyView������ �޴´�.
}
void PlusActionListener::actionPerformed(Component *p) {
	m_p->SomethingAction(p);//������ �׸��� ��쿡���� ������ ����ִ� �Լ��� ȣ�����ش�.
}
