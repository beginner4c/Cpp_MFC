#include "stdafx.h"
#include "X.h"

IMPLEMENT_SERIAL(X, OnePointFigure, 1) // DATA MEMBER�� ���� ��쿣 �̷� �����θ� ������ Serialize ����

#define Delta	(4)

// constructor �����ڵ�
X::X() // formal parameter void�� ����ִ� �ǹ�
	: OnePointFigure() // ���� Ŭ������ constructor ȣ�� ���
{
	
}

X::X(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
	: OnePointFigure(x1,y1) // ���� Ŭ������ constructor ȣ��
{
	
}

// :: �� scope resolution operator ��� �Ѵ�
void X::draw(CDC* pDC) // �簢�� �׸��� �Լ�
{
	pDC->MoveTo(m_x1 - Delta, m_y1 - Delta);
	pDC->LineTo(m_x1 + Delta, m_y1 + Delta);
	pDC->MoveTo(m_x1 + Delta, m_y1 - Delta);
	pDC->LineTo(m_x1 - Delta, m_y1 + Delta);
}

void X::Serialize(CArchive& ar)
{
	OnePointFigure::Serialize(ar);// ���� Ŭ������ Serialize �Լ� ȣ��
}

// deconstructor �Ҹ���
X::~X(void)
{
}
