
// MFCApplicationView.cpp : CMFCApplicationView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMFCApplicationView ����/����

CMFCApplicationView::CMFCApplicationView()
{
	// TODO: �ڴ˴���ӹ������
}

CMFCApplicationView::~CMFCApplicationView()
{
}

BOOL CMFCApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationView ����

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


// CMFCApplicationView ��ӡ

BOOL CMFCApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCApplicationView ���

#ifdef _DEBUG
void CMFCApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationDoc* CMFCApplicationView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationDoc)));
	return (CMFCApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationView ��Ϣ�������

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

    //���ô���Ϊ��Ч���򣬴����ػ�
    Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

void CMFCApplicationView::SetOpNormal()
{
    m_Mode = OP_CURSOR;
    HCURSOR m_Cursor;
    m_Cursor = AfxGetApp()->LoadCursor(IDC_CURSOR1);

    CToolBar *pToolBar = (CToolBar *)//ȡ�ù���������ָ��

        (GetParentFrame()->GetControlBar(IDR_DOCKTOOLBAR));

    //ȡ�ù���������ָ��

    CToolBarCtrl *pToolBarCtrl = &(pToolBar->GetToolBarCtrl());

    //���ƹ�������ť״̬

    pToolBarCtrl->EnableButton(ID_BUTTON_START, FALSE);

    pToolBarCtrl->EnableButton(ID_BUTTON_STOP, TRUE);

    CClientDC dc(this);//ȡ���豸�ı�
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