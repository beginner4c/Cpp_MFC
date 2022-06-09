#pragma once
#include "figure.h"

class FigureList;

// ���� aggregation�� �ٸ� ���·� �ƿ� aggregation�� ���� Ŭ�����̴�
// ���������� ����ϱ� ���� class

class CompositeFigure :
	public Figure
{
	DECLARE_SERIAL(CompositeFigure);

protected:
	FigureList *parts;

public:
	CompositeFigure(); // ��ǥ�� ���� ���� ����
	virtual void Serialize(CArchive& ar);
	virtual void makeRegion();
	virtual void draw(CDC* pDC);
	virtual BOOL ptlnRgn(int x, int y);
	~CompositeFigure();
};

