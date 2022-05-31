
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
#include "Figure.h"
#include "Box.h" // ��� ���ϰ� �ٸ��� include�� �ʿ��ϴ�
#include "Line.h"
#include "Circle.h"
#include "Diamond.h"
#include "X.h"
#include "Bubble.h"
#include "FigureList.h"
#include "ModalDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define DRAW_X			(1)
#define DRAW_BOX		(2)
#define DRAW_LINE		(3)
#define DRAW_CIRCLE		(4)
#define DRAW_DIAMOND	(5)
#define DRAW_BUBBLE		(6)


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
	ON_COMMAND(ID_OBJECT_BOX, &CXDrawerView::OnObjectBox)
	ON_COMMAND(ID_OBJECT_LINE, &CXDrawerView::OnObjectLine)
	ON_COMMAND(ID_OBJECT_CIRCLE, &CXDrawerView::OnObjectCircle)
	ON_COMMAND(ID_OBJECT_DIAMOND, &CXDrawerView::OnObjectDiamond)
	ON_COMMAND(ID_OBJECT_X, &CXDrawerView::OnObjectX)
	ON_COMMAND(ID_OBJECT_BUBBLE, &CXDrawerView::OnObjectBubble)
	ON_COMMAND(ID_MODAL_DIALOG, &CXDrawerView::OnModalDialog)
	ON_COMMAND(ID_MODALESS_DIALOG, &CXDrawerView::OnModalessDialog)
END_MESSAGE_MAP()

// CXDrawerView ����/�Ҹ�

CXDrawerView::CXDrawerView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	currentFigure = NULL;
	whatToDraw = DRAW_BOX; // Default ���� �簢���� �׸���
	pDlg = new ModalDialog(this);

	//::MessageBox(NULL, _T("CXDrawerView"), _T("CXDrawerView"),0);
}

CXDrawerView::~CXDrawerView()
{
	//::MessageBox(NULL, _T("~CXDrawerView"), _T("~CXDrawerView"),0);
	if(pDlg!= NULL)
		delete pDlg;
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
	
	FigureList *list = pDoc->getFigures(); // Generic class �� �ƴ϶� type casting�� �ʿ�������

	// �ƹ��ų� ����Ű�� Pointer POSITION
	POSITION pos = list->GetHeadPosition(); // figures ����Ʈ�� ��� ��ġ�� �����ϴ� ��ü ����

	while(pos != NULL){
		// generic class�� ���� �ʱ� ������ �߻��ϴ� traverse ���
		Figure *ptr = list->GetNext(pos); // reference type�� ����߱� ������ pos�� ���� �ٲ� �� �ִ�
		ptr->draw(pDC);
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
	/*
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_MAINFRAME, point.x, point.y, this, TRUE);
#endif
	*/
	/* // Two Phase Consturction, ���ҽ��� �޴��� ����� ���
	CMenu mainMenu;
	mainMenu.LoadMenuW(IDR_MAINFRAME);

	CMenu *subMenu = mainMenu.GetSubMenu(3);
	subMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
		point.x, point.y, this, NULL);
	*/
	
	CMenu mainMenu;
	mainMenu.CreatePopupMenu();
	mainMenu.AppendMenuW(MF_STRING, 0, _T("�׸�"));
	mainMenu.AppendMenuW(MF_SEPARATOR);
	mainMenu.AppendMenuW(MF_STRING, ID_OBJECT_BOX, _T("�簢��"));
	mainMenu.AppendMenuW(MF_STRING, ID_OBJECT_LINE, _T("��"));
	mainMenu.AppendMenuW(MF_STRING, ID_OBJECT_CIRCLE, _T("��"));
	mainMenu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
		point.x, point.y, this, NULL);
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

	CDC *pDC = GetDC();
	if(whatToDraw == DRAW_X) 
	{
		currentFigure = new X(point.x, point.y);
	}
	else if(whatToDraw == DRAW_BOX) 
	{
		currentFigure = new Box(point.x, point.y);
	} 
	else if (whatToDraw == DRAW_LINE) 
	{
		currentFigure = new Line(point.x, point.y);
	} 
	else if (whatToDraw == DRAW_CIRCLE) 
	{
		currentFigure = new Circle(point.x, point.y);
	} 
	else if (whatToDraw == DRAW_DIAMOND) 
	{
		currentFigure = new Diamond(point.x, point.y);
	}
	else if (whatToDraw == DRAW_BUBBLE) 
	{
		currentFigure = new Bubble(point.x, point.y);
	}

	currentFigure->draw(pDC);

	CView::OnLButtonDown(nFlags, point);
}


void CXDrawerView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(currentFigure != NULL){
		CDC* pDC = this->GetDC(); // ���� ȭ���� Device Context �� ������
		CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH); // Null Brush ����
		currentFigure->setXY2(point.x, point.y); // x2, y2 ��ǥ ����
		currentFigure->draw(pDC); // �׸� �׸���
		pDC->SelectObject(oldBrush); // Brush default ������ �ǵ�����

		CXDrawerDoc *pDoc = GetDocument();
		pDoc->add(currentFigure);

		pDoc->SetModifiedFlag(TRUE); // �̰͸� ȣ���ϸ� ��������� �ִ� ��� ���� ���� �޽��� �ڽ��� ���

	}

	currentFigure = NULL;

	// �޽����ڽ��� ���� �̺�Ʈ ������ Ȯ��
	// MessageBox(_T("Hello"),_T("World"), 0); // �Ϲ� 1byte string�� _T ��ũ�η� 2byte string���� �ٲ㼭 �־���� �Ѵ�

	/* // console â�� ���ؼ� �̺�Ʈ ������ Ȯ���ϴ� ���
	TRACE0("Hello\n"); // debug mode���� �۵��ϴ� �ܼ� â���� ������ִ� ��¹�
	TRACE1("%d", i); // ����� ������ �ϳ��� �� ���
	TRACE2("%d %d", i, j); // ����� ������ �� �� �� �� ���
	*/

	Invalidate();// ȭ���� �����ؼ� rubber banding�� �ܻ��� ����� �� �ִ�

	CView::OnLButtonUp(nFlags, point);
}


void CXDrawerView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(currentFigure != NULL){ // �簢���� RUBBER BANDING
		CDC* pDC = this->GetDC(); // ���� ȭ���� Device Context �� ������
		int oldMode = pDC->SetROP2(R2_NOTXORPEN);
		CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH);
		currentFigure->draw(pDC);
		currentFigure->setXY2(point.x, point.y);
		currentFigure->draw(pDC);
		pDC->SelectObject(oldBrush);
		pDC->SetROP2(oldMode);
		CView::OnMouseMove(nFlags, point);
	}

	CView::OnMouseMove(nFlags, point); // �⺻������ �����Ǵ� default ���� ��� ������ �߻��� ���ɼ��� �������
}

// whatToDraw�� �����ؼ� �� �׸��� ���ϴ� ��
void CXDrawerView::OnObjectBox()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	// ::MessageBox(NULL,_T("Hello"),_T("Box"),0); // Ȯ�ο�
	whatToDraw = DRAW_BOX;
}


void CXDrawerView::OnObjectLine()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	whatToDraw = DRAW_LINE;
}


void CXDrawerView::OnObjectCircle()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	whatToDraw = DRAW_CIRCLE;
}


void CXDrawerView::OnObjectDiamond()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	whatToDraw = DRAW_DIAMOND;
}


void CXDrawerView::OnObjectX()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	whatToDraw = DRAW_X;
}


void CXDrawerView::OnObjectBubble()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	whatToDraw = DRAW_BUBBLE;
}


void CXDrawerView::OnModalDialog()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	// Modal Dialog�� ��� Automatic Allocation�� �⺻���� �Ѵ�
	ModalDialog aDlg(this);
	aDlg.DoModal();
}


void CXDrawerView::OnModalessDialog()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	// Modaless Dialog�� Dynamic Allocation�� �⺻���� �Ѵ�

	pDlg->ShowWindow(SW_SHOW);
}


BOOL CXDrawerView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	pDlg->Create(ModalDialog::IDD); // ���ҽ��� �ε��ϴ� ����
	return CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
