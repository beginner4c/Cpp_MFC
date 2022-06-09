#pragma once
#include "box.h"

class Line;
class Circle;

class Kite1 : public Box
{
	DECLARE_SERIAL(Kite1)
	Line *l1;
	Line *l2;
	Circle *center;
public:	
	Kite1();
	Kite1(int x1, int y1);
	Kite1(int x1, int y1, int x2, int y2);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);
	virtual void setXY2(int x, int y);
	~Kite1();
};

