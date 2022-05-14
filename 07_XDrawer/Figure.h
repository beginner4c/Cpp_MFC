#pragma once
#include "afx.h"
class Figure :
	public CObject
{
	// implementation
	// c++에서는 아무것도 없으면 private
protected:
	int m_x1; int m_y1;
	int m_x2; int m_y2;

public:
	// constructor
	Figure();
	Figure(int x1, int y1 , int x2, int y2);
	Figure(int x1, int y1);

	// dynamic binding 을 위해서 virtual 선언
	virtual void draw(CDC* pDC) = 0; // Figure 에서는 draw가 구현되면 안되니까 추상 함수로 만든다, pure virtual function

	void setXY2(int x, int y);

	~Figure(); // destructor
};

