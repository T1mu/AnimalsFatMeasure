// INFOR.cpp: 实现文件
//

#include "stdafx.h"
#include "AnimalsFatMeasure.h"
#include "INFOR.h"
#include "afxdialogex.h"


// INFOR 对话框

IMPLEMENT_DYNAMIC(INFOR, CDialogEx)

INFOR::INFOR(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Infor, pParent)
{

}

INFOR::~INFOR()
{
}

void INFOR::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(INFOR, CDialogEx)
END_MESSAGE_MAP()


// INFOR 消息处理程序
