
// MFC_ResearchPalyerDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CMFC_ResearchPalyerDlg 대화 상자
class CMFC_ResearchPalyerDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFC_ResearchPalyerDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MFC_RESEARCHPALYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
