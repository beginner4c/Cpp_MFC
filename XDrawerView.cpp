
// XDrawerView.cpp : CXDrawerView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "XDrawer.h"
#endif

#include "XDrawerDoc.h"
#include "XDrawerView.h"
#include "Box.h" // ��� ���ϰ� �ٸ��� include�� �ʿ��ϴ�

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CXDrawerView

IMPLEMENT_DYNCREATE(CXDrawerView, CView)

BEGIN_MESSAGE_MAP(CXDrawerView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CXDrawerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CXDrawerView ����/�Ҹ�

CXDrawerView::CXDrawerView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	currentBox = NULL;

	
}

CXDrawerView::~CXDrawerView()
{
}

BOOL CXDrawerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CXDrawerView �׸���

void CXDrawerView::OnDraw(CDC* pDC) // ȭ�� ���ŵǾ��� �� �ʱ� ȭ���� �����ش�
{
	CXDrawerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH); // Null Brush ����
	for(int i =0;i<pDoc->boxCount(); i++){ // paint �̺�Ʈ�� ȣ��� �� ����� �ڽ��� �ٽ� �׸���
		pDoc->getBox(i)->draw(pDC);
	}
	pDC->SelectObject(oldBrush);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	/*
	// NULL Brush
	pDC->SelectStockObject(NULL_BRUSH); // �ڿ� ������ �����ϴ� �귯���� ����

	// �� �׸���
	pDC->Ellipse(100,100,200,200);

	// �Ķ��� ���� �簢�� �׸���
	CPen pen(PS_SOLID, 3, RGB(0,0,255)); // �Ǽ��� �β��� 3�� �Ķ� ���� ����
	CPen *oldPen = pDC->SelectObject(&pen); // �⺻ �濡 �Ķ����� ������
	pDC->Rectangle(100,100,200,200);
	pDC->SelectObject(oldPen); // ������ ������ ������

	// line�׸���
	pDC->MoveTo(300,300);
	pDC->LineTo(100,100);
	CPen pen2(PS_SOLID, 1, RGB(0,0,0)); // �Ǽ� �β� 1 ���� �� ����
	pDC->SelectObject(&pen2); // �� �Ҵ�
	pDC->MoveTo(300,300);
	pDC->LineTo(500,500);



	// ���� ä���� �簢�� �׸���
	CRect rect(50,50,100,100);
	CBrush br(RGB(255,0,0));
	pDC->FillRect(&rect, &br);
	*/
}


// CXDrawerView �μ�


void CXDrawerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CXDrawerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CXDrawerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CXDrawerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CXDrawerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CXDrawerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CXDrawerView ����

#ifdef _DEBUG
void CXDrawerView::AssertValid() const
{
	CView::AssertValid();
}

void CXDrawerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CXDrawerDoc* CXDrawerView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CXDrawerDoc)));
	return (CXDrawerDoc*)m_pDocument;
}
#endif //_DEBUG


// CXDrawerView �޽��� ó����


void CXDrawerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	currentBox = new Box(point.x, point.y);
	CDC *pDC = GetDC();
	currentBox->draw(pDC);
	CView::OnLButtonDown(nFlags, point);
}


void CXDrawerView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(currentBox != NULL){
		CDC* pDC = this->GetDC(); // ���� ȭ���� Device Context �� ������
		CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH); // Null Brush ����
		currentBox->setXY2(point.x, point.y); // x2, y2 ��ǥ ����
		currentBox->draw(pDC); // �簢�� �׸���
		pDC->SelectObject(oldBrush); // Brush default ������ �ǵ�����

		CXDrawerDoc *pDoc = GetDocument();
		pDoc->boxes[pDoc->nBox++] = currentBox;
		pDoc->add(currentBox);
	}
	currentBox = NULL;

	// �޽����ڽ��� ���� �̺�Ʈ ������ Ȯ��
	// MessageBox(_T("Hello"),_T("World"), 0); // �Ϲ� 1byte string�� _T ��ũ�η� 2byte string���� �ٲ㼭 �־���� �Ѵ�

	/* // console â�� ���ؼ� �̺�Ʈ ������ Ȯ���ϴ� ���
	TRACE0("Hello\n"); // debug mode���� �۵��ϴ� �ܼ� â���� ������ִ� ��¹�
	TRACE1("%d", i); // ����� ������ �ϳ��� �� ���
	TRACE2("%d %d", i, j); // ����� ������ �� �� �� �� ���
	*/

	CView::OnLButtonUp(nFlags, point);
}


void CXDrawerView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(currentBox == NULL){
		CView::OnMouseMove(nFlags, point); // �⺻������ �����Ǵ� default ���� ��� ������ �߻��� ���ɼ��� �������
		return;
	}
	CDC* pDC = this->GetDC(); // ���� ȭ���� Device Context �� ������
	int oldMode = pDC->SetROP2(R2_NOTXORPEN);
	CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH);
	currentBox->draw(pDC);
	currentBox->setXY2(point.x, point.y);
	currentBox->draw(pDC);
	pDC->SelectObject(oldBrush);
	pDC->SetROP2(oldMode);
	CView::OnMouseMove(nFlags, point);
}
