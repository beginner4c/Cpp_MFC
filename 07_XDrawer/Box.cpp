#include "stdafx.h"
#include "Box.h"

// constructor �����ڵ�
Box::Box() // formal parameter void�� ����ִ� �ǹ�
	: Figure() // ���� Ŭ������ constructor ȣ�� ���
{
	
}

Box::Box(int x1, int y1, int x2, int y2) // formal parameter void�� ����ִ� �ǹ�
	: Figure(x1,y1,x2,y2) // ���� Ŭ������ ������ ȣ��
{
	
}

Box::Box(int x1, int y1) // formal parameter void�� ����ִ� �ǹ�
	: Figure(x1,y1) // ���� Ŭ������ constructor ȣ��
{
	
}

// :: �� scope resolution operator ��� �Ѵ�
void Box::draw(CDC* pDC) // �簢�� �׸��� �Լ�
{
	pDC->Rectangle(m_x1, m_y1, m_x2, m_y2);
}

// deconstructor �Ҹ���
Box::~Box()
{
}
