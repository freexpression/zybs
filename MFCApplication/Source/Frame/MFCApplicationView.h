
// MFCApplicationView.h : CMFCApplicationView ��Ľӿ�
//

#pragma once
#include <vector>
#include "Plane.h"
#include "PlaneView.h"

class CMFCApplicationView : public CView
{
protected: // �������л�����
	CMFCApplicationView();
	DECLARE_DYNCREATE(CMFCApplicationView)

// ����
public:
	CMFCApplicationDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

protected:
	int m_Mode = 0;
    std::vector<CObjView*> m_ViewList;

public:
    afx_msg void OnPlayStart();


	//�û�����
	static const int OP_CURSOR = 0;//��ͨģʽ������ѡ���ƶ�����
	static const int OP_ADD_PLANE = 1; //���ƽ̨
	afx_msg void OnOpAddPlane();
	afx_msg void OnOpNormal();
	afx_msg void OnUpdateOpAddPlane(CCmdUI *pCmdUI);
	afx_msg void OnUpdateOpNormal(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnPlayStop();

protected:
    void Repaint(); //�ػ����溯����
    void SetOpNormal();//����Ϊ��ͨģʽ��
       
    void HandleAddPlaneEvent(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplicationView.cpp �еĵ��԰汾
inline CMFCApplicationDoc* CMFCApplicationView::GetDocument() const
   { return reinterpret_cast<CMFCApplicationDoc*>(m_pDocument); }
#endif

