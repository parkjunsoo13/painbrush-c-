#pragma once
#include "mybutton.h"

class View;

// MyButton 을 상속받는 툴바 버튼 클래스.
class TButton:public MyButton {
public:
	TButton(string s, View *v);
	~TButton();
	void draw();
	//void setSize(int x, int y, int sizeX, int sizeY);
	//bool check = FALSE; // 마우스가 버튼 위에 있는지 체크해주는 변수. FALSE로 초기화.
};

