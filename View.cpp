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
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
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
	//m_InstanceHandle = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

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

// 마우스가 움직일 때를 처리하는 함수.
void View::OnMouseMove(Event e) {
	// 툴바에서의 MouseMove 함수 실행.
	if (FileMenuOn != 1 && FigureMenuOn != 1) {
		m_ToolBar->OnMouseMove(e);
	}
	m_MenuBar->OnMouseMove(e);

}

void View::OnLButtonDown(Event e)
{
	// 멤버변수에 좌표를 기억해둔다.
	Start_x = e.x;
	Start_y = e.y;
	
	// LButtonDown 했을때의 함수 처리.
	m_ToolBar->OnLButtonDown(e);
	m_MenuBar->OnLButtonDown(e);
}

void View::OnLButtonUp(Event e)
{
	End_x = e.x;
	End_y = e.y;


	OnMouseButton = m_MenuBar->ButtonOn(e);
	m_mb = m_MenuBar->find(e); 

	if (FileMenuOn == 1) { // 파일 메뉴가 열려있을 때
		m_mi = m_fileMenu->find(e); // 클릭한 버튼 find.
		OnMouseMenuItem = true; 
	}
	else if (FigureMenuOn == 1) { // 도형 메뉴가 열려있을 때
		m_mi = m_figureMenu->find(e); // 클릭한 버튼 find.
		OnMouseMenuItem = true;
	}
	else if (m_ToolBar->ButtonClick(e)) { // 툴바 버튼 클릭했을 때
		m_ToolButton = m_ToolBar->find(e); // 클릭한 버튼 find.
		OnMouseMenuItem = false;
	}
	
	if (m_mb == 0) {
		return;
	}
	else {

		if (m_mb->getName() == "파일") { // 파일 메뉴 클릭시.
			
			FileMenuOn++;
			m_fileMenu->setCheckName(1);
			m_fileMenu->draw(); // 파일 메뉴아이템창 열림.
			FigureMenuOn = 0;

			if (FileMenuOn == 2) { // 열린상태로 클릭하거나 다른곳을 클릭시 메뉴아이템창 닫음.
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
		else if (m_mb->getName() == "도형") { // 도형 메뉴 클릭시.
			
			FigureMenuOn++;
			m_figureMenu->setCheckName(2);
			m_figureMenu->draw(); // 도형 메뉴아이템창 열림.
			FileMenuOn = 0;

			if (FigureMenuOn == 2) { // 열린상태로 클릭하거나 다른곳을 클릭시 메뉴아이템창 닫음.
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
		if (m_mb->getName() != "파일") { 
			m_fileMenu->setCheckName(0);
			m_fileMenu->CloseMenu();
		}
		if (m_mb->getName() != "도형") {
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
	// 키보드 입력이 되면 이 함수가 자동 호출됩니다.  cin이나 getchar, scanf 같은
	// 표준 입력함수는 작동하지 않으니 onchar 를 잘 이용해야 합니다.


}

// 라인의 색을 지정하기
void View::setPenColor(COLORREF color)
{
	thePen = CreatePen(PS_SOLID, 1, color);
	SelectObject(m_DCHandle, thePen);
}

// 선의 색과 두께를 동시에 지정하기
void View::setPen(COLORREF color, int width)
{
	thePen = CreatePen(PS_SOLID, width, color);
	SelectObject(m_DCHandle, thePen);
}

// 채움 색을 결정하는 함수.
void View::setFillColor(COLORREF color)
{
	theBrush = CreateSolidBrush(color);
	SelectObject(m_DCHandle, theBrush);
}

// 글자 색을 지정하는 함수.
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

// 모든  내용물들을 다시 그려주는 함수.  수정이 필요할 것이다.
void View::redrawAll()
{
}

// 화면이 현재 제대로 안되어 있다고 알리는 함수입니다.
// 이 함수를 호출하면 화면이 지워지고 
// Main.cpp 쪽에 case WM_PAINT: 부분이 실행됩니다.
// 결국은 View 객체의 display가 실행되겠죠.
void View::invalidate()
{
	InvalidateRect(m_WindowHandle, NULL, true);
}

// 모든 윈도들을 onInitialize 함수에서 초기화하자.
void View::onInitialize()
{
	
	// 툴바 생성.
	m_ToolBar = new Toolbar();
	// 메뉴바 생성.
	m_MenuBar = new Menubar();

	m_fileMenu = new Menu("파일", this);
	m_figureMenu = new Menu("도형", this);
}

// 사각형 위치를 지운다.
void View::eraseRect(int x, int y, int   sizeX, int  sizeY) // 좌상귀 x y 그리고 x축 y축 크기
{
	// TODO: 여기에 구현 코드 추가.
	setPenColor(RGB(255, 255, 255));
	setFillColor(RGB(255, 255, 255));
	drawRectangle(x, y, sizeX, sizeY);
}

// 윈도의 위치를 돌려준다.
RECT View::getClientRect()   // RECT에는 left, right, top, bottom 이 있다.
{
	// TODO: 여기에 구현 코드 추가.
	RECT r;
	GetClientRect(m_WindowHandle, &r);
	return r;
}

SIZE View::textSize(const std::string text)
{
	// TODO: 여기에 구현 코드 추가.
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