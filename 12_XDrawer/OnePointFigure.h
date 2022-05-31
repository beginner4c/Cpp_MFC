#pragma once
#include "figure.h"
class OnePointFigure : public Figure
{
	DECLARE_SERIAL(OnePointFigure) // DATA MEMBER가 없는 경우 이것만 적는다

protected:
	int m_x1; int m_y1;

public:
	OnePointFigure();
	OnePointFigure(int x1, int y1);
	virtual void setXY2(int x, int y); // 구현이 달라져 override가 필요하다
	virtual void Serialize(CArchive& ar);

	~OnePointFigure();
};

