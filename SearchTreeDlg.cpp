// SearchTreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SearchTree.h"
#include "SearchTreeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchTreeDlg dialog

CSearchTreeDlg::CSearchTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchTreeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchTreeDlg)
	m_strNine1 = 0;
	m_strNine2 = 0;
	m_strNine3 = 0;
	m_strNine4 = 0;
	m_strNine5 = 0;
	m_strNine6 = 0;
	m_strNine7 = 0;
	m_strNine8 = 0;
	m_strNine9 = 0;
	m_strCount = 0;
	m_strTimes = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSearchTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchTreeDlg)
	DDX_Text(pDX, IDC_EDIT_NINE1, m_strNine1);
	DDX_Text(pDX, IDC_EDIT_NINE2, m_strNine2);
	DDX_Text(pDX, IDC_EDIT_NINE3, m_strNine3);
	DDX_Text(pDX, IDC_EDIT_NINE4, m_strNine4);
	DDX_Text(pDX, IDC_EDIT_NINE5, m_strNine5);
	DDX_Text(pDX, IDC_EDIT_NINE6, m_strNine6);
	DDX_Text(pDX, IDC_EDIT_NINE7, m_strNine7);
	DDX_Text(pDX, IDC_EDIT_NINE8, m_strNine8);
	DDX_Text(pDX, IDC_EDIT_NINE9, m_strNine9);
	DDX_Text(pDX, IDC_EDIT_COUNT, m_strCount);
	DDX_Text(pDX, IDC_EDIT_TIMES, m_strTimes);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSearchTreeDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchTreeDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SOLVE, OnButtonSolve)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_AGAIN, OnButtonAgain)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchTreeDlg message handlers

BOOL CSearchTreeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSearchTreeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSearchTreeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

bool CSearchTreeDlg::Judge() 
{
	// TODO: Add your control notification handler code here
	if(head->Nine[0][0] == 1 && head->Nine[0][1] == 2 && head->Nine[0][2] == 3 && head->Nine[1][0] == 8 && head->Nine[1][1] == 0 && head->Nine[1][2] == 4 && head->Nine[2][0] == 7 && head->Nine[2][1] == 6 && head->Nine[2][2] == 5 )
		return 1;
	else return 0;
}

bool CSearchTreeDlg::Exchange(char PositionX, char PositionY, char Direction) 
{
	NineLink s; 
	int i,j,flag = 0;
	// TODO: Add your control notification handler code here
	//筛掉不符合要求的换位
	if(PositionX != 1 || PositionY != 1) 
	{
		if(PositionX == 0)
		{
			if(Direction == 'u') flag = 1;
		}
		if(PositionX == 2)
		{
			if(Direction == 'd') flag = 1;
		}
		if(PositionY == 0)
		{
			if(Direction == 'l') flag = 1;
		}
	    if(PositionY == 2)
		{
			if(Direction == 'r') flag = 1;
		}
	}
	if((Direction == 'u' && head->D == 'd')||(Direction == 'd' && head->D == 'u')||(Direction == 'r' && head->D == 'l')||(Direction == 'l' && head->D == 'r')) flag = 1;
	if(flag == 1) return 0;

    else	//将可用的换位构造成为子节点并放到链表尾部
	{
		s=(NineLink)malloc(LEN);   
		tail->next = s;
		s->prior = head;
		for(i = 0;i <=2;i ++)
		{
			for(j = 0;j <= 2;j ++)
			{

				s->Nine[i][j] = head->Nine[i][j];
			}
		}
		tail = s;
		
		switch(Direction)
		{
		case 'l':
			{
				tail->Nine[PositionX][PositionY] = tail->Nine[PositionX][PositionY-1];
				tail->Nine[PositionX][PositionY-1] = 0;
				tail->X = PositionX;
				tail->Y = PositionY-1;
				tail->D = 'l';
				break;
			}
		case 'r':
			{
				tail->Nine[PositionX][PositionY] = tail->Nine[PositionX][PositionY+1];
				tail->Nine[PositionX][PositionY+1] = 0;
				tail->X = PositionX;
				tail->Y = PositionY+1;
				tail->D = 'r';
				break;
			}
		case 'u':
			{
				tail->Nine[PositionX][PositionY] = tail->Nine[PositionX-1][PositionY];
				tail->Nine[PositionX-1][PositionY] = 0;
				tail->X = PositionX-1;
				tail->Y = PositionY;
				tail->D = 'u';
				break;
			}
		case 'd':
			{
				tail->Nine[PositionX][PositionY] = tail->Nine[PositionX+1][PositionY];
				tail->Nine[PositionX+1][PositionY] = 0;
				tail->X = PositionX+1;
				tail->Y = PositionY;
				tail->D = 'd';
				break;
			}
		default:
			{
				MessageBox(_T("出错啦！"));
				break;
			}
		}
		return 1;
	}

}
void CSearchTreeDlg::CreateNineLink()
{
	head=(NineLink)malloc(LEN);//生成头结点
	head->prior=head;
	head->next=head;//头结点的前向和后向指针都指向自己
	tail = head;
}

void CSearchTreeDlg::OnButtonSolve() 
{
	// TODO: Add your control notification handler code here
	bool IsDone;
	int i,j,times = 0;
	NineLink temp;
	Direct[0] = 'u';
	Direct[1] = 'd';
	Direct[2] = 'l';
	Direct[3] = 'r';

	CreateNineLink();//创建头结点

	UpdateData(true);
	head->Nine[0][0]=m_strNine1;
    head->Nine[0][1]=m_strNine2;
	head->Nine[0][2]=m_strNine3;
	head->Nine[1][0]=m_strNine4;
	head->Nine[1][1]=m_strNine5;
	head->Nine[1][2]=m_strNine6;
	head->Nine[2][0]=m_strNine7;
	head->Nine[2][1]=m_strNine8;
	head->Nine[2][2]=m_strNine9;

	for(i = 0;i <= 2;i ++)
	{
		for(j = 0;j <= 2;j ++)
		{
			if(head->Nine[i][j] == 0)
			{
				head->X = i; //寻找空位位置 
				head->Y = j;
				break;
			}
		}
	}

	IsDone = Judge();
	while(!IsDone)
	{
		IsDone = Judge(); //判断是否完成排布
		if(!IsDone)
		{
			for(j = 0;j < 4;j ++) //分别将当前空位与上、下、左、右元素交换，作为新的状态子节点，并放入链表
			{
				Exchange(head->X,head->Y,Direct[j]);	
			}
			head = head->next; //查找表中的下一个节点
		}
	}
	while(head->prior != head) //倒序寻找第一个节点，并将解答中的步骤链接起来
	{
		temp = head;
		head = head->prior;
		head->next = temp;
		times ++;
	}
	head = head->next;

	m_strTimes = times;
	UpdateData(false);
}

void CSearchTreeDlg::OnButtonNext() 
{
	//显示下一个状态并计数
	if(m_strTimes == m_strCount && m_strTimes != 0) MessageBox(_T("已经搞好啦！~"));
	else if(m_strTimes == 0) MessageBox(_T("先点一下求解吧> <"));
	else
	{
		m_strNine1 = head->Nine[0][0];
		m_strNine2 = head->Nine[0][1];
		m_strNine3 = head->Nine[0][2];
		m_strNine4 = head->Nine[1][0];
		m_strNine5 = head->Nine[1][1];
		m_strNine6 = head->Nine[1][2];
		m_strNine7 = head->Nine[2][0];
		m_strNine8 = head->Nine[2][1];
		m_strNine9 = head->Nine[2][2];
		
		head = head->next;
		
		m_strCount++;
		
		UpdateData(false);

	}
}

void CSearchTreeDlg::OnButtonAgain() 
{
	// 清除九宫数组，清除计数
	    m_strTimes = 0;
		m_strCount = 0;
		m_strNine1 = 0;
		m_strNine2 = 0;
		m_strNine3 = 0;
		m_strNine4 = 0;
		m_strNine5 = 0;
		m_strNine6 = 0;
		m_strNine7 = 0;
		m_strNine8 = 0;
		m_strNine9 = 0;

		UpdateData(false);
}
