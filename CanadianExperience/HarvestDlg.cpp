// HarvestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CanadianExperience.h"
#include "HarvestDlg.h"
#include "afxdialogex.h"


// CHarvestDlg dialog

IMPLEMENT_DYNAMIC(CHarvestDlg, CDialog)

CHarvestDlg::CHarvestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHarvestDlg::IDD, pParent)
	, mHarvestFrame(0)
{

}

CHarvestDlg::~CHarvestDlg()
{
}

void CHarvestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mHarvestFrame);
	DDV_MinMaxInt(pDX, mHarvestFrame, 100, 300);
}


BEGIN_MESSAGE_MAP(CHarvestDlg, CDialog)
END_MESSAGE_MAP()


// CHarvestDlg message handlers
