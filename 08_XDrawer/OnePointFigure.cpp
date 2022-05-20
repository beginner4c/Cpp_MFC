#include "stdafx.h"
#include "OnePointFigure.h"

// X�� Bubble class�� ����

IMPLEMENT_SERIAL(OnePointFigure, Figure, 1) // DATA MEMBER�� ���� ��쿣 �̷� �����θ� ������ Serialize ����

OnePointFigure::OnePointFigure(void) // formal parameter void�� ����ִ� �ǹ�
	: Figure()
{
	m_x1 = 0;
	m_y1 = 0;
}


OnePointFigure::OnePointFigure(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
	: Figure()
{
	m_x1 = x1;
	m_y1 = y1;
}


void OnePointFigure::setXY2(int x, int y)
{
	m_x1 = x;
	m_y1 = y;
}

void OnePointFigure::Serialize(CArchive& ar)
{
	Figure::Serialize(ar);// ���� Ŭ������ Serialize �Լ� ȣ��
	if(ar.IsStoring()){ // ������ �� �ڵ�
		ar << m_x1 << m_y1;
	}else{ // �ε��� ���� �ڵ�
		ar >> m_x1 >> m_y1;
	}
}

OnePointFigure::~OnePointFigure(void)
{
}
