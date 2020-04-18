#pragma once

class View;  // forward declaration.

// ���� Ŭ����.
class Figure {
protected:
	View *m_v; // View ������.
	int m_x, m_y, m_sizeX, m_sizeY; // ��ǥ���� ����.
	int n;
public:
	Figure(int x, int y, int sizeX, int sizeY, int n, View *v); // ������.
	virtual void draw(); // ������ �׸��� �����Լ�.
	int Type();
	int GetSx();
	int GetSy();
	int GetEx();
	int GetEy();
};

