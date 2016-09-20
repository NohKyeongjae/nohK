
// MFC_ResearchPalyerDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CMFC_ResearchPalyerDlg ��ȭ ����
class CMFC_ResearchPalyerDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFC_ResearchPalyerDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MFC_RESEARCHPALYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CString m_strEditPath;

public:
//	CStatic m_videoControl;
	afx_msg void OnBnClickedPathbutton();
	CEdit m_ctlEditVideo;
	afx_msg void OnEnChangePathedit();

public:
	void LoadVideofile(CString parentPath);
	void PlayVideofile(CString parentPath);
	static UINT ThreadProcess(LPVOID ptn);

//	CVideoctl m_VideoCtl;
	afx_msg void OnBnClickedPlaybtn();
	afx_msg void OnBnClickedStopbtn();
};
