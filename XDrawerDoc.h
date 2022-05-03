
// XDrawerDoc.h : CXDrawerDoc 클래스의 인터페이스
//


#pragma once

class Box;

class CXDrawerDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CXDrawerDoc();
	DECLARE_DYNCREATE(CXDrawerDoc)

// 특성입니다.
public:
	// 중요한 자료 구조는 Document에 저장하는 게 기본이다
	Box *boxes[100]; // 작업이 끝난 박스를 저장할 객체
	int nBox; // boxes의 index 나타낼 정수
	void add(Box *pBox); // 배열에 박스를 저장하는 함수
	// 한 줄 함수는 헤더 파일에서 처리가 가능하다
	// inline 은 속도 향상을 위해 매크로 처럼 사용하게 만든다
	inline int boxCount() {return nBox;} // 박스의 개수를 알려주는 함수
	inline Box* getBox(int i){return boxes[i];} // 박스 배열을 돌려주는 함수

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
