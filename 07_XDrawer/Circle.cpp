#include "stdafx.h"
#include "Circle.h"


Circle::Circle(void)
	: Figure() // ���� Ŭ������ constructor ȣ��
{
	
}

Circle::Circle(int x1, int y1, int x2, int y2) // formal parameter void�� ����ִ� �ǹ�
	: Figure(x1,y1,x2,y2) // ���� Ŭ������ ������ ȣ��
{
	
}

Circle::Circle(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
	: Figure(x1,y1) // ���� Ŭ������ ������ ȣ��
{
	
}

// :: �� scope resolution operator ��� �Ѵ�
void Circle::draw(CDC* pDC) // �� �׸��� �Լ�
{
	pDC->Ellipse(m_x1,m_y1,m_x2,m_y2);
}


Circle::~Circle(void) // destructor
{
}
