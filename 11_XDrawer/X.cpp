#include "stdafx.h"
#include "X.h"

IMPLEMENT_SERIAL(X, OnePointFigure, 1) // DATA MEMBER가 없는 경우엔 이런 식으로만 선언해 Serialize 가능

#define Delta	(4)

// constructor 생성자들
X::X() // formal parameter void는 비어있는 의미
	: OnePointFigure() // 상위 클래스의 constructor 호출 방법
{
	
}

X::X(int x1, int y1) // formal parameter void는 비어있는 의미
	: OnePointFigure(x1,y1) // 상위 클래스의 constructor 호출
{
	
}

// :: 은 scope resolution operator 라고 한다
void X::draw(CDC* pDC) // 사각형 그리는 함수
{
	pDC->MoveTo(m_x1 - Delta, m_y1 - Delta);
	pDC->LineTo(m_x1 + Delta, m_y1 + Delta);
	pDC->MoveTo(m_x1 + Delta, m_y1 - Delta);
	pDC->LineTo(m_x1 - Delta, m_y1 + Delta);
}

void X::Serialize(CArchive& ar)
{
	OnePointFigure::Serialize(ar);// 상위 클래스의 Serialize 함수 호출
}

// deconstructor 소멸자
X::~X(void)
{
}
