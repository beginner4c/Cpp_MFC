#include "stdafx.h"
#include "Figure.h"
#include "FigureList.h"

IMPLEMENT_SERIAL(FigureList, CObList, 1) // DATA MEMBER�� ���� ��쿣 �̷� �����θ� ������ Serialize ����

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