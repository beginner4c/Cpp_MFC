#pragma once
#include "figure.h"
class Diamond :
	public Figure
{
public:
	Diamond();
	Diamond(int x1, int y1, int x2, int y2); // ��ȣ �� void�� ���ٴ� �ǹ�
	Diamond(int x1, int y1);
	virtual void draw(CDC* pDC);

	~Diamond(void); // destructor �Ҹ���
};

