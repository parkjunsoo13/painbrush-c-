#include "stdafx.h"
#include "myview.h"
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
#include "menuitem.h"
#include <list>
#include "ActionListener.h"
#include "PlusActionListener.h"
#include <fstream> 
using namespace std;

// ������.
MyView::MyView(HINSTANCE hInstance):View(hInstance) {}

MyView::MyView(HWND w):View(w) {}

// �Ҹ���.
MyView::~MyView() {}

// LButtonDown ���� �Լ�.
void MyView::OnLButtonDown(Event e) {
	View::OnLButtonDown(e);

}

// LButtonUp ���� �Լ�.
void MyView::OnLButtonUp(Event e) {
	View::OnLButtonUp(e);
	
	if (m_mi) {
		m_mi->mouseClick();//actionPerformed�� �����ϴ� �Լ��̴�.
	}

	if (m_mi) {
		m_mi->mouseClick();//actionPerformed�� �����ϴ� �Լ��̴�.
	}
	//�׸��� ȸ���� ������ �׸��� �� ��� ��������ش�.
	if (m_ToolBar->decideLine(e)) {
		return;
	}
	if (m_ToolButton) {
		m_ToolButton->mouseClick();//actionPerformed�� �����ϴ� �Լ��̴�.
	}

	//if (close == true)
		//return;

	invalidate();

	/*if (m_ToolBar->isOnToolbar(e)) {
		return;
	}

	if (m_MenuBar->isOnMenubar(e)) {
		return;
	}
	
	if (m_mi && OnMouseMenuItem == true) {
		if (m_mi->getName() == "����") // ���� ��ư Ŭ������ ��.
			debugOutput("����");
		else if (m_mi->getName() == "����") // ���� ��ư Ŭ������ ��.
			debugOutput("����");
		else if (m_mi->getName() == "����") // ���� ��ư�� Ŭ������ ��.
			mList.push_back(new Line(Start_x, Start_y, End_x - Start_x, End_y - Start_y, this));
		else if (m_mi->getName() == "Ÿ��") // Ÿ�� ��ư�� Ŭ������ ��.
			mList.push_back(new Ellip(Start_x, Start_y, End_x - Start_x, End_y - Start_y, this));
		else if (m_mi->getName() == "�簢��") // �簢�� ��ư�� Ŭ������ ��.
			mList.push_back(new Rect(Start_x, Start_y, End_x - Start_x, End_y - Start_y, this));
		invalidate(); // ȭ�鿡 ǥ�õǵ��� ��.
	}



	if (m_ToolButton && OnMouseMenuItem == false) {
		if (m_ToolButton->getName() == "L") // ���� ��ư�� Ŭ������ ��.
			mList.push_back(new Line(Start_x, Start_y, End_x - Start_x, End_y - Start_y, this));
		else if (m_ToolButton->getName() == "E") // Ÿ�� ��ư�� Ŭ������ ��.
			mList.push_back(new Ellip(Start_x, Start_y, End_x - Start_x, End_y - Start_y, this));
		else if (m_ToolButton->getName() == "R") // �簢�� ��ư�� Ŭ������ ��.
			mList.push_back(new Rect(Start_x, Start_y, End_x - Start_x, End_y - Start_y, this));
		invalidate(); // ȭ�鿡 ǥ�õǵ��� ��.
	}
*/
}

void MyView::OnRButtonDown(Event e) {

}

void MyView::OnRButtonUp(Event e) {

}

void MyView::OnChar(long ch) {

}

// ���  ���빰���� �ٽ� �׷��ִ� �Լ�.
void MyView::OnMouseMove(Event e) {
	View::OnMouseMove(e); // View�� OnMouseMove�Լ� ����.
}

// 
void MyView::redrawAll() {

	list<Figure *>::iterator i;
	for (i = mList.begin(); i != mList.end(); i++) {
		(*i)->draw();
	}

	
	if (m_ToolBar) {
		m_ToolBar->draw();
	}
	if (m_MenuBar) {
		m_MenuBar->draw();
	}
	View::redrawAll(); 
}

void MyView::onInitialize() {
	View::onInitialize(); // View�� OnInitialize�Լ� ����.
	PlusActionListener *m_p = new PlusActionListener(this);

	TButton *RECT = new TButton("R", this);
	TButton *Elipse = new TButton("E", this);
	TButton *Line = new TButton("L", this);

	RECT->addActionListener(m_p);
	Elipse->addActionListener(m_p);
	Line->addActionListener(m_p);

	m_ToolBar->addComponent(RECT, this);
	m_ToolBar->addComponent(Elipse, this);
	m_ToolBar->addComponent(Line, this);
	//m_ToolBar->addComponent(new TButton("R", this), this);
	//m_ToolBar->addComponent(new TButton("E", this), this);
	//m_ToolBar->addComponent(new TButton("L", this), this);
	m_MenuBar->addComponent(m_fileMenu, this);
	m_MenuBar->addComponent(m_figureMenu, this);

	MenuItem *sa = new MenuItem("����", this);
	MenuItem *op = new MenuItem("����", this);
	
	sa->addActionListener(this);
	op->addActionListener(this);

	m_fileMenu->addComponent(sa, this);
	m_fileMenu->addComponent(op, this);


	MenuItem *m_r = new MenuItem("�簢��", this);
	MenuItem *m_e = new MenuItem("Ÿ��", this);
	MenuItem *m_l = new MenuItem("����", this);

	m_r->addActionListener(m_p);
	m_e->addActionListener(m_p);
	m_l->addActionListener(m_p);

	m_figureMenu->addComponent(m_r, this);
	m_figureMenu->addComponent(m_e, this);
	m_figureMenu->addComponent(m_l, this);

	/*m_fileMenu = new Menu("����", this);
	m_figureMenu = new Menu("����", this);

	

	m_fileMenu->addComponent(new MenuItem("����", this), this);
	m_fileMenu->addComponent(new MenuItem("����", this), this);

	m_figureMenu->addComponent(new MenuItem("�簢��", this), this);
	m_figureMenu->addComponent(new MenuItem("Ÿ��", this), this);
	m_figureMenu->addComponent(new MenuItem("����", this), this);*/

	invalidate(); // ȭ�鿡 ǥ�õǵ��� ��.
}
void MyView::actionPerformed(Component * p) {
	//���� �޴��� �������� ���� ���⿡ ���� �ൿ�� �Ѵ�.
	int n;
	if (m_mi && OnMouseMenuItem == true) {
		if (p->getName() == "����") {
			debugOutput("����");

			
			ofstream a_file("save.txt");
			list<Figure *>::iterator i;
			for (i = mList.begin(); i != mList.end(); i++) {
				
				if ((*i)->Type() == 1) {
					a_file << "1 ";
					a_file << (*i)->GetSx() << " ";
					a_file << (*i)->GetSy() << " ";
					a_file << (*i)->GetEx() << " ";
					a_file << (*i)->GetEy() << "\n";

				}
				else if ((*i)->Type() == 2) {
					a_file << "2 ";
					a_file << (*i)->GetSx() << " ";
					a_file << (*i)->GetSy() << " ";
					a_file << (*i)->GetEx() << " ";
					a_file << (*i)->GetEy() << "\n";
				}
				else {
					a_file << "3 ";
					a_file << (*i)->GetSx() << " ";
					a_file << (*i)->GetSy() << " ";
					a_file << (*i)->GetEx() << " ";
					a_file << (*i)->GetEy() << "\n";
				}
			}
			
			a_file.close();
		}
		else if (p->getName() == "����") {
			ifstream b_file("save.txt");
			while (b_file) { 

				int Sx, Sy, Ex, Ey, t;

				b_file >> t >> Sx >> Sy >> Ex >> Ey ;

				if (t == 1 ) {
					mList.push_back(new Line(Sx, Sy, Ex, Ey, 1, this));
				}
				else if (t == 2)
				{
					mList.push_back(new Ellip(Sx, Sy, Ex, Ey, 2, this));
				}
				else
					mList.push_back(new Rect(Sx, Sy, Ex, Ey, 3, this));

			}
			invalidate();
			b_file.close();

		}
	}

}

void MyView::SomethingAction(Component *p) {

	if (m_mi && OnMouseMenuItem == true) {
		
		if (m_mi->getName() == "����") // ���� ��ư�� Ŭ������ ��.
			mList.push_back(new Line(Start_x, Start_y, End_x - Start_x, End_y - Start_y,1, this));
		else if (m_mi->getName() == "Ÿ��") // Ÿ�� ��ư�� Ŭ������ ��.
			mList.push_back(new Ellip(Start_x, Start_y, End_x - Start_x, End_y - Start_y,2, this));
		else if (m_mi->getName() == "�簢��") // �簢�� ��ư�� Ŭ������ ��.
			mList.push_back(new Rect(Start_x, Start_y, End_x - Start_x, End_y - Start_y,3, this));
		invalidate(); // ȭ�鿡 ǥ�õǵ��� ��.
	}
	if (m_ToolButton == 0) {
		close = true;
		return;
	}

	if (m_ToolButton && OnMouseMenuItem == false) {
		if (m_ToolButton->getName() == "L") // ���� ��ư�� Ŭ������ ��.
			mList.push_back(new Line(Start_x, Start_y, End_x - Start_x, End_y - Start_y,1, this));
		else if (m_ToolButton->getName() == "E") // Ÿ�� ��ư�� Ŭ������ ��.
			mList.push_back(new Ellip(Start_x, Start_y, End_x - Start_x, End_y - Start_y,2, this));
		else if (m_ToolButton->getName() == "R") // �簢�� ��ư�� Ŭ������ ��.
			mList.push_back(new Rect(Start_x, Start_y, End_x - Start_x, End_y - Start_y,3, this));
		invalidate(); // ȭ�鿡 ǥ�õǵ��� ��.
	}
}
