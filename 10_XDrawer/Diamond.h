#pragma once
#include "TwoPointFigure.h"

class Diamond :public TwoPointFigure
{
	DECLARE_SERIAL(Diamond) // DATA MEMBER�� ���� ��� �̰͸� ���´�

public:
	Diamond();
	Diamond(int x1, int y1, int x2, int y2); // ��ȣ �� void�� ���ٴ� �ǹ�
	Diamond(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);

	~Diamond(void); // destructor �Ҹ���
};

