#include "stdafx.h"
#include "Bubble.h"

IMPLEMENT_SERIAL(Bubble, OnePointFigure, 1) // DATA MEMBER�� ���� ��쿣 �̷� �����θ� ������ Serialize ����

#define Delta	(4)

Bubble::Bubble(void)
	: OnePointFigure() // ���� Ŭ������ constructor ȣ��
{
	
}


Bubble::Bubble(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
	: OnePointFigure(x1,y1) // ���� Ŭ������ ������ ȣ��
{
	
}

// :: �� scope resolution operator ��� �Ѵ�
void Bubble::draw(CDC* pDC) // �� �׸��� �Լ�
{
	pDC->Ellipse(m_x1-Delta,m_y1-Delta,m_x1+Delta,m_y1+Delta);
}

void Bubble::Serialize(CArchive& ar)
{
	OnePointFigure::Serialize(ar);// ���� Ŭ������ Serialize �Լ� ȣ��
}

Bubble::~Bubble(void) // destructor
{
}
