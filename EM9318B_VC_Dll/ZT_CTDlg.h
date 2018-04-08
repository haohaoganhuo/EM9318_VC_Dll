#pragma once

#include "EM9118.h"
// CZT_CTDlg �Ի���

class CEM9318B_VC_DllDlg;

class CZT_CTDlg : public CDialog
{
	DECLARE_DYNAMIC(CZT_CTDlg)

public:
	CZT_CTDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CZT_CTDlg();

// �Ի�������
	enum { IDD = IDD_CT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEM9318B_VC_DllDlg* _pF;
	int		_cntMode;
	F64 _ctBaseMS[EM9118_MAXCTCHCNT];
	BOOL _isCtInFifo[EM9118_MAXCTCHCNT];
	BOOL _isCt;
	afx_msg void OnBnClickedSetcnt();
	afx_msg void OnBnClickedIsct();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void ShowCtValue( I32 chInx, F64 ctCode );
	afx_msg void OnBnClickedCtclear();
};
