#pragma once
#include "afx.h"
#include "Figure.h" // ���� Ŭ������ ��� ������ �ݵ�� include ���ش�

class Line : public Figure
{
	// specification
public: // m�� member�� �ǹ�
	/*
	Box *mp_Pointer; // member pointer
	CString ms_name; // member string
	bool mb_flag; 
	*/

	Line();
	Line(int x1, int y1, int x2, int y2); // ��ȣ �� void�� ���ٴ� �ǹ�
	Line(int x1, int y1);
	virtual void draw(CDC* pDC);

	~Line(); // destructor �Ҹ���
};

