
// XDrawerDoc.h : CXDrawerDoc 클래스의 인터페이스
//


#pragma once

class Figure;
class FigureList;

class CXDrawerDoc : public CDocument
{
	FigureList *figures; // private linked list 생성

protected: // serialization에서만 만들어집니다.
	CXDrawerDoc();
	DECLARE_DYNCREATE(CXDrawerDoc)

	// 중요한 자료 구조는 Document에 저장하는 게 기본이다
	

// 특성입니다.
public:
	void add(Figure *pFigure); // 배열에 그림을 저장하는 함수
	inline FigureList *getFigures(){return figures;} // 보호된 리스트를 가져올 함수


	// 한 줄 함수는 헤더 파일에서 처리가 가능하다
	// inline 은 속도 향상을 위해 매크로 처럼 사용하게 만든다

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CXDrawerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
