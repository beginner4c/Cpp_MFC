#include "stdafx.h"
#include "Figure.h"
#include "FigureList.h"

IMPLEMENT_SERIAL(FigureList, CObList, 1) // DATA MEMBER가 없는 경우엔 이런 식으로만 선언해 Serialize 가능

FigureList::FigureList(void)
	: CObList()
{
}


FigureList::~FigureList(void)
{
}

Figure *FigureList::GetNext(POSITION &pos)
{
	return (Figure *)CObList::GetNext(pos);
}