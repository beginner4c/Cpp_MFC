#include "stdafx.h"
#include "Figure.h"
#include "FigureList.h"

IMPLEMENT_SERIAL(FigureList, CObList, 1) // DATA MEMBER�� ���� ��쿣 �̷� �����θ� ������ Serialize ����

FigureList::FigureList()
	: CObList()
{
}


FigureList::~FigureList()
{
	RemoveAllFigures();
}

void FigureList::RemoveAllFigures()
{
	POSITION pos = GetHeadPosition();
	while(pos != NULL){
		Figure* fig = (Figure*)GetNext(pos);
		delete fig;
	}
	RemoveAll();
}

Figure *FigureList::GetNext(POSITION &pos)
{
	return (Figure *)CObList::GetNext(pos);
}