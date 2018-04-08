// ZT_IODlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EM9318B_VC_Dll.h"
#include "ZT_IODlg.h"
#include "EM9318B_VC_DllDlg.h"


// CZT_IODlg �Ի���

IMPLEMENT_DYNAMIC(CZT_IODlg, CDialog)

CZT_IODlg::CZT_IODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZT_IODlg::IDD, pParent)
	, _isDi(FALSE)
	, _isIoInFifo(FALSE)
{
	memset( _do, 0, sizeof(_do) );
}

CZT_IODlg::~CZT_IODlg()
{
}

void CZT_IODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_ISDI, _isDi);
	DDX_Check(pDX, IDC_CHKIOINFIFO, _isIoInFifo);
}


BEGIN_MESSAGE_MAP(CZT_IODlg, CDialog)
	ON_BN_CLICKED(IDC_ISDI, &CZT_IODlg::OnBnClickedIsdi)
	ON_WM_TIMER()
	ON_CONTROL_RANGE(BN_CLICKED,IDC_IO1,IDC_IO8,OnIo)
	ON_CONTROL_RANGE(CBN_SELCHANGE,IDC_IOMODE1,IDC_IOMODE8,OnIoMode)
END_MESSAGE_MAP()


// CZT_IODlg ��Ϣ�������

void CZT_IODlg::OnBnClickedIsdi()
{
	UpdateData( TRUE );
	if( _isDi )
	{
		SetTimer( 1, _pF->_readInterval, 0 );
	}else
	{
		KillTimer( 1 );
	}	
}

void CZT_IODlg::OnTimer(UINT_PTR nIDEvent)
{
	I8 iStatus[8];
	I32 ret = EM9318_IoGetAll( _pF->_hDev, iStatus );
	if( ret < 0 )
		_pF->ShowInfo( "EM9318_IoGetAll��%d\n", ret );
	for( int i = 0; i < EM9318_MAXIOCHCNT; ++i )
	{
		((CButton*)(GetDlgItem( IDC_IO1 + i )))->SetCheck( iStatus[i] );
	}

	CDialog::OnTimer(nIDEvent);
}

void CZT_IODlg::OnIo(UINT uiID)
{
	//���������
	CButton* bt = (CButton*)GetDlgItem( uiID );
	_do[uiID - IDC_IO1] = bt->GetCheck();
	I32 ret = EM9318_IoSetAll( _pF->_hDev, _do );
	if( ret < 0 )
		_pF->ShowInfo( "EM9318_IoSetAll��%d\n", ret );
}

void CZT_IODlg::OnIoMode(UINT uiID)
{
	//���������
	CComboBox* bt = (CComboBox*)GetDlgItem( uiID );
	I32 chNo = uiID - IDC_IOMODE1 + 1; 
	I8 ioMode = bt->GetCurSel();
	I32 ret = EM9318_IoSetMode( _pF->_hDev, chNo, ioMode );
	if( ret < 0 )
		_pF->ShowInfo( "EM9318_IoSetMode��%d\n", ret );
}
BOOL CZT_IODlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	for( I32 i = 0; i < EM9318_MAXIOCHCNT; ++i )
	{
		((CComboBox*)GetDlgItem(IDC_IOMODE1 + i))->SetCurSel( 0 );
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}