#pragma once
#include "mybutton.h"

class View;

// MyButton �� ��ӹ޴� ���� ��ư Ŭ����.
class TButton:public MyButton {
public:
	TButton(string s, View *v);
	~TButton();
	void draw();
	//void setSize(int x, int y, int sizeX, int sizeY);
	//bool check = FALSE; // ���콺�� ��ư ���� �ִ��� üũ���ִ� ����. FALSE�� �ʱ�ȭ.
};

