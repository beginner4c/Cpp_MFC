
// XDrawerView.cpp : CXDrawerView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "XDrawer.h"
#endif

#include "XDrawerDoc.h"
#include "XDrawerView.h"
#include "Figure.h"
#include "Box.h" // 헤더 파일과 다르게 include가 필요하다
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
	// 표준 인쇄 명령입니다.
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

// CXDrawerView 생성/소멸

CXDrawerView::CXDrawerView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	currentFigure = NULL;
	whatToDraw = DRAW_BOX; // Default 값은 사각형을 그리게
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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CXDrawerView 그리기

void CXDrawerView::OnDraw(CDC* pDC) // 화면 갱신되었을 때 초기 화면을 보여준다
{
	CXDrawerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH); // Null Brush 세팅
	
	FigureList *list = pDoc->getFigures(); // Generic class 가 아니라 type casting이 필요해진다

	// 아무거나 가르키는 Pointer POSITION
	POSITION pos = list->GetHeadPosition(); // figures 리스트의 헤드 위치를 저장하는 객체 생성

	while(pos != NULL){
		// generic class를 쓰지 않기 때문에 발생하는 traverse 방식
		Figure *ptr = list->GetNext(pos); // reference type을 사용했기 때문에 pos의 값이 바뀔 수 있다
		ptr->draw(pDC);
	}
	
	pDC->SelectObject(oldBrush);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	/*
	// NULL Brush
	pDC->SelectStockObject(NULL_BRUSH); // 뒤에 도형을 삭제하는 브러쉬를 제거

	// 원 그리기
	pDC->Ellipse(100,100,200,200);

	// 파란색 선의 사각형 그리기
	CPen pen(PS_SOLID, 3, RGB(0,0,255)); // 실선에 두께가 3인 파란 펜을 생성
	CPen *oldPen = pDC->SelectObject(&pen); // 기본 펜에 파란색을 더해줌
	pDC->Rectangle(100,100,200,200);
	pDC->SelectObject(oldPen); // 원래의 펜으로 돌려줌

	// line그리기
	pDC->MoveTo(300,300);
	pDC->LineTo(100,100);
	CPen pen2(PS_SOLID, 1, RGB(0,0,0)); // 실선 두께 1 검정 펜 생성
	pDC->SelectObject(&pen2); // 펜 할당
	pDC->MoveTo(300,300);
	pDC->LineTo(500,500);



	// 색이 채워진 사각형 그리기
	CRect rect(50,50,100,100);
	CBrush br(RGB(255,0,0));
	pDC->FillRect(&rect, &br);
	*/
}


// CXDrawerView 인쇄


void CXDrawerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CXDrawerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CXDrawerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CXDrawerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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
	/* // Two Phase Consturction, 리소스로 메뉴를 만드는 방법
	CMenu mainMenu;
	mainMenu.LoadMenuW(IDR_MAINFRAME);

	CMenu *subMenu = mainMenu.GetSubMenu(3);
	subMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
		point.x, point.y, this, NULL);
	*/
	
	CMenu mainMenu;
	mainMenu.CreatePopupMenu();
	mainMenu.AppendMenuW(MF_STRING, 0, _T("그림"));
	mainMenu.AppendMenuW(MF_SEPARATOR);
	mainMenu.AppendMenuW(MF_STRING, ID_OBJECT_BOX, _T("사각형"));
	mainMenu.AppendMenuW(MF_STRING, ID_OBJECT_LINE, _T("선"));
	mainMenu.AppendMenuW(MF_STRING, ID_OBJECT_CIRCLE, _T("원"));
	mainMenu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
		point.x, point.y, this, NULL);
}


// CXDrawerView 진단

#ifdef _DEBUG
void CXDrawerView::AssertValid() const
{
	CView::AssertValid();
}

void CXDrawerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CXDrawerDoc* CXDrawerView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CXDrawerDoc)));
	return (CXDrawerDoc*)m_pDocument;
}
#endif //_DEBUG


// CXDrawerView 메시지 처리기


void CXDrawerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(currentFigure != NULL){
		CDC* pDC = this->GetDC(); // 현재 화면의 Device Context 를 가져옴
		CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH); // Null Brush 세팅
		currentFigure->setXY2(point.x, point.y); // x2, y2 좌표 세팅
		currentFigure->draw(pDC); // 그림 그리기
		pDC->SelectObject(oldBrush); // Brush default 값으로 되돌리기

		CXDrawerDoc *pDoc = GetDocument();
		pDoc->add(currentFigure);

		pDoc->SetModifiedFlag(TRUE); // 이것만 호출하면 변경사항이 있는 경우 저장 관련 메시지 박스가 뜬다

	}

	currentFigure = NULL;

	// 메시지박스를 통해 이벤트 실행을 확인
	// MessageBox(_T("Hello"),_T("World"), 0); // 일반 1byte string을 _T 매크로로 2byte string으로 바꿔서 넣어줘야 한다

	/* // console 창을 통해서 이벤트 실행을 확인하는 방법
	TRACE0("Hello\n"); // debug mode에서 작동하는 콘솔 창에서 출력해주는 출력문
	TRACE1("%d", i); // 출력할 정수가 하나일 때 사용
	TRACE2("%d %d", i, j); // 출력할 정수가 두 개 일 때 사용
	*/

	Invalidate();// 화면을 갱신해서 rubber banding의 잔상을 잡아줄 수 있다

	CView::OnLButtonUp(nFlags, point);
}


void CXDrawerView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(currentFigure != NULL){ // 사각형의 RUBBER BANDING
		CDC* pDC = this->GetDC(); // 현재 화면의 Device Context 를 가져옴
		int oldMode = pDC->SetROP2(R2_NOTXORPEN);
		CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH);
		currentFigure->draw(pDC);
		currentFigure->setXY2(point.x, point.y);
		currentFigure->draw(pDC);
		pDC->SelectObject(oldBrush);
		pDC->SetROP2(oldMode);
		CView::OnMouseMove(nFlags, point);
	}

	CView::OnMouseMove(nFlags, point); // 기본적으로 제공되는 default 값을 줘야 문제가 발생할 가능성이 사라진다
}

// whatToDraw를 세팅해서 뭘 그릴지 정하는 곳
void CXDrawerView::OnObjectBox()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// ::MessageBox(NULL,_T("Hello"),_T("Box"),0); // 확인용
	whatToDraw = DRAW_BOX;
}


void CXDrawerView::OnObjectLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_LINE;
}


void CXDrawerView::OnObjectCircle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_CIRCLE;
}


void CXDrawerView::OnObjectDiamond()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_DIAMOND;
}


void CXDrawerView::OnObjectX()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_X;
}


void CXDrawerView::OnObjectBubble()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	whatToDraw = DRAW_BUBBLE;
}


void CXDrawerView::OnModalDialog()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// Modal Dialog의 경우 Automatic Allocation을 기본으로 한다
	ModalDialog aDlg(this);
	aDlg.DoModal();
}


void CXDrawerView::OnModalessDialog()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// Modaless Dialog는 Dynamic Allocation을 기본으로 한다

	pDlg->ShowWindow(SW_SHOW);
}


BOOL CXDrawerView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	pDlg->Create(ModalDialog::IDD); // 리소스를 로드하는 과정
	return CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
