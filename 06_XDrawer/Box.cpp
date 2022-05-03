#include "stdafx.h"
#include "Box.h"

// constructor 생성자들
Box::Box(void) // formal parameter void는 비어있는 의미
{
	this->m_x1 = this->m_x2 = 0;
	m_y1 = m_y2 = 0;
}

Box::Box(int x1, int y1, int x2, int y2) // formal parameter void는 비어있는 의미
{
	this->m_x1 = x1;
	m_x2 = x2;
	m_y1 = y1;
	m_y2 = y2;
}

Box::Box(int x1, int y1) // formal parameter void는 비어있는 의미
{
	this->m_x1 = this->m_x2 = x1;
	m_y1 = m_y2 = y1;
}

// :: 은 scope resolution operator 라고 한다
void Box::draw(CDC* pDC) // 사각형 그리는 함수
{
	pDC->Rectangle(m_x1, m_y1, m_x2, m_y2);
}

// 좌표 세팅 함수
void Box::setXY2(int x, int y)
{
	m_x2 = x;
	m_y2 = y;
}

// deconstructor 소멸자
Box::~Box()
{
}
