// ModalDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "XDrawer.h"
#include "ModalDialog.h"
#include "afxdialogex.h"


// ModalDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(ModalDialog, CDialogEx)

ModalDialog::ModalDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(ModalDialog::IDD, pParent)
	, m_x1(0)
	, m_y1(0)
	, m_x2(_T(""))
	, m_y2(_T(""))
{

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
END_MESSAGE_MAP()


// ModalDialog �޽��� ó�����Դϴ�.


void ModalDialog::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	CDialogEx::OnOK(); // default ������ ������ �������

	
}
