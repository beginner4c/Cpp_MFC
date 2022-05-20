#pragma once
#include "afx.h"
#include "TwoPointFigure.h" // ���� Ŭ������ ��� ������ �ݵ�� include ���ش�

class Box : public TwoPointFigure
{
	DECLARE_SERIAL(Box) // DATA MEMBER�� ���� ��� �̰͸� ���´�

	// specification
public: // m�� member�� �ǹ�
	/*
	Box *mp_Pointer; // member pointer
	CString ms_name; // member string
	bool mb_flag; 
	*/

	Box();
	Box(int x1, int y1, int x2, int y2); // ��ȣ �� void�� ���ٴ� �ǹ�
	Box(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);

	~Box(); // destructor �Ҹ���
};

