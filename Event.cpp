#include "stdafx.h"
#include "Event.h"

bool Event::ctrlPressed(){ // control�� ���������� �Ǻ�

	if (E_wParam & MK_CONTROL) {
		return 1;
	}
	else
		return 0;

}
bool Event::shiftPressed(){ //Shift�� ���������� �Ǻ�

	if (E_wParam & MK_SHIFT) {
		return 1;
	}
	else
		return 0;

}