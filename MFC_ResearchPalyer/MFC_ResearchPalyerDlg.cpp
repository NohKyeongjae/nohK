
// MFC_ResearchPalyerDlg.cpp : 구현 파일
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
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFC_ResearchPalyerDlg 대화 상자



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


// CMFC_ResearchPalyerDlg 메시지 처리기

BOOL CMFC_ResearchPalyerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFC_ResearchPalyerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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
	TCHAR szFilters[] = _T("동영상 파일(*.avi)|*.avi||"); // 보기 텍스트란| 입력 텍스트란

	CFileDialog fileDlg(TRUE, _T("avi"), _T("*.avi"), //생겨나는 파일 속성
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);

	// Display the file dialog. When user clicks OK, 

	CString pathName;

	fileDlg.DoModal();
		// returns IDOK. 
		if (fileDlg.DoModal() == IDOK)
		{
			pathName = fileDlg.GetPathName(); //선택한 파일의 경로
			// Implement opening and reading file in here. 
			// Change the window's title to the opened file's title.

			LoadVideofile(pathName);

			CString fileName = fileDlg.GetFileTitle(); //파일 이름
			//SetWindowText(fileName);
		}

		PlayVideofile(pathName);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	CString input_value;
	m_ctlEditVideo.GetWindowTextW(m_strEditPath);
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMFC_ResearchPalyerDlg::OnBnClickedPlaybtn()
{
	if (VideoControl != 1)
	{
		VideoControl = 1;
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFC_ResearchPalyerDlg::OnBnClickedStopbtn()
{
	if (VideoControl = 1)
	{
		VideoControl = -1;
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
