#pragma once
#include "EM9118.h"

// CZT_PWMDlg �Ի���
class CEM9318B_VC_DllDlg;
class CZT_PWMDlg : public CDialog
{
	DECLARE_DYNAMIC(CZT_PWMDlg)

public:
	CZT_PWMDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CZT_PWMDlg();

// �Ի�������
	enum { IDD = IDD_PWM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEM9318B_VC_DllDlg* _pF;
	I8 _en[EM9318_MAXPWMCHCNT];
	F64 _freq[EM9318_MAXPWMCHCNT];
	F64 _realFreq[EM9318_MAXPWMCHCNT];
	F64 _duty[EM9318_MAXPWMCHCNT];
	F64 _realDuty[EM9318_MAXPWMCHCNT];
	U32 _count[EM9318_MAXPWMCHCNT];
	I8 _phase[EM9318_MAXPWMCHCNT];
	void GetPara();
	afx_msg void OnBnClickedPwmstart();
	afx_msg void OnBnClickedPwmstop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
};
