#pragma once
#include "OnePointFigure.h"
class X : public OnePointFigure
{
	DECLARE_SERIAL(X) // DATA MEMBER�� ���� ��� �̰͸� ���´�

public:
	X();
	X(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);

	~X(); // destructor �Ҹ���
};

