#pragma once
#include "iostream"
#include "Proj2018.h"
#include "Misc.h"
#include "container.h"
#include <list>
using namespace std;
#define MAX_LOADSTRING 100

// forward declaration.
class Figure;
class MyButton;
class Toolbar;
class Menubar;
class Menu;

class View :public Container
{
protected:
	
	Toolbar *m_ToolBar; // ToolBar ������
	Menubar *m_MenuBar; // MenuBar ������
	Component *m_mb = 0; 
	Menu *m_figureMenu; 
	Menu *m_fileMenu;
	Component *m_mi = 0; // �޴� ������ ������
	Component *m_ToolButton= 0; // ToolBarButton ������
	int FileMenuOn = 0;
	int FigureMenuOn = 0;
	bool OnMouseButton = false;
	bool OnMouseMenuItem = false;
	bool close = false;
public:
	View(HINSTANCE);
	View(HWND);
	~View();
protected:
	HWND m_WindowHandle;    //  ���� ���� handle
	HDC m_DCHandle;	// DC handle
	HBRUSH brushWhite, brushBlack;
	HPEN penWhite, penBlack;
	// �ӽ� ����
	int count = 0;
	HPEN thePen;
	HBRUSH theBrush;
	HINSTANCE m_InstanceHandle;
	WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
	WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

public:
	// �ʱ�ȭ �Լ���
	ATOM MyRegisterClass(HINSTANCE hInstance);
	BOOL initInstance(/*HINSTANCE hInstance, */int nCmdShow);

	virtual void OnLButtonDown(Event e);
	virtual void OnLButtonUp(Event e);
	virtual void OnRButtonDown(Event e);
	virtual void OnRButtonUp(Event e);
	virtual void OnChar(long ch);
	virtual void OnMouseMove(Event e);

	void setPenColor(COLORREF color);         
	void setPen(COLORREF color, int width);  
	void setFillColor(COLORREF color);
	void setTextColor(COLORREF color);
	void setTextBkColor(COLORREF color);
 
	void drawRectangle(int x, int y, int sizeX, int sizeY);
	void drawEllipse(int x, int y, int sizeX, int sizeY);
	void drawLine(int x, int y, int sizeX, int sizeY);
	void drawText(std::string str, int x, int y);
	virtual void redrawAll(); // ����� ���� ����.
	void invalidate();
	virtual void onInitialize(); // ����� ���� ����.
	SIZE textSize(const std::string text);
	int getWindowWidth();

protected:

public:

	void eraseRect(int x, int y, int sizeX, int sizeY);
	RECT getClientRect();
};

