#include "stdafx.h"
#include "OnePointFigure.h"

// X와 Bubble class가 속함

IMPLEMENT_SERIAL(OnePointFigure, Figure, 1) // DATA MEMBER가 없는 경우엔 이런 식으로만 선언해 Serialize 가능

OnePointFigure::OnePointFigure(void) // formal parameter void는 비어있는 의미
	: Figure()
{
	m_x1 = 0;
	m_y1 = 0;
}


OnePointFigure::OnePointFigure(int x1, int y1) // formal parameter void는 비어있는 의미
	: Figure()
{
	m_x1 = x1;
	m_y1 = y1;
}


void OnePointFigure::setXY2(int x, int y)
{
	m_x1 = x;
	m_y1 = y;
}

void OnePointFigure::Serialize(CArchive& ar)
{
	Figure::Serialize(ar);// 상위 클래스의 Serialize 함수 호출
	if(ar.IsStoring()){ // 저장할 때 코드
		ar << m_x1 << m_y1;
	}else{ // 로드할 때의 코드
		ar >> m_x1 >> m_y1;
	}
}

OnePointFigure::~OnePointFigure(void)
{
}
