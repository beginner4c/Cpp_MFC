#pragma once
#include "afxcoll.h"

class Figure;

class FigureList : public CObList
{
	DECLARE_SERIAL(FigureList) // data member가 없는 경우 이것만 적어주고 넘어가도 된다

public:
	FigureList(void);
	~FigureList(void);

	Figure *GetNext(POSITION &pos);
	void RemoveAllFigures();
};

