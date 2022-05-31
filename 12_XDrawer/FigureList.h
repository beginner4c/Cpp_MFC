#pragma once
#include "afxcoll.h"

class Figure;

class FigureList : public CObList
{
	DECLARE_SERIAL(FigureList) // data member�� ���� ��� �̰͸� �����ְ� �Ѿ�� �ȴ�

public:
	FigureList(void);
	~FigureList(void);

	Figure *GetNext(POSITION &pos);
	void RemoveAllFigures();
};

