// CHM2Dlg.h : header file
//

#if !defined(AFX_CHM2DLG_H__6B1D7A66_893C_4587_91A9_ACC2FF06510D__INCLUDED_)
#define AFX_CHM2DLG_H__6B1D7A66_893C_4587_91A9_ACC2FF06510D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NewWizDialog.h"
#include "WizardData.h"
#include "ServiceManager.h"

/////////////////////////////////////////////////////////////////////////////
// CCHM2Dlg dialog

class CCHM2Dlg : public CNewWizDialog
{
// Construction
public:
	CFont m_fontTitle;
	CWizardData* m_pWizardData;
	CServiceManager* m_pServiceManager;
	CCHM2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCHM2Dlg)
	enum { IDD = IDD_CHM2_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCHM2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCHM2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHM2DLG_H__6B1D7A66_893C_4587_91A9_ACC2FF06510D__INCLUDED_)
