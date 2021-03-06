#include "stdafx.h"
#include "Figure.h"
#include "FigurePopup.h"

IMPLEMENT_SERIAL(Figure, CObject, 1)
Figure::Figure()
	:CObject()
{
	region = NULL;
}
void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
}

void Figure::popup(int x, int y)
{
	popupPtr->popup(x, y);
}

BOOL Figure::ptlnRgn(int x, int y)
{
	if(region == NULL)
		return FALSE;

	return region->PtInRegion(x,y);
}

Figure::~Figure()
{
	if (region != NULL) delete region;
}
