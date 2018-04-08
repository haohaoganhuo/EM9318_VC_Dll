// ZT_PWMDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EM9318B_VC_Dll.h"
#include "ZT_PWMDlg.h"
#include "EM9318B_VC_DllDlg.h"


// CZT_PWMDlg �Ի���

IMPLEMENT_DYNAMIC(CZT_PWMDlg, CDialog)

CZT_PWMDlg::CZT_PWMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZT_PWMDlg::IDD, pParent)
{
	for( int chInx = 0; chInx < EM9318_MAXPWMCHCNT; ++chInx )
	{
		_en[chInx] = 1;
		_freq[chInx] = 10000;
		_realFreq[chInx] = 10000;
		_duty[chInx] = 0.5;
		_realFreq[chInx] = 0.5;
		_count[chInx] = 0;
		_phase[chInx] = 0;
	}
}

CZT_PWMDlg::~CZT_PWMDlg()
{
}

void CZT_PWMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CZT_PWMDlg, CDialog)
	ON_BN_CLICKED(IDC_PWMSTART, &CZT_PWMDlg::OnBnClickedPwmstart)
	ON_BN_CLICKED(IDC_PWMSTOP, &CZT_PWMDlg::OnBnClickedPwmstop)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CZT_PWMDlg ��Ϣ�������

void CZT_PWMDlg::GetPara()
{
	int chInx = 0;
	for( chInx = 0; chInx < EM9318_MAXPWMCHCNT; ++chInx )
	{
		CString str;
		//�õ�Ƶ������ֵ
		GetDlgItem( IDC_FREQ1 + chInx )->GetWindowText( str );
		_freq[chInx] = atof( str );
		//�õ�ռ�ձ�����ֵ
		GetDlgItem( IDC_DUTY1 + chInx )->GetWindowText( str );
		_duty[chInx] = atof( str ) / 100;//�ӰٷֱȻ����С��
		//�õ��Ƿ��ӳ�90��
		_phase[chInx] = ((CButton*)GetDlgItem(IDC_PWMPHASE1 + chInx))->GetCheck();
		//�õ���Ҫ����������������Ϊ0�����ʾһֱ���
		GetDlgItem( IDC_PWMCNT1 + chInx )->GetWindowText( str );
		_count[chInx] = atol( str );
		//�õ���Ӧͨ����PWM�Ƿ���Ҫ�������
		_en[chInx] = ((CButton*)GetDlgItem(IDC_PWMEN1 + chInx))->GetCheck();
	}
}

void CZT_PWMDlg::OnBnClickedPwmstart()
{
	GetPara();
	I32 ret;
	for( int chInx = 0; chInx < EM9318_MAXPWMCHCNT; ++chInx )
	{
		//�����������
		ret = EM9318_PwmSetCount( _pF->_hDev, chInx + 1, _count[chInx] );
		if( ret < 0 )
		{
			_pF->ShowInfo( "EM9318_PwmSetCount��chInx:%d, %d\n", chInx, ret );
			break;
		}
		//��������Ƶ�ʺ�ռ�ձ�
		ret = EM9318_PwmSetPulse( _pF->_hDev, chInx + 1, _freq[chInx], _duty[chInx], &_realFreq[chInx], &_realDuty[chInx] );
		if( ret < 0 )
		{
			_pF->ShowInfo( "EM9318_PwmSetPulse��chInx:%d, %d\n", chInx, ret );
			break;
		}

		//���������ֻ�������ֵ������������ֵ�п��ܲ�һ�¡�
		CString str;
		str.Format( "%0.3f", _realFreq[chInx] );
		GetDlgItem( IDC_REALFREQ1 + chInx )->SetWindowText( str );
		str.Format( "%0.3f", _realDuty[chInx] * 100 );
		GetDlgItem( IDC_REALDUTY1 + chInx )->SetWindowText( str );
	}
	ret = EM9318_PwmStartAll( _pF->_hDev, _en, _phase );
	if( ret < 0 )
		_pF->ShowInfo( "EM9318_IoSetAll��%d\n", ret );

	GetDlgItem( IDC_PWMSTART )->EnableWindow( TRUE );
	GetDlgItem( IDC_PWMSTOP )->EnableWindow( TRUE );
	SetTimer( 1, 100, NULL );
}

void CZT_PWMDlg::OnBnClickedPwmstop()
{
	I8 en[EM9318_MAXPWMCHCNT];
	//ֹͣPWM���
	memset( en, 0, sizeof(en) );
	I32 ret = EM9318_PwmStartAll( _pF->_hDev, en, _phase );
	if( ret < 0 )
		_pF->ShowInfo( "EM9318_PwmStartAll��%d\n", ret );
	KillTimer( 1 );

	GetDlgItem( IDC_PWMSTART )->EnableWindow( TRUE );
	GetDlgItem( IDC_PWMSTOP )->EnableWindow( FALSE );
}

void CZT_PWMDlg::OnTimer(UINT_PTR nIDEvent)
{
	I8 isOver[EM9318_MAXPWMCHCNT];
	I32 ret = EM9318_PwmIsOver( _pF->_hDev, isOver );
	if( ret < 0 )
		_pF->ShowInfo( "EM9318_PwmIsOver��%d\n", ret );
	for( I32 i = 0; i < EM9318_MAXPWMCHCNT; ++i )
		((CButton*)GetDlgItem( IDC_PWMOVER1 + i ))->SetCheck( isOver[i] );

	CDialog::OnTimer(nIDEvent);
}

BOOL CZT_PWMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	for( int i = 0; i < EM9318_MAXPWMCHCNT; ++i )
	{
		((CButton*)GetDlgItem(IDC_PWMEN1 + i))->SetCheck( _en[i] );
		CString str;
		str.Format( "%0.0f", _freq[i] );
		GetDlgItem( IDC_FREQ1 + i )->SetWindowText( str );
		GetDlgItem( IDC_REALFREQ1 + i )->SetWindowText( str );
		str.Format( "%0.0f", _duty[i] * 100 );
		GetDlgItem( IDC_DUTY1 + i )->SetWindowText( str );
		GetDlgItem( IDC_REALDUTY1 + i )->SetWindowText( str );
		str.Format( "%u", _count[i] );
		GetDlgItem( IDC_PWMCNT1 + i )->SetWindowText( str );

		((CButton*)GetDlgItem(IDC_PWMOVER1 + i))->SetCheck( _phase[i] );
	}

	GetDlgItem( IDC_PWMSTART )->EnableWindow( TRUE );
	GetDlgItem( IDC_PWMSTOP )->EnableWindow( FALSE );

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
