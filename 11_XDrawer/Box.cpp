#include "stdafx.h"
#include "Box.h"

IMPLEMENT_SERIAL(Box, TwoPointFigure, 1) // DATA MEMBER�� ���� ��쿣 �̷� �����θ� ������ Serialize ����

// constructor �����ڵ�
Box::Box() // formal parameter void�� ����ִ� �ǹ�
	: TwoPointFigure() // ���� Ŭ������ constructor ȣ�� ���
{
	
}

Box::Box(int x1, int y1, int x2, int y2) // formal parameter void�� ����ִ� �ǹ�
	: TwoPointFigure(x1,y1,x2,y2) // ���� Ŭ������ ������ ȣ��
{
	
}

Box::Box(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
	: TwoPointFigure(x1,y1) // ���� Ŭ������ constructor ȣ��
{
	
}

// :: �� scope resolution operator ��� �Ѵ�
void Box::draw(CDC* pDC) // �簢�� �׸��� �Լ�
{
	pDC->Rectangle(m_x1, m_y1, m_x2, m_y2);
}

void Box::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);// ���� Ŭ������ Serialize �Լ� ȣ��
}

// deconstructor �Ҹ���
Box::~Box()
{
}
