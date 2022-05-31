#include "stdafx.h"
#include "Diamond.h"

IMPLEMENT_SERIAL(Diamond, TwoPointFigure, 1) // DATA MEMBER�� ���� ��쿣 �̷� �����θ� ������ Serialize ����

Diamond::Diamond() // formal parameter void�� ����ִ� �ǹ�
	: TwoPointFigure() // ���� Ŭ������ constructor ȣ�� ���
{
	
}

Diamond::Diamond(int x1, int y1, int x2, int y2) // formal parameter void�� ����ִ� �ǹ�
	: TwoPointFigure(x1,y1,x2,y2) // ���� Ŭ������ ������ ȣ��
{
	
}

Diamond::Diamond(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
	: TwoPointFigure(x1,y1) // ���� Ŭ������ constructor ȣ��
{
	
}

// :: �� scope resolution operator ��� �Ѵ�
void Diamond::draw(CDC* pDC) // ���̾Ƹ�� �׸��� �Լ�
{
	int dx, dy;
	dx = m_x1 + (m_x2 - m_x1) / 2;
	dy = m_y1 + (m_y2 - m_y1) / 2;

	pDC->MoveTo(dx, m_y1); // ��ǥ ���� �̵�
	pDC->LineTo(m_x2, dy); // �� ��ǥ���� ���� ��ǥ���� ���� �׸���
	pDC->LineTo(dx, m_y2);
	pDC->LineTo(m_x1, dy);
	pDC->LineTo(dx, m_y1);}

void Diamond::Serialize(CArchive& ar)
{
	TwoPointFigure::Serialize(ar);// ���� Ŭ������ Serialize �Լ� ȣ��
}

// deconstructor �Ҹ���
Diamond::~Diamond(void)
{
}