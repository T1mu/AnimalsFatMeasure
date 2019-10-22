#pragma once


// Cpig 对话框

class Cpig : public CDialogEx
{
	DECLARE_DYNAMIC(Cpig)

public:
	Cpig(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cpig();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Pig };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedImport1();
	virtual BOOL OnInitDialog();
};
