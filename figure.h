#pragma once

class View;  // forward declaration.

// 도형 클래스.
class Figure {
protected:
	View *m_v; // View 포인터.
	int m_x, m_y, m_sizeX, m_sizeY; // 좌표정보 변수.
	int n;
public:
	Figure(int x, int y, int sizeX, int sizeY, int n, View *v); // 생성자.
	virtual void draw(); // 도형을 그리는 가상함수.
	int Type();
	int GetSx();
	int GetSy();
	int GetEx();
	int GetEy();
};

