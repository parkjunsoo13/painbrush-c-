#include "stdafx.h"
#include "Event.h"

bool Event::ctrlPressed(){ // control이 눌러졌을때 판별

	if (E_wParam & MK_CONTROL) {
		return 1;
	}
	else
		return 0;

}
bool Event::shiftPressed(){ //Shift가 눌러졌을때 판별

	if (E_wParam & MK_SHIFT) {
		return 1;
	}
	else
		return 0;

}