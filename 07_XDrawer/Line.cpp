#include "stdafx.h"
#include "Line.h"


Line::Line(void) // formal parameter void�� ����ִ� �ǹ�
	: Figure() // ���� Ŭ������ ������ ȣ��
{
	
}

Line::Line(int x1, int y1, int x2, int y2) // formal parameter void�� ����ִ� �ǹ�
	: Figure(x1,y1,x2,y2) // ���� Ŭ������ ������ ȣ��
{
	
}

Line::Line(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
	: Figure(x1,y1) // ���� Ŭ������ constructor ȣ��
{
	
}

// :: �� scope resolution operator ��� �Ѵ�
void Line::draw(CDC* pDC) // �簢�� �׸��� �Լ�
{
	pDC->MoveTo(m_x1, m_y1); // ��ǥ ���� �̵�
	pDC->LineTo(m_x2, m_y2); // �� ��ǥ���� ���� ��ǥ���� ���� �׸���
}


Line::~Line(void)
{
}
