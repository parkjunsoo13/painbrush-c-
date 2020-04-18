#pragma once
#include "stdafx.h"

class Event {

public:

	int x, y; // xÁÂÇ¥ yÁÂÇ¥
	long E_wParam ; // wParam 
	bool ctrlPressed();
	bool shiftPressed();

};