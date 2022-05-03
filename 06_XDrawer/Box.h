#pragma once
#include "afx.h"
class Box : public CObject
{
	// implementation
	// c++에서는 아무것도 없으면 private
	int m_x1; int m_y1;
	int m_x2; int m_y2;

	// specification
public: // m은 member를 의미
	/*
	Box *mp_Pointer; // member pointer
	CString ms_name; // member string
	bool mb_flag; 
	*/

	Box();
	Box(int x1, int y1, int x2, int y2); // 괄호 안 void는 없다는 의미
	Box(int x1, int y1);
	void draw(CDC* pDC);
	void setXY2(int x, int y);
	~Box(); // destructor 소멸자
};

