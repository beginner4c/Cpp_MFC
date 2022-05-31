#pragma once
#include "OnePointFigure.h"

class Bubble : public OnePointFigure
{
	DECLARE_SERIAL(Bubble) // DATA MEMBER가 없는 경우 이것만 적는다

public:
	Bubble();
	Bubble(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);

	~Bubble(void); // destructor 소멸자
};

