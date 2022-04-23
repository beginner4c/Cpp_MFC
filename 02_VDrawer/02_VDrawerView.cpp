
// 02_VDrawerView.cpp: CMy02VDrawerView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "02_VDrawer.h"
#endif

#include "02_VDrawerDoc.h"
#include "02_VDrawerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02VDrawerView

IMPLEMENT_DYNCREATE(CMy02VDrawerView, CView)

BEGIN_MESSAGE_MAP(CMy02VDrawerView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy02VDrawerView 생성/소멸

CMy02VDrawerView::CMy02VDrawerView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

	sX = sY = eX = eY = 0; // header에서 선언한 것들 초기화
	buttonPressed = FALSE;
}

CMy02VDrawerView::~CMy02VDrawerView()
{
}

BOOL CMy02VDrawerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy02VDrawerView 그리기

void CMy02VDrawerView::OnDraw(CDC* /*pDC*/)
{
	CMy02VDrawerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy02VDrawerView 인쇄

BOOL CMy02VDrawerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy02VDrawerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy02VDrawerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy02VDrawerView 진단

#ifdef _DEBUG
void CMy02VDrawerView::AssertValid() const
{
	CView::AssertValid();
}

void CMy02VDrawerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy02VDrawerDoc* CMy02VDrawerView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02VDrawerDoc)));
	return (CMy02VDrawerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy02VDrawerView 메시지 처리기




void CMy02VDrawerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	// _T를 통해 내용과 메시지 박스 이름 선언
	// ::MessageBox(NULL, _T("hello world"), _T("hi!"), 0);

	sX = eX = point.x;
	sY = eY = point.y;
	buttonPressed = TRUE;

	CView::OnLButtonDown(nFlags, point);
}


void CMy02VDrawerView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (buttonPressed == TRUE) {
		int eX = point.x;
		int eY = point.y;

		// CDC는 C#에서 Graphics 객체의 역할
		CDC* pDC = GetDC();

		// 3개의 Argument 필요(종류, 두께, 색)
		CPen pen(PS_SOLID, 1, RGB(0,0,0));

		pDC->SelectObject(&pen); // pen을 pDC에 등록

		pDC->Rectangle(sX, sY, eX, eY);
	}

	buttonPressed = FALSE;
	CView::OnLButtonUp(nFlags, point);
}


void CMy02VDrawerView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (buttonPressed == TRUE) {
		int newX = point.x;
		int newY = point.y;

		// CDC는 C#에서 Graphics 객체의 역할
		CDC* pDC = GetDC();

		// 3개의 Argument 필요(종류, 두께, 색)
		CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
		CPen erasePen(PS_SOLID, 1, RGB(255, 255, 255));
		
		pDC->SelectObject(&erasePen);
		pDC->Rectangle(sX, sY, eX, eY);
		
		pDC->SelectObject(&pen); // pen을 pDC에 등록
		pDC->Rectangle(sX, sY, newX, newY); // C++의 pen에는 nullBrush가 장착되어 있어 C#과는 다르게 지워진다

		eX = newX;
		eY = newY;
	}

	CView::OnMouseMove(nFlags, point);
}
