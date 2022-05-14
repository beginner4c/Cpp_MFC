#pragma once
#include "afx.h"
#include "Figure.h" // ���� Ŭ������ ��� ������ �ݵ�� include ���ش�

class Circle :public Figure
{
	// specification
public: // m�� member�� �ǹ�

	Circle();
	Circle(int x1, int y1, int x2, int y2); // ��ȣ �� void�� ���ٴ� �ǹ�
	Circle(int x1, int y1);
	virtual void draw(CDC* pDC);

	~Circle(void); // destructor �Ҹ���
};

