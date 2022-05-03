#include "stdafx.h"
#include "Box.h"

// constructor �����ڵ�
Box::Box(void) // formal parameter void�� ����ִ� �ǹ�
{
	this->m_x1 = this->m_x2 = 0;
	m_y1 = m_y2 = 0;
}

Box::Box(int x1, int y1, int x2, int y2) // formal parameter void�� ����ִ� �ǹ�
{
	this->m_x1 = x1;
	m_x2 = x2;
	m_y1 = y1;
	m_y2 = y2;
}

Box::Box(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
{
	this->m_x1 = this->m_x2 = x1;
	m_y1 = m_y2 = y1;
}

// :: �� scope resolution operator ��� �Ѵ�
void Box::draw(CDC* pDC) // �簢�� �׸��� �Լ�
{
	pDC->Rectangle(m_x1, m_y1, m_x2, m_y2);
}

// ��ǥ ���� �Լ�
void Box::setXY2(int x, int y)
{
	m_x2 = x;
	m_y2 = y;
}

// deconstructor �Ҹ���
Box::~Box()
{
}
