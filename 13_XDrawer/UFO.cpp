#include "stdafx.h"
#include "UFO.h"
#include "Circle.h"
#include "FigureList.h"

#define DELTA (20) // Ciclce 크기를 고정하기 위한 매크로 값

IMPLEMENT_SERIAL(UFO, CompositeFigure, 1)

UFO::UFO()
	:CompositeFigure()
{	
	c1 = new Circle();
	c2 = new Circle();
	
	parts->AddTail(c1);
	parts->AddTail(c2);
}
UFO::UFO(int x1, int y1)
	:CompositeFigure()
{	
	c1 = new Circle(x1 - DELTA, y1 - DELTA, x1 + DELTA, y1 + DELTA);
	c2 = new Circle(x1 - DELTA, y1 - DELTA, x1 + DELTA, y1 + DELTA);
	
	parts->AddTail(c1);
	parts->AddTail(c2);
}
UFO::UFO(int x1, int y1, int x2, int y2)
	:CompositeFigure()
{
	int w = x2 - x1;
	int h = y2 - y1;
	c1 = new Circle(x1 - DELTA, y1 - DELTA, x2 + DELTA, y2 + DELTA);
	c2 = new Circle(x1 - DELTA, y1 - DELTA, x2 + DELTA, y2 + DELTA);
	
	parts->AddTail(c1);
	parts->AddTail(c2);
}
UFO::~UFO()
{
	// CompositeFigure에서 delete를 해주기 때문에 여기서 또 하면 dangling reference가 발생한다
}

void UFO::Serialize(CArchive& ar)
{
	CompositeFigure::Serialize(ar);
}

void UFO::setXY2(int x, int y)
{
	c2->setXY12(x-DELTA, y-DELTA, x+DELTA, y+DELTA);
}

