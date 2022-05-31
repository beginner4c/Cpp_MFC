#include "stdafx.h"
#include "Bubble.h"

IMPLEMENT_SERIAL(Bubble, OnePointFigure, 1) // DATA MEMBER가 없는 경우엔 이런 식으로만 선언해 Serialize 가능

#define Delta	(4)

Bubble::Bubble(void)
	: OnePointFigure() // 상위 클래스의 constructor 호출
{
	
}


Bubble::Bubble(int x1, int y1) // formal parameter void는 비어있는 의미
	: OnePointFigure(x1,y1) // 상위 클래스의 생성자 호출
{
	
}

// :: 은 scope resolution operator 라고 한다
void Bubble::draw(CDC* pDC) // 원 그리는 함수
{
	pDC->Ellipse(m_x1-Delta,m_y1-Delta,m_x1+Delta,m_y1+Delta);
}

void Bubble::Serialize(CArchive& ar)
{
	OnePointFigure::Serialize(ar);// 상위 클래스의 Serialize 함수 호출
}

Bubble::~Bubble(void) // destructor
{
}
