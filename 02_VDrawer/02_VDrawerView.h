
// 02_VDrawerView.h: CMy02VDrawerView 클래스의 인터페이스
//

#pragma once


class CMy02VDrawerView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy02VDrawerView() noexcept;
	DECLARE_DYNCREATE(CMy02VDrawerView)

// 특성입니다.
public:
	CMy02VDrawerDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy02VDrawerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// header 파일에 데이터 멤버를 넣어주는게 C++ 스타일
	// C++에서는 데이터 선언 시 초기화가 되지 않기 때문에 무조건 해주어야 한다
protected:
	int sX, sY;
	int eX, eY;
	BOOL buttonPressed;

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 02_VDrawerView.cpp의 디버그 버전
inline CMy02VDrawerDoc* CMy02VDrawerView::GetDocument() const
   { return reinterpret_cast<CMy02VDrawerDoc*>(m_pDocument); }
#endif

