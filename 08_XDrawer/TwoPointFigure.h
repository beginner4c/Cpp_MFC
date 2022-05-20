#pragma once
#include "figure.h"

class TwoPointFigure : public Figure
{
	DECLARE_SERIAL(TwoPointFigure) // DATA MEMBER가 없는 경우 이것만 적는다

protected:
	int m_x1; int m_y1;
	int m_x2; int m_y2;

public:
	//constructor
	TwoPointFigure();
	TwoPointFigure(int x1, int y1 , int x2, int y2);
	TwoPointFigure(int x1, int y1);

	virtual void setXY2(int x, int y);
	virtual void Serialize(CArchive& ar);

	~TwoPointFigure(void);
};

