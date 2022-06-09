#pragma once
#include "TwoPointFigure.h"

class Line;
class Circle;
class Box;

class Kite2 : public TwoPointFigure
{
	DECLARE_SERIAL(Kite2)
	Box *frame;
	Line *l1;
	Line *l2;
	Circle *center;
public:	
	Kite2();
	Kite2(int x1, int y1);
	Kite2(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);
	virtual void setXY2(int x, int y);
	~Kite2();
};

