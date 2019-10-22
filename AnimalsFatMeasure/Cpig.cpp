// Cpig.cpp: 实现文件
#include "Resource.h"
#include "stdafx.h"
#include "AnimalsFatMeasure.h"
#include "Cpig.h"
#include "afxdialogex.h"
#include "INFOR.h"
#include <opencv2/opencv.hpp>



using namespace cv;
using namespace std;
// Cpig 对话框

IMPLEMENT_DYNAMIC(Cpig, CDialogEx)

Cpig::Cpig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Pig, pParent)
{

}

Cpig::~Cpig()
{
}

void Cpig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cpig, CDialogEx)
	ON_BN_CLICKED(IDC_Import1, &Cpig::OnBnClickedImport1)
END_MESSAGE_MAP()


Mat hp_mat; //横图图片地址
static Mat g_img_src;
static Mat g_img_dst;
static Mat g_img_sub;
static bool g_is_rect_inited = false;
static Point g_rect_tl;
static String g_window_name = "view";

static void onMouse(int event, int x, int y, int, void*)
{
	if (CV_EVENT_LBUTTONDOWN == event) {
		g_is_rect_inited = true;
		g_rect_tl = Point(x, y);
	}
	else if (CV_EVENT_MOUSEMOVE == event && g_is_rect_inited) {
		hp_mat.copyTo(g_img_dst);
		rectangle(g_img_dst, g_rect_tl, Point(x, y), Scalar_<uchar>::all(200), 3, 8);
		imshow(g_window_name, g_img_dst);
	}
	else if (CV_EVENT_LBUTTONUP == event && g_rect_tl != Point(x, y)) {
		hp_mat(Rect(g_rect_tl, Point(x, y))).copyTo(g_img_sub);
		cv::imwrite("timrow.png", g_img_sub);
		imshow("sub image", g_img_sub);
		g_is_rect_inited = false;
	}
}


// Cpig 消息处理程序
// 导入横图
void Cpig::OnBnClickedImport1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString hP = _T("");
	CFileDialog dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.jpg)|*.jpg|All Files (*.*)|*.*||"), NULL);
	if (dlgFile.DoModal())
	{
		hP = dlgFile.GetPathName();
		if(hP.IsEmpty())
		{
			AfxMessageBox(_T("所选文件为空"));
		}
		else {
			std::string hp_string = CStringA(hP);
			hp_mat = imread(hp_string);
			imshow("view", hp_mat);
			setMouseCallback(g_window_name, onMouse, 0);


			INFOR  *dlg = new INFOR;
			dlg->Create(IDD_Infor, this);
			dlg->ShowWindow(SW_SHOW);

			//Result res = numberIdenti(hp_string);				//获取识别信息
			//GetDlgItem(IDC_STATIC)->SetWindowText(res.mianji);	//赋值面积
			//GetDlgItem(IDC_EDIT3)->SetWindowText(res.houdu);	//赋值厚度
		}
	}
}


BOOL Cpig::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	namedWindow("view", WINDOW_NORMAL);
	HWND hWnd = (HWND)cvGetWindowHandle("view");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_hp)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
			  // 异常: OCX 属性页应返回 FALSE
}