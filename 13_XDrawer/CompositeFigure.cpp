#include "stdafx.h"
#include "CompositeFigure.h"
#include "FigureList.h"

IMPLEMENT_SERIAL(CompositeFigure, Figure, 1)

CompositeFigure::CompositeFigure(void)
	:Figure()
{
	parts = new FigureList();
}

void CompositeFigure::Serialize(CArchive& ar)
{
	Figure::Serialize(ar);
	if (ar.IsStoring()) {
		ar << parts;
	} else {
		ar >> parts;
	}
}

void CompositeFigure::makeRegion()
{
	if(region != NULL) 
		delete region;

	POSITION pos = parts->GetHeadPosition();
	while(pos != NULL){
		Figure *ptr = parts->GetNext(pos);
		ptr->makeRegion();
	}

}

void CompositeFigure::draw(CDC* pDC)
{
	POSITION pos = parts->GetHeadPosition();
	while(pos != NULL){
		Figure *ptr = parts->GetNext(pos);
		ptr->draw(pDC);
	}
}

BOOL CompositeFigure::ptlnRgn(int x, int y)
{
	POSITION pos = parts->GetHeadPosition();
	while(pos != NULL){
		Figure *ptr = parts->GetNext(pos);
		if(ptr->ptlnRgn(x,y) == TRUE)
			return TRUE;			
	}
	return FALSE;
}

CompositeFigure::~CompositeFigure(void) // destructor
{
	delete parts;
}
