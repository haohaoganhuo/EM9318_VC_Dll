// EM9318B_VC_DllDlg.h : 头文件
//

#pragma once

#include "ZT_ADDlg.h"
#include "ZT_CTDlg.h"
#include "ZT_ECDlg.h"
#include "ZT_IODlg.h"
#include "ZT_PWMDlg.h"

// CEM9318B_VC_DllDlg 对话框
class CEM9318B_VC_DllDlg : public CDialog
{
// 构造
public:
	CEM9318B_VC_DllDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EM9318B_VC_DLL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
