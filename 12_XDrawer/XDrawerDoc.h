
// XDrawerDoc.h : CXDrawerDoc Ŭ������ �������̽�
//


#pragma once

class Figure;
class FigureList;

class CXDrawerDoc : public CDocument
{
	FigureList *figures; // private linked list ����
//	FigureList figures // automatic allocation�� ��� Serialize�� �� ����������

protected: // serialization������ ��������ϴ�.
	CXDrawerDoc();
	DECLARE_DYNCREATE(CXDrawerDoc)

	// �߿��� �ڷ� ������ Document�� �����ϴ� �� �⺻�̴�
	

// Ư���Դϴ�.
public:
	void add(Figure *pFigure); // �迭�� �׸��� �����ϴ� �Լ�
	inline FigureList *getFigures(){return figures;} // ��ȣ�� ����Ʈ�� ������ �Լ�


	// �� �� �Լ��� ��� ���Ͽ��� ó���� �����ϴ�
	// inline �� �ӵ� ����� ���� ��ũ�� ó�� ����ϰ� �����

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CXDrawerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
//	afx_msg void OnFileNew();
};