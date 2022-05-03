
// XDrawerDoc.h : CXDrawerDoc Ŭ������ �������̽�
//


#pragma once

class Box;

class CXDrawerDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CXDrawerDoc();
	DECLARE_DYNCREATE(CXDrawerDoc)

// Ư���Դϴ�.
public:
	// �߿��� �ڷ� ������ Document�� �����ϴ� �� �⺻�̴�
	Box *boxes[100]; // �۾��� ���� �ڽ��� ������ ��ü
	int nBox; // boxes�� index ��Ÿ�� ����
	void add(Box *pBox); // �迭�� �ڽ��� �����ϴ� �Լ�
	// �� �� �Լ��� ��� ���Ͽ��� ó���� �����ϴ�
	// inline �� �ӵ� ����� ���� ��ũ�� ó�� ����ϰ� �����
	inline int boxCount() {return nBox;} // �ڽ��� ������ �˷��ִ� �Լ�
	inline Box* getBox(int i){return boxes[i];} // �ڽ� �迭�� �����ִ� �Լ�

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
};
