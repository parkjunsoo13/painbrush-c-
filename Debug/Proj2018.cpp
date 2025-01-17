// Proj2018.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Proj2018.h"
#include "string"
#include "View.h"
#include "Misc.h"
#include "myview.h"
#include "component.h"
#include "container.h"
 
// MS의 해괴한 구조 때문에 전역변수를 어쩔 수 없이 쓴다.
// external static 으로서 다른 파일에서 사용할 수 없게 한다.
static View * mainView = NULL;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다: (자동 생성 코드)
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

  
	// by 조세형 2018.10.27
	mainView = new MyView(hInstance); // MyView.
	mainView->initInstance(nCmdShow);
    // 응용 프로그램 초기화를 수행합니다:
 
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJ2018));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	int x = LOWORD(lParam);
	int y = HIWORD(lParam); 
	
	Event e(wParam, x, y); // 지역변수로 선언.

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                //DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			if (mainView) {
				mainView->redrawAll();
			}
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_MOUSEMOVE:
		mainView->OnMouseMove(e);
		break;
	case WM_LBUTTONDOWN:
		mainView->OnLButtonDown(e);
		break;
	case WM_LBUTTONUP:
		mainView->OnLButtonUp(e);
		break;
	case WM_RBUTTONDOWN:
		mainView->OnRButtonDown(e);
		break;
	case WM_CHAR:
		{
			RECT r = mainView->getClientRect();
			debugOutput(r.right - r.left); debugOutput(r.bottom - r.top);
			mainView->drawLine(r.left, r.top, r.right-5, r.bottom-5);
			break;
		}
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
	
}

// 정보 대화 상자의 메시지 처리기입니다.
/*
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
*/
