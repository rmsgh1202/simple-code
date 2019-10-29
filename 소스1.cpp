#include<afxwin.h>
class CMainFrame : public CFrameWnd {
public:
	CMainFrame() {
		Create(NULL, L"Hi !");
	}
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
---- -
// OnDraw()
// OnSize()
#include<afxwin.h>
class CMainFrame : public CFrameWnd {
public:
	CMainFrame() {
		Create(NULL, L"Hi !");
	}
	void OnPaint();
	void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()  // jcshim
};
class CMy : public CWinApp {
	BOOL InitInstance() {
		CMainFrame* Frm = new CMainFrame();
		m_pMainWnd = Frm;
		Frm->ShowWindow(1);
		return TRUE;
	}
};
CMy theApp;
// jcshim
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()
void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	dc.TextOutW(100, 100, L"Welcome");
}
void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);
	Invalidate();
}