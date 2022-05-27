#pragma once
#include "afx.h"
class Figure : public CObject
{
	DECLARE_SERIAL(Figure) // DATA MEMBER가 없는 경우 이것만 적는다

// implementation
// c++에서는 아무것도 없으면 private
public:
	// constructor
	Figure();

	// dynamic binding 을 위해서 virtual 선언
	virtual void draw(CDC* pDC) {} // Figure 에서는 draw가 구현되면 안되니까 추상 함수로 만든다, pure virtual function

	virtual void setXY2(int x, int y) {} // 순수 가상 함수
	virtual void Serialize(CArchive& ar);

	~Figure(); // destructor
};

