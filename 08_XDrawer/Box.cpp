#include "stdafx.h"
#include "Box.h"

IMPLEMENT_SERIAL(Box, TwoPointFigure, 1) // DATA MEMBER가 없는 경우엔 이런 식으로만 선언해 Serialize 가능

// constructor 생성자들
Box::Box() // formal parameter void는 비어있는 의미
	: TwoPointFigure() // 상위 클래스의 constructor 호출 방법
{
	
}

Box::Box(int x1, int y1, int x2, int y2) // formal parameter void는 비어있는 의미
	: TwoPointFigure(x1,y1,x2,y2) // 상위 클래스의 생성자 호출
{
	
}

Box::Box(int x1, int y1) // formal parameter void는 비어있는 의미
	: TwoPointFigure(x1,y1) // 상위 클래스의 constructor 호출
{
	
}

// :: 은 scope resolution operator 라고 한다
void Box::draw(CDC* pDC) // 사각형 그리는 함수
{
	pDC->Rectangle(m_x1, m_y1, m_x2, m_y2);
}

void Box::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);// 상위 클래스의 Serialize 함수 호출
}

// deconstructor 소멸자
Box::~Box()
{
}
