#pragma once
class View;
class CEllipse : public Figure { // ���� ������ ����ִ� Ŭ����
public:
	CEllipse(int S_x, int S_y, int E_x, int E_y, View *v);
	virtual void Draw();
};