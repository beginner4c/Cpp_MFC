#include "stdafx.h"
#include "Kite2.h"
#include "Line.h"
#include "Circle.h"
#include "Box.h"

IMPLEMENT_SERIAL(Kite2, TwoPointFigure, 1)

Kite2::Kite2()
	:TwoPointFigure()
{	
	frame = new Box();
	l1 = new Line();
	l2 = new Line();
	center = new Circle();
}
Kite2::Kite2(int x1, int y1)
	:TwoPointFigure(x1, y1)
{	
	frame = new Box(x1, y1);
	l1 = new Line(x1, y1);
	l2 = new Line(x1, y1);
	center = new Circle(x1, y1);
}
Kite2::Kite2(int x1, int y1, int x2, int y2)
	:TwoPointFigure(x1, y1, x2, y2)
{
	int w = x2 - x1;
	int h = y2 - y1;
	frame = new Box(x1, y1, x2, y2);
	l1 = new Line(x1, y1, x2, y2);
	l2 = new Line(x1+w/2, y1, x1+w/2, y2);
	center = new Circle(x1+w/4, y1+h/4, x2-w/4, y2-h/4);
}
Kite2::~Kite2()
{
	if(frame != NULL)
		delete frame;
	if(l1 != NULL)
		delete l1;
	if(l2 != NULL)
		delete l2;
	if(center != NULL)
		delete center;
}
void Kite2::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);
	if(ar.IsStoring()){
		ar << frame << l1 << l2 << center;
	}else{
		ar >> frame >> l1 >> l2 >> center;
	}
}
//Scope resolution operator
void Kite2::draw(CDC* pDC)
{
	// delegation ю╖юс
	frame->draw(pDC);
	l1->draw(pDC);
	l2->draw(pDC);
	center->draw(pDC);
}

void Kite2::setXY2(int x, int y)
{
	int w = x - m_x1;
	int h = y - m_y1;

	TwoPointFigure::setXY2(x,y);
	frame->setXY2(x,y);
	l1->setXY2(x,y);
	l2->setXY12(m_x1+w/2, m_y1, m_x1+w/2, y);
	center->setXY12(m_x1+w/4, m_y1+h/4, x-w/4, y-h/4);
}
