
// 01_SineGraphView.cpp: CMy01SineGraphView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "01_SineGraph.h"
#endif

#include "01_SineGraphDoc.h"
#include "01_SineGraphView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 아래는 C#의 형태로 선언했던 X와 Y의 크기들이다
const int XORG = 100; // static 대신 상수라고 선언할 수 있다
const int YORG = 100; // #define을 사용할 수도 있다
const int XMAX = 600;
const int YMAX = 400;
const double PI = 3.1415926535898;

// CMy01SineGraphView

IMPLEMENT_DYNCREATE(CMy01SineGraphView, CView)

BEGIN_MESSAGE_MAP(CMy01SineGraphView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy01SineGraphView 생성/소멸

CMy01SineGraphView::CMy01SineGraphView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy01SineGraphView::~CMy01SineGraphView()
{
}

BOOL CMy01SineGraphView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// 이전 C#에서 SineGraph를 그렸던 함수를 그대로 가져왔다
void drawSine(CDC* pDC) // 클래스 안에서 c처럼 전역함수로 사용하던 static을 삭제하고 Graphics 대신 CDC*를 준다
{
	double x = 0.0;
	// C#과 달리 Math라는 라이브러리 자체가 없기 때문에 PI값을 const 혹은 define을 통해 선언해놓는다
	double step = 2 * PI / XMAX; // 2pi 값을 XMAX값으로 나눈 거

	// Pen pen = new Pen(Color.Black); // C#과 달리 C++은 그릴 때 Pen을 명시할 필요가 없다
	// Pen 객체를 따로 만들어서 selectObject라는 함수와 연결시킨다
	// 까만 펜을 사용할 때는 따로 만들 필요도 없다

	// C#의 DrawLine 함수를 두 개로 나누어 놓은 개념이다
	pDC->MoveTo(XORG, YORG); // pDC 자체가 Pen의 역할을 하니까 pDC를 이동시키는 함수다
	pDC->LineTo(XORG, YORG + YMAX); // pDC의 위치로부터 선을 그린다
	//	pDC.DrawLine(pen, XORG, YORG, XORG, YORG + YMAX);
	
	pDC->MoveTo(XORG, YORG + YMAX / 2); // 시작 좌표 지정
	pDC->LineTo(XORG + XMAX, YORG + YMAX / 2); // pDC위치부터 받은 인자값까지 선을 그린다
	//	pDC.DrawLine(pen, XORG, YORG + YMAX / 2, XORG + XMAX, YORG + YMAX / 2);


	// sin 그래프를 그릴 * 좌표 저장
	for (int i = 0; i < XMAX + 1; i++)
	{
		double y; // 구할 sin 값
		int yPrime;

		y = sin(x); // Math 라이브러리가 없어 system에 정의된 sin 사용
		x += step;

		yPrime = (int)(-(YMAX / 2) * y + (YMAX / 2 + YORG));

		pDC->SetPixel(i + XORG, yPrime, RGB(0,0,0)); // C++는 점을 찍는 함수가 존재해 크기를 줄인 원을 사용할 필요가 없다
		// pDC.DrawEllipse(pen, i + XORG, yPrime, 1, 1); // 사인 그래프를 그릴 점들을 이어보인다
	}

	// c++에서는 font는 필요 없으나 문자열을 그릴 사각형을 잡아주어야 한다
	CRect rect(XORG + 10, YORG + YMAX, XORG + 10 + 100, YORG + YMAX + 100);
	pDC->DrawText(_T("Sine Graph"), 10, &rect, 0); // _T를 통해 문자열을 지정하고 10만큼의 문자열 길이를 지정하며 위치는 rect에 default 값 0

	//pDC.DrawString("Sine Graph", font, brush, XORG + 10, YORG + YMAX);
}

// CMy01SineGraphView 그리기

// CDC = Device Context라고 하고 C#의 Graphics와 역할이 똑같다
void CMy01SineGraphView::OnDraw(CDC* pDC)
{
	CMy01SineGraphDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	drawSine(pDC);
}


// CMy01SineGraphView 인쇄

BOOL CMy01SineGraphView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy01SineGraphView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy01SineGraphView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy01SineGraphView 진단

#ifdef _DEBUG
void CMy01SineGraphView::AssertValid() const
{
	CView::AssertValid();
}

void CMy01SineGraphView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy01SineGraphDoc* CMy01SineGraphView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy01SineGraphDoc)));
	return (CMy01SineGraphDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy01SineGraphView 메시지 처리기
