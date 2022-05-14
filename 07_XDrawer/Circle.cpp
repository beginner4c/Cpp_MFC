#include "stdafx.h"
#include "Circle.h"


Circle::Circle(void)
	: Figure() // 상위 클래스의 constructor 호출
{
	
}

Circle::Circle(int x1, int y1, int x2, int y2) // formal parameter void는 비어있는 의미
	: Figure(x1,y1,x2,y2) // 상위 클래스의 생성자 호출
{
	
}

Circle::Circle(int x1, int y1) // formal parameter void는 비어있는 의미
	: Figure(x1,y1) // 상위 클래스의 생성자 호출
{
	
}

// :: 은 scope resolution operator 라고 한다
void Circle::draw(CDC* pDC) // 원 그리는 함수
{
	pDC->Ellipse(m_x1,m_y1,m_x2,m_y2);
}


Circle::~Circle(void) // destructor
{
}
