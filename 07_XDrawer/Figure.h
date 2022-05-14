#pragma once
#include "afx.h"
class Figure :
	public CObject
{
	// implementation
	// c++������ �ƹ��͵� ������ private
protected:
	int m_x1; int m_y1;
	int m_x2; int m_y2;

public:
	// constructor
	Figure();
	Figure(int x1, int y1 , int x2, int y2);
	Figure(int x1, int y1);

	// dynamic binding �� ���ؼ� virtual ����
	virtual void draw(CDC* pDC) = 0; // Figure ������ draw�� �����Ǹ� �ȵǴϱ� �߻� �Լ��� �����, pure virtual function

	void setXY2(int x, int y);

	~Figure(); // destructor
};

