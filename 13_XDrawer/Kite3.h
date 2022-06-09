#pragma once
#include "CompositeFigure.h"

class Line;
class Circle;
class Box;

class Kite3 :
	public CompositeFigure
{
	DECLARE_SERIAL(Kite3)
	Box *frame;
	Line *l1;
	Line *l2;
	Circle *center;

public:
	Kite3();
	Kite3(int x1, int y1);
	Kite3(int x1, int y1, int x2, int y2);
	virtual void Serialize(CArchive& ar);
	virtual void setXY2(int x, int y);
	~Kite3();
};

