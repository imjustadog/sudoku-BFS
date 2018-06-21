// SearchTreeDlg.h : header file
//

#if !defined(AFX_SEARCHTREEDLG_H__197102C7_D2DF_4D16_9B95_093AE243086C__INCLUDED_)
#define AFX_SEARCHTREEDLG_H__197102C7_D2DF_4D16_9B95_093AE243086C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define LEN sizeof(struct NineNode)
/////////////////////////////////////////////////////////////////////////////
// CSearchTreeDlg dialog

class CSearchTreeDlg : public CDialog
{
// Construction
public:
	CSearchTreeDlg(CWnd* pParent = NULL);	// standard constructor
	char Direct[4];
	typedef struct NineNode     //定义双向链表的结构
	{
		char Nine[3][3];
		char X,Y,D;       //数据域
		struct NineNode *prior,*next;//前项指针和后项指针
	}*NineLink;
	NineLink head,tail;
	bool Judge();
	bool Exchange(char, char, char);
	void CreateNineLink();
// Dialog Data
	//{{AFX_DATA(CSearchTreeDlg)
	enum { IDD = IDD_SEARCHTREE_DIALOG };
	int		m_strNine1;
	int		m_strNine2;
	int		m_strNine3;
	int		m_strNine4;
	int		m_strNine5;
	int		m_strNine6;
	int		m_strNine7;
	int		m_strNine8;
	int		m_strNine9;
	int		m_strCount;
	int		m_strTimes;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchTreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSearchTreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonSolve();
	afx_msg void OnButtonNext();
	afx_msg void OnButtonAgain();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHTREEDLG_H__197102C7_D2DF_4D16_9B95_093AE243086C__INCLUDED_)
