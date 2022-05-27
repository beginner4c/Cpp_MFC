#include "stdafx.h"
#include "Figure.h"

IMPLEMENT_SERIAL(Figure, CObject, 1) // DATA MEMBER가 없는 경우엔 이런 식으로만 선언해 Serialize 가능

Figure::Figure() // formal parameter void는 비어있는 의미
: CObject()
{
	
}

void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);// 상위 클래스의 Serialize 함수 호출
}


Figure::~Figure(void)
{
}
