
// MFC_ResearchPalyerDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MFC_ResearchPalyer.h"
#include "MFC_ResearchPalyerDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <thread>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace cv;
using namespace std;
int VideoControl = 0;
// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_ResearchPalyerDlg ��ȭ ����



CMFC_ResearchPalyerDlg::CMFC_ResearchPalyerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_ResearchPalyerDlg::IDD, pParent)
	, m_strEditPath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_ResearchPalyerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_Video_STATIC, m_videoControl);
	DDX_Control(pDX, IDC_PathEDIT, m_ctlEditVideo);
	DDX_Text(pDX, IDC_PathEDIT, m_strEditPath);
	//  DDX_Control(pDX, IDC_VideoCtl, m_VideoCtl);
}

BEGIN_MESSAGE_MAP(CMFC_ResearchPalyerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PathBUTTON, &CMFC_ResearchPalyerDlg::OnBnClickedPathbutton)
	ON_EN_CHANGE(IDC_PathEDIT, &CMFC_ResearchPalyerDlg::OnEnChangePathedit)
	ON_BN_CLICKED(IDC_PlayBtn, &CMFC_ResearchPalyerDlg::OnBnClickedPlaybtn)
	ON_BN_CLICKED(IDC_StopBtn, &CMFC_ResearchPalyerDlg::OnBnClickedStopbtn)
END_MESSAGE_MAP()


// CMFC_ResearchPalyerDlg �޽��� ó����

BOOL CMFC_ResearchPalyerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMFC_ResearchPalyerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFC_ResearchPalyerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFC_ResearchPalyerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


struct ThreadArg
{
	int index;
	CString str;
};

ThreadArg test;

void CMFC_ResearchPalyerDlg::OnBnClickedPathbutton()
{
	//Load File Video Path

	// szFilters is a text string that includes two file name filters: 
	TCHAR szFilters[] = _T("������ ����(*.avi)|*.avi||"); // ���� �ؽ�Ʈ��| �Է� �ؽ�Ʈ��

	CFileDialog fileDlg(TRUE, _T("avi"), _T("*.avi"), //���ܳ��� ���� �Ӽ�
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);

	// Display the file dialog. When user clicks OK, 

	CString pathName;

	fileDlg.DoModal();
		// returns IDOK. 
		if (fileDlg.DoModal() == IDOK)
		{
			pathName = fileDlg.GetPathName(); //������ ������ ���
			// Implement opening and reading file in here. 
			// Change the window's title to the opened file's title.

			LoadVideofile(pathName);

			CString fileName = fileDlg.GetFileTitle(); //���� �̸�
			//SetWindowText(fileName);
		}

		PlayVideofile(pathName);

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CMFC_ResearchPalyerDlg::LoadVideofile(CString pathName)
{
	CString strTmpFileName;

	m_strEditPath = pathName;

	strTmpFileName.Format(_T("%s"), m_strEditPath);

	UpdateData(FALSE);
}


void CMFC_ResearchPalyerDlg::PlayVideofile(CString pathName)
{
	CvCapture* capture = cvCreateFileCapture((CStringA)pathName);
	IplImage* frame;
	char c;


	CWinThread *p1 = NULL;

	test.str = pathName;
	p1 = AfxBeginThread(ThreadProcess, (LPVOID)&test);

	if (p1 == NULL)
	{
		AfxMessageBox(L"Error");
	}

	while (1){
			frame = cvQueryFrame(capture);
			if (!frame) break;
			cvShowImage("Video Play", frame);

			c = cvWaitKey(33);

			if (c == 27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Video Play");
}


UINT CMFC_ResearchPalyerDlg::ThreadProcess(LPVOID ptn)
{
	CMFC_ResearchPalyerDlg *fir = (CMFC_ResearchPalyerDlg*)ptn;
	ThreadArg* item;
	item = (ThreadArg*)ptn;
	CString str;
	char x[50];

	CvCapture* capture = cvCreateFileCapture((CStringA)item->str);
	IplImage *img;

	int count = 0;
	if (capture){
		while (1){
			img = cvQueryFrame(capture);
			if (!img) break;
			sprintf(x, "VideofileCapture\\capture%03d.jpg", count);
			cvSaveImage(x, img);
			cvWaitKey(1);
			count++;
		}
	}
	//cvReleaseCapture(&capture);

	return 0;
}
void CMFC_ResearchPalyerDlg::OnEnChangePathedit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	CString input_value;
	m_ctlEditVideo.GetWindowTextW(m_strEditPath);
	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CMFC_ResearchPalyerDlg::OnBnClickedPlaybtn()
{
	if (VideoControl != 1)
	{
		VideoControl = 1;
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFC_ResearchPalyerDlg::OnBnClickedStopbtn()
{
	if (VideoControl = 1)
	{
		VideoControl = -1;
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
