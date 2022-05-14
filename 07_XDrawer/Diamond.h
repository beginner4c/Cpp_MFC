#pragma once
#include "figure.h"
class Diamond :
	public Figure
{
public:
	Diamond();
	Diamond(int x1, int y1, int x2, int y2); // 괄호 안 void는 없다는 의미
	Diamond(int x1, int y1);
	virtual void draw(CDC* pDC);

	~Diamond(void); // destructor 소멸자
};

