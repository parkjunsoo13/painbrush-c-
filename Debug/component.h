#pragma once
#include <string>
using namespace std;
class View;

class ActionListener;
class Component {
protected:
	int Start_x, Start_y, End_x, End_y; // 버튼의 좌표 변수.
	View *m_v; // 뷰 포인터.
	string m_name; // 이름 변수.
	bool isOn = false; // 상태 변수.
public:
	Component();
	Component(string s, View *v);

	bool check = false; // 마우스가 버튼 위에 있는지 체크해주는 변수. FALSE로 초기화.
	bool on = false;
	bool Click_Check(int x, int y);

	string getName();
	void setSize(int x, int y, int sizeX, int sizeY);
	virtual void onMouse();
	virtual void draw();
	virtual void addActionListener(ActionListener *l);
	virtual void mouseClick();
	
};
