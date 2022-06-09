#pragma once
#include "figure.h"

class FigureList;

// 이전 aggregation과 다른 형태로 아예 aggregation을 위한 클래스이다
// 범용적으로 사용하기 위한 class

class CompositeFigure :
	public Figure
{
	DECLARE_SERIAL(CompositeFigure);

protected:
	FigureList *parts;

public:
	CompositeFigure(); // 좌표와 전혀 관계 없음
	virtual void Serialize(CArchive& ar);
	virtual void makeRegion();
	virtual void draw(CDC* pDC);
	virtual BOOL ptlnRgn(int x, int y);
	~CompositeFigure();
};

