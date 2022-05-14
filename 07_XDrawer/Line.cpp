#include "stdafx.h"
#include "Line.h"


Line::Line(void) // formal parameter void는 비어있는 의미
	: Figure() // 상위 클래스의 생성자 호출
{
	
}

Line::Line(int x1, int y1, int x2, int y2) // formal parameter void는 비어있는 의미
	: Figure(x1,y1,x2,y2) // 상위 클래스의 생성자 호출
{
	
}

Line::Line(int x1, int y1) // formal parameter void는 비어있는 의미
	: Figure(x1,y1) // 상위 클래스의 constructor 호출
{
	
}

// :: 은 scope resolution operator 라고 한다
void Line::draw(CDC* pDC) // 사각형 그리는 함수
{
	pDC->MoveTo(m_x1, m_y1); // 좌표 먼저 이동
	pDC->LineTo(m_x2, m_y2); // 현 좌표에서 다음 좌표까지 선을 그리기
}


Line::~Line(void)
{
}
