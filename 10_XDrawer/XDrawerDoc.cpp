
// XDrawerDoc.cpp : CXDrawerDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "XDrawer.h"
#endif

#include "XDrawerDoc.h"
#include "Figure.h"
#include "FigureList.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CXDrawerDoc

IMPLEMENT_DYNCREATE(CXDrawerDoc, CDocument)

BEGIN_MESSAGE_MAP(CXDrawerDoc, CDocument)
//	ON_COMMAND(ID_FILE_NEW, &CXDrawerDoc::OnFileNew)
END_MESSAGE_MAP()


// CXDrawerDoc ����/�Ҹ�

CXDrawerDoc::CXDrawerDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	
	//::MessageBox(NULL, _T("CXDrawerDoc"), _T("CXDrawerDoc"),0);
	figures = new FigureList();
}

CXDrawerDoc::~CXDrawerDoc()
{
	//::MessageBox(NULL, _T("~CXDrawerDoc"), _T("~CXDrawerDoc"),0);
	if(figures){
		delete figures;
		figures = NULL;
	}
}

BOOL CXDrawerDoc::OnNewDocument() // �� â ���� �̺�Ʈ �ڵ鷯�� ������� ������ �ڵ����� ȣ���
{
	if (!CDocument::OnNewDocument()) // �޸� ���� �� �����Ѵ�
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

//	delete figures; // ȿ�� ��¦ ������ garbage collection
//	figures = new FigureList(); // �� ����� ���� ����ϱ�

	// figures->RemoveAll(); // garbage collection ����
	figures->RemoveAllFigures();

	return TRUE;
}




// CXDrawerDoc serialization

void CXDrawerDoc::Serialize(CArchive& ar)
{
	// figures.Serialize(ar); // automatic allocation�� ��쿡 ����Ѵ�, �� ����

	if (ar.IsStoring()) // ������ΰ�
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		ar << figures;
	}
	else // �ε���� ���
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		delete figures;

		ar >> figures;

		// POSITION pos = GetFirstViewPosition();
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CXDrawerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CXDrawerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CXDrawerDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CXDrawerDoc ����

#ifdef _DEBUG
void CXDrawerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CXDrawerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CXDrawerDoc ����

void CXDrawerDoc::add(Figure *pFigure)
{
	figures->AddTail(pFigure); // automatic allocation�� figures ���� ���
}


//void CXDrawerDoc::OnFileNew()
//{
//	// TODO: ���⿡ ���� ó���� �ڵ带 �߰��մϴ�.
//
//	::MessageBox(NULL, _T("HI"), _T("MFC"), 0);
//	// OnNewDocument(); // �̰Ÿ� ���⼭ ȣ���ϴ� ������ ������ �����ϴ�
//}