#pragma once
#include "stdafx.h"

class Event {

public:

	int x, y; // x��ǥ y��ǥ
	long E_wParam ; // wParam 
	bool ctrlPressed();
	bool shiftPressed();

};