
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
#include "Box.h" // 헤더 파일과 다르게 include가 필요하다

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
END_MESSAGE_MAP()

// CXDrawerView 생성/소멸

CXDrawerView::CXDrawerView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	currentBox = NULL;

	
}

CXDrawerView::~CXDrawerView()
{
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
	for(int i =0;i<pDoc->boxCount(); i++){ // paint 이벤트가 호출될 때 저장된 박스를 다시 그리기
		pDoc->getBox(i)->draw(pDC);
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
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
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

	currentBox = new Box(point.x, point.y);
	CDC *pDC = GetDC();
	currentBox->draw(pDC);
	CView::OnLButtonDown(nFlags, point);
}


void CXDrawerView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(currentBox != NULL){
		CDC* pDC = this->GetDC(); // 현재 화면의 Device Context 를 가져옴
		CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH); // Null Brush 세팅
		currentBox->setXY2(point.x, point.y); // x2, y2 좌표 세팅
		currentBox->draw(pDC); // 사각형 그리기
		pDC->SelectObject(oldBrush); // Brush default 값으로 되돌리기

		CXDrawerDoc *pDoc = GetDocument();
		pDoc->boxes[pDoc->nBox++] = currentBox;
		pDoc->add(currentBox);
	}
	currentBox = NULL;

	// 메시지박스를 통해 이벤트 실행을 확인
	// MessageBox(_T("Hello"),_T("World"), 0); // 일반 1byte string을 _T 매크로로 2byte string으로 바꿔서 넣어줘야 한다

	/* // console 창을 통해서 이벤트 실행을 확인하는 방법
	TRACE0("Hello\n"); // debug mode에서 작동하는 콘솔 창에서 출력해주는 출력문
	TRACE1("%d", i); // 출력할 정수가 하나일 때 사용
	TRACE2("%d %d", i, j); // 출력할 정수가 두 개 일 때 사용
	*/

	CView::OnLButtonUp(nFlags, point);
}


void CXDrawerView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(currentBox == NULL){
		CView::OnMouseMove(nFlags, point); // 기본적으로 제공되는 default 값을 줘야 문제가 발생할 가능성이 사라진다
		return;
	}
	CDC* pDC = this->GetDC(); // 현재 화면의 Device Context 를 가져옴
	int oldMode = pDC->SetROP2(R2_NOTXORPEN);
	CGdiObject *oldBrush = pDC->SelectStockObject(NULL_BRUSH);
	currentBox->draw(pDC);
	currentBox->setXY2(point.x, point.y);
	currentBox->draw(pDC);
	pDC->SelectObject(oldBrush);
	pDC->SetROP2(oldMode);
	CView::OnMouseMove(nFlags, point);
}
