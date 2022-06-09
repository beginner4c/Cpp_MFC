#include "stdafx.h"
#include "Kite3.h"
#include "Line.h"
#include "Circle.h"
#include "Box.h"
#include "FigureList.h"

IMPLEMENT_SERIAL(Kite3, CompositeFigure, 1)

Kite3::Kite3()
	:CompositeFigure()
{	
	frame = new Box();
	l1 = new Line();
	l2 = new Line();
	center = new Circle();

	parts->AddTail(frame);
	parts->AddTail(l1);
	parts->AddTail(l2);
	parts->AddTail(center);
}
Kite3::Kite3(int x1, int y1)
	:CompositeFigure()
{	
	frame = new Box(x1, y1);
	l1 = new Line(x1, y1);
	l2 = new Line(x1, y1);
	center = new Circle(x1, y1);

	parts->AddTail(frame);
	parts->AddTail(l1);
	parts->AddTail(l2);
	parts->AddTail(center);
}
Kite3::Kite3(int x1, int y1, int x2, int y2)
	:CompositeFigure()
{
	int w = x2 - x1;
	int h = y2 - y1;
	frame = new Box(x1, y1, x2, y2);
	l1 = new Line(x1, y1, x2, y2);
	l2 = new Line(x1+w/2, y1, x1+w/2, y2);
	center = new Circle(x1+w/4, y1+h/4, x2-w/4, y2-h/4);

	parts->AddTail(frame);
	parts->AddTail(l1);
	parts->AddTail(l2);
	parts->AddTail(center);
}
Kite3::~Kite3()
{
	// CompositeFigure에서 delete를 해주기 때문에 여기서 또 하면 dangling reference가 발생한다
}

void Kite3::Serialize(CArchive& ar)
{
	CompositeFigure::Serialize(ar);
}

void Kite3::setXY2(int x, int y)
{
	int x1 = frame->getX1();
	int y1 = frame->getY1();
	int w = x - x1;
	int h = y - y1;

	frame->setXY2(x,y);
	l1->setXY2(x,y);
	l2->setXY12(x1+w/2, y1, x1+w/2, y);
	center->setXY12(x1+w/4, y1+h/4, x-w/4, y-h/4);
}

