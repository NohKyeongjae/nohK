
// MFC_ResearchPalyer.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFC_ResearchPalyerApp:
// �� Ŭ������ ������ ���ؼ��� MFC_ResearchPalyer.cpp�� �����Ͻʽÿ�.
//

class CMFC_ResearchPalyerApp : public CWinApp
{
public:
	CMFC_ResearchPalyerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFC_ResearchPalyerApp theApp;