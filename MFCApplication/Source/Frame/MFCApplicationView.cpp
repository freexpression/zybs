
// MFCApplicationView.cpp : CMFCApplicationView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication.h"
#endif

#include "MFCApplicationDoc.h"
#include "MFCApplicationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationView

IMPLEMENT_DYNCREATE(CMFCApplicationView, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_COMMAND(ID_ADD_PLANE, &CMFCApplicationView::OnAddPlane)
	ON_WM_TIMER()
ON_COMMAND(ID_PLAY_START, &CMFCApplicationView::OnPlayStart)
ON_COMMAND(ID_OP_ADD_PLANE, &CMFCApplicationView::OnOpAddPlane)
ON_COMMAND(ID_OP_NORMAL, &CMFCApplicationView::OnOpNormal)
ON_UPDATE_COMMAND_UI(ID_OP_ADD_PLANE, &CMFCApplicationView::OnUpdateOpAddPlane)
ON_UPDATE_COMMAND_UI(ID_OP_NORMAL, &CMFCApplicationView::OnUpdateOpNormal)
ON_WM_LBUTTONDOWN()
ON_COMMAND(ID_PLAY_STOP, &CMFCApplicationView::OnPlayStop)
END_MESSAGE_MAP()

// CMFCApplicationView 构造/析构

CMFCApplicationView::CMFCApplicationView()
{
	// TODO: 在此处添加构造代码
}

CMFCApplicationView::~CMFCApplicationView()
{
}

BOOL CMFCApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationView 绘制

void CMFCApplicationView::OnDraw(CDC* pDC)
{
	CMFCApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	std::vector<CObjView*>::iterator it;

	for (it = m_ViewList.begin(); it != m_ViewList.end(); it++)
	{
		(*it)->Paint(pDC);
	}
}


// CMFCApplicationView 打印

BOOL CMFCApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplicationView 诊断

#ifdef _DEBUG
void CMFCApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationDoc* CMFCApplicationView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationDoc)));
	return (CMFCApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationView 消息处理程序

void CMFCApplicationView::Repaint()
{
    CDC* pDC = CWnd::GetDC();

    OnDraw(pDC);
}

void CMFCApplicationView::OnTimer(UINT_PTR nIDEvent)
{
    Repaint();
}


void CMFCApplicationView::OnPlayStart()
{
	SetTimer(PLAY_TIMER, 1000, NULL);
}


void CMFCApplicationView::OnPlayStop()
{
    KillTimer(PLAY_TIMER);
}

void CMFCApplicationView::OnOpNormal()
{
	m_Mode = OP_CURSOR;
}

void CMFCApplicationView::OnOpAddPlane()
{
	m_Mode = OP_ADD_PLANE;
}

//

void CMFCApplicationView::OnUpdateOpAddPlane(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Mode == OP_ADD_PLANE);
}


void CMFCApplicationView::OnUpdateOpNormal(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Mode == OP_CURSOR);
}


void CMFCApplicationView::OnLButtonDown(UINT nFlags, CPoint point)
{
    switch (m_Mode)
    {
    case OP_ADD_PLANE:
        HandleAddPlaneEvent(nFlags, point);
        SetOpNormal();
    default:
        break;
    }

    //设置窗口为无效区域，触发重绘
    Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

void CMFCApplicationView::SetOpNormal()
{
    m_Mode = OP_CURSOR;
    HCURSOR m_Cursor;
    m_Cursor = AfxGetApp()->LoadCursor(IDC_CURSOR1);

    CToolBar *pToolBar = (CToolBar *)//取得工具栏对象指针

        (GetParentFrame()->GetControlBar(IDR_DOCKTOOLBAR));

    //取得工具条控制指针

    CToolBarCtrl *pToolBarCtrl = &(pToolBar->GetToolBarCtrl());

    //控制工具条按钮状态

    pToolBarCtrl->EnableButton(ID_BUTTON_START, FALSE);

    pToolBarCtrl->EnableButton(ID_BUTTON_STOP, TRUE);

    CClientDC dc(this);//取得设备文本
}

void CMFCApplicationView::HandleAddPlaneEvent(UINT nFlags, CPoint point)
{
    CMFCApplicationDoc* pDoc = GetDocument();

    CPlane pPlane;
    pDoc->AddObj(pPlane);

    CPlaneView* pView = new CPlaneView();
    pView->SetObj(pPlane);

    m_ViewList.push_back(pView);
}