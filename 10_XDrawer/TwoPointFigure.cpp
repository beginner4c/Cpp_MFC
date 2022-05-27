#include "stdafx.h"
#include "TwoPointFigure.h"

IMPLEMENT_SERIAL(TwoPointFigure, Figure, 1) // DATA MEMBER�� ���� ��쿣 �̷� �����θ� ������ Serialize ����

TwoPointFigure::TwoPointFigure(void) // formal parameter void�� ����ִ� �ǹ�
	: Figure()
{
	m_x1 = m_x2 = 0;
	m_y1 = m_y2 = 0;
}

TwoPointFigure::TwoPointFigure(int x1, int y1, int x2, int y2) // formal parameter void�� ����ִ� �ǹ�
	: Figure()
{
	m_x1 = x1;
	m_x2 = x2;
	m_y1 = y1;
	m_y2 = y2;
}

TwoPointFigure::TwoPointFigure(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
	: Figure()
{
	m_x1 = m_x2 = x1;
	m_y1 = m_y2 = y1;
}

// ��ǥ ���� �Լ�
void TwoPointFigure::setXY2(int x, int y)
{
	m_x2 = x;
	m_y2 = y;
}

void TwoPointFigure::Serialize(CArchive& ar)
{
	Figure::Serialize(ar);// ���� Ŭ������ Serialize �Լ� ȣ��
	if(ar.IsStoring()){ // ������ �� �ڵ�
		ar << m_x1 << m_y1 << m_x2 << m_y2;
	}else{ // �ε��� ���� �ڵ�
		ar >> m_x1 >> m_y1 >> m_x2 >> m_y2;
	}
}

TwoPointFigure::~TwoPointFigure(void)
{
}
