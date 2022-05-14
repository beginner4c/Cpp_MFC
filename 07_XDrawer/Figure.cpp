#include "stdafx.h"
#include "Figure.h"


Figure::Figure(void) // formal parameter void�� ����ִ� �ǹ�
{
	m_x1 = m_x2 = 0;
	m_y1 = m_y2 = 0;
}

Figure::Figure(int x1, int y1, int x2, int y2) // formal parameter void�� ����ִ� �ǹ�
{
	m_x1 = x1;
	m_x2 = x2;
	m_y1 = y1;
	m_y2 = y2;
}

Figure::Figure(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
{
	m_x1 = m_x2 = x1;
	m_y1 = m_y2 = y1;
}

// ��ǥ ���� �Լ�
void Figure::setXY2(int x, int y)
{
	m_x2 = x;
	m_y2 = y;
}

Figure::~Figure(void)
{
}
