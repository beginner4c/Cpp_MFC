#pragma once
#include "afx.h"
#include "TwoPointFigure.h" // 상위 클래스의 헤더 파일을 반드시 include 해준다

class Line : public TwoPointFigure
{
	DECLARE_SERIAL(Line) // DATA MEMBER가 없는 경우 이것만 적는다

	// specification
public: // m은 member를 의미
	/*
	Box *mp_Pointer; // member pointer
	CString ms_name; // member string
	bool mb_flag; 
	*/

	Line();
	Line(int x1, int y1, int x2, int y2); // 괄호 안 void는 없다는 의미
	Line(int x1, int y1);
	virtual void draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);

	~Line(); // destructor 소멸자
};

