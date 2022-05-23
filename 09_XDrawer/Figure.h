#pragma once
#include "afx.h"
class Figure : public CObject
{
	DECLARE_SERIAL(Figure) // DATA MEMBER�� ���� ��� �̰͸� ���´�

// implementation
// c++������ �ƹ��͵� ������ private
public:
	// constructor
	Figure();

	// dynamic binding �� ���ؼ� virtual ����
	virtual void draw(CDC* pDC) {} // Figure ������ draw�� �����Ǹ� �ȵǴϱ� �߻� �Լ��� �����, pure virtual function

	virtual void setXY2(int x, int y) {} // ���� ���� �Լ�
	virtual void Serialize(CArchive& ar);

	~Figure(); // destructor
};

