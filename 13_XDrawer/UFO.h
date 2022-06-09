#pragma once
#include "compositefigure.h"

class Circle;

class UFO :
	public CompositeFigure
{
DECLARE_SERIAL(UFO)
	Circle *c1;
	Circle *c2;

public:
	UFO();
	UFO(int x1, int y1);
	UFO(int x1, int y1, int x2, int y2);
	virtual void Serialize(CArchive& ar);
	virtual void setXY2(int x, int y);
	~UFO();
};

