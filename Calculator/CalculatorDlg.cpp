
// CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// 按下1 
void CCalculatorDlg::OnBnClickedButton1()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);

	if (pEdit != nullptr)
	{
		CString currentText;
		pEdit->GetWindowText(currentText);
		currentText += _T("1");
		pEdit->SetWindowText(currentText);
	}
}


// 按下2
void CCalculatorDlg::OnBnClickedButton2()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);

	if (pEdit != nullptr)
	{
		CString currentText;
		pEdit->GetWindowText(currentText);
		currentText += _T("2");
		pEdit->SetWindowText(currentText);
	}
}


// 按下3
void CCalculatorDlg::OnBnClickedButton14()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);

	if (pEdit != nullptr)
	{
		CString currentText;
		pEdit->GetWindowText(currentText);
		currentText += _T("3");
		pEdit->SetWindowText(currentText);
	}	
}


// 按下4
void CCalculatorDlg::OnBnClickedButton6()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);

	if (pEdit != nullptr)
	{
		CString currentText;
		pEdit->GetWindowText(currentText);
		currentText += _T("4");
		pEdit->SetWindowText(currentText);
	}
}


// 按下5
void CCalculatorDlg::OnBnClickedButton4()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);

	if (pEdit != nullptr)
	{
		CString currentText;
		pEdit->GetWindowText(currentText);
		currentText += _T("5");
		pEdit->SetWindowText(currentText);
	}
}


// 按下6
void CCalculatorDlg::OnBnClickedButton11()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);

	if (pEdit != nullptr)
	{
		CString currentText;
		pEdit->GetWindowText(currentText);
		currentText += _T("6");
		pEdit->SetWindowText(currentText);
	}
}

// 按下7
void CCalculatorDlg::OnBnClickedButton7()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);

	if (pEdit != nullptr)
	{
		CString currentText;
		pEdit->GetWindowText(currentText);
		currentText += _T("7");
		pEdit->SetWindowText(currentText);
	}
}


// 按下8
void CCalculatorDlg::OnBnClickedButton8()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);

	if (pEdit != nullptr)
	{
		CString currentText;
		pEdit->GetWindowText(currentText);
		currentText += _T("8");
		pEdit->SetWindowText(currentText);
	}
}


// 按下9
void CCalculatorDlg::OnBnClickedButton5()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);

	if (pEdit != nullptr)
	{
		CString currentText;
		pEdit->GetWindowText(currentText);
		currentText += _T("9");
		pEdit->SetWindowText(currentText);
	}
}


// 按下0
void CCalculatorDlg::OnBnClickedButton12()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);

	if (pEdit != nullptr)
	{
		CString currentText;
		pEdit->GetWindowText(currentText);
		currentText += _T("0");
		pEdit->SetWindowText(currentText);
	}
}

// 按下.
void CCalculatorDlg::OnBnClickedButton9()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);

	if (pEdit != nullptr)
	{
		// 获取当前文本
		CString currentText;
		pEdit->GetWindowText(currentText);

		// 检查是否当前文本为空或是运算符输入状态，然后添加小数点
		if (currentText.IsEmpty() || isOperatorEntered)
		{
			currentText += _T(".");
			pEdit->SetWindowText(currentText);
			isOperatorEntered = false;  // 重置运算符输入状态
		}
		else if (currentText.Find(_T(".")) == -1)
		{
			// 如果当前文本中没有小数点，添加小数点
			currentText += _T(".");
			pEdit->SetWindowText(currentText);
		}
	}
}


// +
void CCalculatorDlg::OnBnClickedButton13()
{
	isOperatorEntered = true;	// 运算符被按下
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);
	if (pEdit != nullptr)
	{
		// 获取当前文本
		CString currentText;
		pEdit->GetWindowText(currentText);


		// 获取当前文本的长度
		int textLength = currentText.GetLength();

		if (textLength != 0)
		{
			switch (currentText[textLength - 1])
			{
			case L'+':
			case L'-':
			case L'*':
			case L'/':
			case L'%': 
			{
				CString subString = currentText.Left(textLength - 1);
				pEdit->SetWindowText(subString + "+");
				break;

			}
			default:
			{
				currentText += L"+";
				pEdit->SetWindowText(currentText);
			}
			}
		}
	}
}



// - 
void CCalculatorDlg::OnBnClickedButton15()
{
	isOperatorEntered = true;	// 运算符被按下
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);
	if (pEdit != nullptr)
	{
		// 获取当前文本
		CString currentText;
		pEdit->GetWindowText(currentText);


		// 获取当前文本的长度
		int textLength = currentText.GetLength();

		if (textLength != 0)
		{
			switch (currentText[textLength - 1])
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			{
				CString subString = currentText.Left(textLength - 1);
				pEdit->SetWindowText(subString + "-");
				break;
			}
			default:
			{
				currentText += "-";
				pEdit->SetWindowText(currentText);
			}
			}
		}
	}
}


// *
void CCalculatorDlg::OnBnClickedButton16()
{
	isOperatorEntered = true;	// 运算符被按下
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);
	if (pEdit != nullptr)
	{
		// 获取当前文本
		CString currentText;
		pEdit->GetWindowText(currentText);


		// 获取当前文本的长度
		int textLength = currentText.GetLength();

		if (textLength != 0)
		{
			switch (currentText[textLength - 1])
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			{
				CString subString = currentText.Left(textLength - 1);
				pEdit->SetWindowText(subString + "*");
				break;
			}
			default:
			{
				currentText += "*";
				pEdit->SetWindowText(currentText);
			}
			}
		}
	}
}


// /
void CCalculatorDlg::OnBnClickedButton17()
{
	isOperatorEntered = true;	// 运算符被按下
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);
	if (pEdit != nullptr)
	{
		// 获取当前文本
		CString currentText;
		pEdit->GetWindowText(currentText);


		// 获取当前文本的长度
		int textLength = currentText.GetLength();

		if (textLength != 0)
		{
			switch (currentText[textLength - 1])
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			{
				CString subString = currentText.Left(textLength - 1);
				pEdit->SetWindowText(subString + "/");
				break;
			}
			default:
			{
				currentText += "/";
				pEdit->SetWindowText(currentText);
			}
			}
		}
	}
}


// %
void CCalculatorDlg::OnBnClickedButton18()
{
	isOperatorEntered = true;	// 运算符被按下
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);
	if (pEdit != nullptr)
	{
		// 获取当前文本
		CString currentText;
		pEdit->GetWindowText(currentText);


		// 获取当前文本的长度
		int textLength = currentText.GetLength();

		if (textLength != 0)
		{
			switch (currentText[textLength - 1])
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			{
				CString subString = currentText.Left(textLength - 1);
				pEdit->SetWindowText(subString + "%");
				break;
			}
			default:
			{
				currentText += "%";
				pEdit->SetWindowText(currentText);
			}
			}
		}
	}
}


// 归零
void CCalculatorDlg::OnBnClickedButton3()
{
	isOperatorEntered = false;	
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC);
	pEdit->SetWindowText(L"");
}



// 计算
void CCalculatorDlg::OnBnClickedButton10()
{
	isOperatorEntered = false;

	

}
