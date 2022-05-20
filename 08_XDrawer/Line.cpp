#include "stdafx.h"
#include "Line.h"

IMPLEMENT_SERIAL(Line, TwoPointFigure, 1) // DATA MEMBER�� ���� ��쿣 �̷� �����θ� ������ Serialize ����

Line::Line(void) // formal parameter void�� ����ִ� �ǹ�
	: TwoPointFigure() // ���� Ŭ������ ������ ȣ��
{
	
}

Line::Line(int x1, int y1, int x2, int y2) // formal parameter void�� ����ִ� �ǹ�
	: TwoPointFigure(x1,y1,x2,y2) // ���� Ŭ������ ������ ȣ��
{
	
}

Line::Line(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
	: TwoPointFigure(x1,y1) // ���� Ŭ������ constructor ȣ��
{
	
}

// :: �� scope resolution operator ��� �Ѵ�
void Line::draw(CDC* pDC) // �簢�� �׸��� �Լ�
{
	pDC->MoveTo(m_x1, m_y1); // ��ǥ ���� �̵�
	pDC->LineTo(m_x2, m_y2); // �� ��ǥ���� ���� ��ǥ���� ���� �׸���
}

void Line::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);// ���� Ŭ������ Serialize �Լ� ȣ��
}

Line::~Line(void)
{
}
