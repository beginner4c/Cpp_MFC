// ModalDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "XDrawer.h"
#include "ModalDialog.h"
#include "afxdialogex.h"
#include "Box.h"
#include "XDrawerView.h"
#include "XDrawerDoc.h"

// ModalDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(ModalDialog, CDialogEx)

// XDrawerView를 불러오는데 *const 형식으로 불러주어야 한다

ModalDialog::ModalDialog(CXDrawerView *const pView, CWnd* pParent /*=NULL*/)
	: CDialogEx(ModalDialog::IDD, pParent)
	, m_x1(0)
	, m_y1(0)
	, m_x2(_T("")) // 여기서 선언된 CString이 골때린다
	, m_y2(_T(""))
	, m_pView(pView)
{
	// m_pView = pView; // 이렇게 하면 문제가 발생한다
}

ModalDialog::~ModalDialog()
{
}

void ModalDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X1, m_x1);
	DDX_Text(pDX, IDC_EDIT_Y1, m_y1);
	DDX_Text(pDX, IDC_EDIT_X2, m_x2);
	DDX_Text(pDX, IDC_EDIT_Y2, m_y2);
}


BEGIN_MESSAGE_MAP(ModalDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &ModalDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ModalDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// ModalDialog 메시지 처리기입니다.


void ModalDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//	CDialogEx::OnOK(); // default 값으로 누르면 사라진다

	UpdateData(); // 이걸 선언을 해줘야 화면상의 데이터가 메모리 상의 데이터로 이동한다

	int x1 = m_x1;
	int y1 = m_y1;

	// CString은 atoi 혹은 casting으로 바꿔주기도 힘들다
	// CString a("100");
	// CString b("200");
	// a = "300";
	
	int x2 = _ttoi(m_x2); // _ttoi를 통해서 CString을 int 형식으로 바꿀 수 있다
	int y2 = _ttoi(m_y2);

	// TRACE2("%d %d\n", x2, y2);

	Box *pBox = new Box(x1,y1,x2,y2);

	m_pView->GetDocument()->add(pBox);
	m_pView->Invalidate();

	// 아래는 그림을 그리고 나면 화면상 숫자를 0으로 초기화시키는 곳
	m_x1 = 0;
	m_y1 = 0;
	m_x2 = _T("0");
	m_y2 = _T("0");

	UpdateData(FALSE);
}


void ModalDialog::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
	// delete this; // 절대 이렇게 코딩하면 안된다, dangling reference가 발생할 수 있다
}
