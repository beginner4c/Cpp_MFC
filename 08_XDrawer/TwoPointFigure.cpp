#include "stdafx.h"
#include "TwoPointFigure.h"

IMPLEMENT_SERIAL(TwoPointFigure, Figure, 1) // DATA MEMBER가 없는 경우엔 이런 식으로만 선언해 Serialize 가능

TwoPointFigure::TwoPointFigure(void) // formal parameter void는 비어있는 의미
	: Figure()
{
	m_x1 = m_x2 = 0;
	m_y1 = m_y2 = 0;
}

TwoPointFigure::TwoPointFigure(int x1, int y1, int x2, int y2) // formal parameter void는 비어있는 의미
	: Figure()
{
	m_x1 = x1;
	m_x2 = x2;
	m_y1 = y1;
	m_y2 = y2;
}

TwoPointFigure::TwoPointFigure(int x1, int y1) // formal parameter void는 비어있는 의미
	: Figure()
{
	m_x1 = m_x2 = x1;
	m_y1 = m_y2 = y1;
}

// 좌표 세팅 함수
void TwoPointFigure::setXY2(int x, int y)
{
	m_x2 = x;
	m_y2 = y;
}

void TwoPointFigure::Serialize(CArchive& ar)
{
	Figure::Serialize(ar);// 상위 클래스의 Serialize 함수 호출
	if(ar.IsStoring()){ // 저장할 때 코드
		ar << m_x1 << m_y1 << m_x2 << m_y2;
	}else{ // 로드할 때의 코드
		ar >> m_x1 >> m_y1 >> m_x2 >> m_y2;
	}
}

TwoPointFigure::~TwoPointFigure(void)
{
}
