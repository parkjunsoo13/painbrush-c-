#pragma once
#include <string>
using namespace std;
class View;

class ActionListener;
class Component {
protected:
	int Start_x, Start_y, End_x, End_y; // ��ư�� ��ǥ ����.
	View *m_v; // �� ������.
	string m_name; // �̸� ����.
	bool isOn = false; // ���� ����.
public:
	Component();
	Component(string s, View *v);

	bool check = false; // ���콺�� ��ư ���� �ִ��� üũ���ִ� ����. FALSE�� �ʱ�ȭ.
	bool on = false;
	bool Click_Check(int x, int y);

	string getName();
	void setSize(int x, int y, int sizeX, int sizeY);
	virtual void onMouse();
	virtual void draw();
	virtual void addActionListener(ActionListener *l);
	virtual void mouseClick();
	
};
