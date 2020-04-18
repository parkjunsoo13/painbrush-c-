#pragma once
class View;
class CEllipse : public Figure { // 원의 정보를 담고있는 클래스
public:
	CEllipse(int S_x, int S_y, int E_x, int E_y, View *v);
	virtual void Draw();
};