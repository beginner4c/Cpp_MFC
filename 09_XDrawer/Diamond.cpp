#include "stdafx.h"
#include "Diamond.h"

IMPLEMENT_SERIAL(Diamond, TwoPointFigure, 1) // DATA MEMBER가 없는 경우엔 이런 식으로만 선언해 Serialize 가능

Diamond::Diamond() // formal parameter void는 비어있는 의미
	: TwoPointFigure() // 상위 클래스의 constructor 호출 방법
{
	
}

Diamond::Diamond(int x1, int y1, int x2, int y2) // formal parameter void는 비어있는 의미
	: TwoPointFigure(x1,y1,x2,y2) // 상위 클래스의 생성자 호출
{
	
}

Diamond::Diamond(int x1, int y1) // formal parameter void는 비어있는 의미
	: TwoPointFigure(x1,y1) // 상위 클래스의 constructor 호출
{
	
}

// :: 은 scope resolution operator 라고 한다
void Diamond::draw(CDC* pDC) // 다이아몬드 그리는 함수
{
	int dx, dy;
	dx = m_x1 + (m_x2 - m_x1) / 2;
	dy = m_y1 + (m_y2 - m_y1) / 2;

	pDC->MoveTo(dx, m_y1); // 좌표 먼저 이동
	pDC->LineTo(m_x2, dy); // 현 좌표에서 다음 좌표까지 선을 그리기
	pDC->LineTo(dx, m_y2);
	pDC->LineTo(m_x1, dy);
	pDC->LineTo(dx, m_y1);}

void Diamond::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);// 상위 클래스의 Serialize 함수 호출
}

// deconstructor 소멸자
Diamond::~Diamond(void)
{
}
