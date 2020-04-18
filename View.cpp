#include "stdafx.h"
#include "View.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "Misc.h"
#include "figure.h"
#include "ellip.h"
#include "line.h"
#include "rect.h"
#include "mybutton.h"
#include "toolbar.h"
#include "tbutton.h"
#include "menubar.h"
#include "menu.h"
#include <list>
using namespace std;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);  // Prototype to external fun

//
//  �Լ�: MyRegisterClass()
//
//  �뵵: â Ŭ������ ����մϴ�.
//
ATOM View::MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJ2018));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL; //  MAKEINTRESOURCEW(IDC_PROJ2018);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

View::View(HINSTANCE hInstance):m_InstanceHandle(hInstance) {
	m_InstanceHandle = hInstance;
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_PROJ2018, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
}
View::View(HWND w):m_WindowHandle(w)
{
	m_DCHandle = ::GetDC(w);
	onInitialize();
}

View::~View()
{

}

BOOL View::initInstance( int nCmdShow)
{
	//m_InstanceHandle = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

	m_WindowHandle = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_InstanceHandle, nullptr);

	if (!m_WindowHandle)
	{
		return FALSE;
	}

	ShowWindow(m_WindowHandle, nCmdShow);
	UpdateWindow(m_WindowHandle);
	m_DCHandle = ::GetDC(m_WindowHandle);
	onInitialize();
	//mainView = new View(hWnd);

	return TRUE;
}

// ���콺�� ������ ���� ó���ϴ� �Լ�.
void View::OnMouseMove(Event e) {
	// ���ٿ����� MouseMove �Լ� ����.
	if (FileMenuOn != 1 && FigureMenuOn != 1) {
		m_ToolBar->OnMouseMove(e);
	}
	m_MenuBar->OnMouseMove(e);

}

void View::OnLButtonDown(Event e)
{
	// ��������� ��ǥ�� ����صд�.
	Start_x = e.x;
	Start_y = e.y;
	
	// LButtonDown �������� �Լ� ó��.
	m_ToolBar->OnLButtonDown(e);
	m_MenuBar->OnLButtonDown(e);
}

void View::OnLButtonUp(Event e)
{
	End_x = e.x;
	End_y = e.y;


	OnMouseButton = m_MenuBar->ButtonOn(e);
	m_mb = m_MenuBar->find(e); 

	if (FileMenuOn == 1) { // ���� �޴��� �������� ��
		m_mi = m_fileMenu->find(e); // Ŭ���� ��ư find.
		OnMouseMenuItem = true; 
	}
	else if (FigureMenuOn == 1) { // ���� �޴��� �������� ��
		m_mi = m_figureMenu->find(e); // Ŭ���� ��ư find.
		OnMouseMenuItem = true;
	}
	else if (m_ToolBar->ButtonClick(e)) { // ���� ��ư Ŭ������ ��
		m_ToolButton = m_ToolBar->find(e); // Ŭ���� ��ư find.
		OnMouseMenuItem = false;
	}
	
	if (m_mb == 0) {
		return;
	}
	else {

		if (m_mb->getName() == "����") { // ���� �޴� Ŭ����.
			
			FileMenuOn++;
			m_fileMenu->setCheckName(1);
			m_fileMenu->draw(); // ���� �޴�������â ����.
			FigureMenuOn = 0;

			if (FileMenuOn == 2) { // �������·� Ŭ���ϰų� �ٸ����� Ŭ���� �޴�������â ����.
				m_fileMenu->setCheckName(0);
				m_fileMenu->CloseMenu();
				FileMenuOn = 0;
			}
			if (OnMouseButton == false) {
				m_fileMenu->setCheckName(0);
				m_fileMenu->CloseMenu();
				FigureMenuOn = 0;
			}

			
		}
		else if (m_mb->getName() == "����") { // ���� �޴� Ŭ����.
			
			FigureMenuOn++;
			m_figureMenu->setCheckName(2);
			m_figureMenu->draw(); // ���� �޴�������â ����.
			FileMenuOn = 0;

			if (FigureMenuOn == 2) { // �������·� Ŭ���ϰų� �ٸ����� Ŭ���� �޴�������â ����.
				m_figureMenu->setCheckName(0);
				m_figureMenu->CloseMenu();
				FigureMenuOn = 0;
			}
			if (OnMouseButton == false) {
				m_figureMenu->setCheckName(0);
				m_figureMenu->CloseMenu();
				FigureMenuOn = 0;
			}
			
		}
		if (m_mb->getName() != "����") { 
			m_fileMenu->setCheckName(0);
			m_fileMenu->CloseMenu();
		}
		if (m_mb->getName() != "����") {
			m_figureMenu->setCheckName(0);
			m_figureMenu->CloseMenu();
		}
	}
	
}

void View::OnRButtonDown(Event e){}

// long wParam, int x, int y
void View::OnRButtonUp(Event e){}

void View::OnChar(long ch)
{
	// Ű���� �Է��� �Ǹ� �� �Լ��� �ڵ� ȣ��˴ϴ�.  cin�̳� getchar, scanf ����
	// ǥ�� �Է��Լ��� �۵����� ������ onchar �� �� �̿��ؾ� �մϴ�.


}

// ������ ���� �����ϱ�
void View::setPenColor(COLORREF color)
{
	thePen = CreatePen(PS_SOLID, 1, color);
	SelectObject(m_DCHandle, thePen);
}

// ���� ���� �β��� ���ÿ� �����ϱ�
void View::setPen(COLORREF color, int width)
{
	thePen = CreatePen(PS_SOLID, width, color);
	SelectObject(m_DCHandle, thePen);
}

// ä�� ���� �����ϴ� �Լ�.
void View::setFillColor(COLORREF color)
{
	theBrush = CreateSolidBrush(color);
	SelectObject(m_DCHandle, theBrush);
}

// ���� ���� �����ϴ� �Լ�.
void View::setTextColor(COLORREF color)
{
	SetTextColor(m_DCHandle, color);
}


void View::drawRectangle(int x, int y, int sizeX, int sizeY)
{
	Rectangle(m_DCHandle, x, y, x + sizeX, y + sizeY);
}

void View::drawEllipse(int x, int y, int sizeX, int sizeY)
{
	Ellipse(m_DCHandle, x, y, x + sizeX, y + sizeY);
}

void View::drawLine(int x, int y, int sizeX, int sizeY)
{
	MoveToEx(m_DCHandle, x, y, NULL);
	LineTo(m_DCHandle, x + sizeX, y + sizeY);
}


void View::drawText(std::string str, int x, int y)
{
	TextOutA(m_DCHandle, x, y, str.c_str(), strlen(str.c_str()));
}

// ���  ���빰���� �ٽ� �׷��ִ� �Լ�.  ������ �ʿ��� ���̴�.
void View::redrawAll()
{
}

// ȭ���� ���� ����� �ȵǾ� �ִٰ� �˸��� �Լ��Դϴ�.
// �� �Լ��� ȣ���ϸ� ȭ���� �������� 
// Main.cpp �ʿ� case WM_PAINT: �κ��� ����˴ϴ�.
// �ᱹ�� View ��ü�� display�� ����ǰ���.
void View::invalidate()
{
	InvalidateRect(m_WindowHandle, NULL, true);
}

// ��� �������� onInitialize �Լ����� �ʱ�ȭ����.
void View::onInitialize()
{
	
	// ���� ����.
	m_ToolBar = new Toolbar();
	// �޴��� ����.
	m_MenuBar = new Menubar();

	m_fileMenu = new Menu("����", this);
	m_figureMenu = new Menu("����", this);
}

// �簢�� ��ġ�� �����.
void View::eraseRect(int x, int y, int   sizeX, int  sizeY) // �»�� x y �׸��� x�� y�� ũ��
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	setPenColor(RGB(255, 255, 255));
	setFillColor(RGB(255, 255, 255));
	drawRectangle(x, y, sizeX, sizeY);
}

// ������ ��ġ�� �����ش�.
RECT View::getClientRect()   // RECT���� left, right, top, bottom �� �ִ�.
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	RECT r;
	GetClientRect(m_WindowHandle, &r);
	return r;
}

SIZE View::textSize(const std::string text)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	SIZE size;
	const char *s = text.c_str();
	GetTextExtentPoint32A(m_DCHandle, s, strlen(s), &size);
	return size;
}

void View::setTextBkColor(COLORREF color)
{
	SetBkColor(m_DCHandle, color);
}

int View::getWindowWidth() {
	RECT r;
	GetWindowRect(m_WindowHandle, &r);
	return r.right - r.left;
}