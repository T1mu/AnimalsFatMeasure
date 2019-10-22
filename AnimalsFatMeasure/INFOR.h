#pragma once


// INFOR 对话框

class INFOR : public CDialogEx
{
	DECLARE_DYNAMIC(INFOR)

public:
	INFOR(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~INFOR();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Infor };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
