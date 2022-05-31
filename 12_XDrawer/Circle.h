#pragma once
#include "afx.h"
#include "TwoPointFigure.h" // ���� Ŭ������ ��� ������ �ݵ�� include ���ش�

class Circle :public TwoPointFigure
{
	DECLARE_SERIAL(Circle) // DATA MEMBER�� ���� ��� �̰͸� ���´�

	// specification
public: // m�� member�� �ǹ�

	Circle();
	Circle(int x1, int y1, int x2, int y2); // ��ȣ �� void�� ���ٴ� �ǹ�
	Circle(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);

	~Circle(void); // destructor �Ҹ���
};

