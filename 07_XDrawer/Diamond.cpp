#include "stdafx.h"
#include "Diamond.h"


Diamond::Diamond() // formal parameter void는 비어있는 의미
	: Figure() // 상위 클래스의 constructor 호출 방법
{
	
}

Diamond::Diamond(int x1, int y1, int x2, int y2) // formal parameter void는 비어있는 의미
	: Figure(x1,y1,x2,y2) // 상위 클래스의 생성자 호출
{
	
}

Diamond::Diamond(int x1, int y1) // formal parameter void는 비어있는 의미
	: Figure(x1,y1) // 상위 클래스의 constructor 호출
{
	
}

// :: 은 scope resolution operator 라고 한다
void Diamond::draw(CDC* pDC) // 사각형 그리는 함수
{
	int dx, dy;
	dx = m_x1 + (m_x2 - m_x1) / 2;
	dy = m_y1 + (m_y2 - m_y1) / 2;

	pDC->MoveTo(dx, m_y1); // 좌표 먼저 이동
	pDC->LineTo(m_x2, dy); // 현 좌표에서 다음 좌표까지 선을 그리기
	pDC->LineTo(dx, m_y2);
	pDC->LineTo(m_x1, dy);
	pDC->LineTo(dx, m_y1);
}

// deconstructor 소멸자
Diamond::~Diamond(void)
{
}
