#include "stdafx.h"
#include "Figure.h"

IMPLEMENT_SERIAL(Figure, CObject, 1) // DATA MEMBER�� ���� ��쿣 �̷� �����θ� ������ Serialize ����

Figure::Figure() // formal parameter void�� ����ִ� �ǹ�
: CObject()
{
	
}

void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);// ���� Ŭ������ Serialize �Լ� ȣ��
}


Figure::~Figure(void)
{
}
