#pragma once
#include "OnePointFigure.h"
class X : public OnePointFigure
{
	DECLARE_SERIAL(X) // DATA MEMBER가 없는 경우 이것만 적는다

public:
	X();
	X(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);

	~X(); // destructor 소멸자
};

