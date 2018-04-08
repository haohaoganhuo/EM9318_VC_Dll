// EM9318B_VC_DllDlg.h : ͷ�ļ�
//

#pragma once

#include "ZT_ADDlg.h"
#include "ZT_CTDlg.h"
#include "ZT_ECDlg.h"
#include "ZT_IODlg.h"
#include "ZT_PWMDlg.h"

// CEM9318B_VC_DllDlg �Ի���
class CEM9318B_VC_DllDlg : public CDialog
{
// ����
public:
	CEM9318B_VC_DllDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EM9318B_VC_DLL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	I32 _hDev;
	CString _strIP;
	int _cmdPort;
	int _readInterval;
	int _dataPort;
	CZT_ADDlg _dlgAd;
	CZT_CTDlg _dlgCt;
	CZT_ECDlg _dlgEc;
	CZT_IODlg _dlgIo;
	CZT_PWMDlg _dlgPwm;

	CString _strInfo;
	afx_msg void OnBnClickedConnect();
	void InitTabCtrl();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl _tabCtrl;
	std::vector<CWnd*> _vTAbDlg;
	afx_msg void OnBnClickedDisconnect();
	afx_msg void OnBnClickedButton2();
	bool _showTime;
	void ShowInfo( const char* szFormat, ... );
	void ClearInfo();
	void ReadPara();
	void WritePara();
	afx_msg void OnClose();
};
