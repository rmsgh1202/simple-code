#include<afxwin.h>
class CMainFrame : public CFrameWnd {
public:
	CMainFrame() {
		Create(NULL, L"Hi !");
	}
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};
class CMyApp : public CWinApp {
	BOOL InitInstance() {
		CMainFrame* Frm = new CMainFrame();
		m_pMainWnd = Frm;
		Frm->ShowWindow(1);
		return TRUE;
	}

};
CMyApp theApp;
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	CBrush b;
	b.CreateSolidBrush(RGB(0, 255, 0));
	dc.SelectObject(&b);
	dc.Rectangle(20, 20, 300, 300);
}
