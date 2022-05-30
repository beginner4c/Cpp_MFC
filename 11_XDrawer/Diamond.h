#pragma once
#include "TwoPointFigure.h"

class Diamond :public TwoPointFigure
{
	DECLARE_SERIAL(Diamond) // DATA MEMBER가 없는 경우 이것만 적는다

public:
	Diamond();
	Diamond(int x1, int y1, int x2, int y2); // 괄호 안 void는 없다는 의미
	Diamond(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);

	~Diamond(void); // destructor 소멸자
};

