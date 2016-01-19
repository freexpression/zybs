
// MFCApplicationView.h : CMFCApplicationView 类的接口
//

#pragma once
#include <vector>
#include "Plane.h"
#include "PlaneView.h"

class CMFCApplicationView : public CView
{
protected: // 仅从序列化创建
	CMFCApplicationView();
	DECLARE_DYNCREATE(CMFCApplicationView)

// 特性
public:
	CMFCApplicationDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

protected:
	int m_Mode = 0;
    std::vector<CObjView*> m_ViewList;

public:
    afx_msg void OnPlayStart();


	//用户操作
	static const int OP_CURSOR = 0;//普通模式，可以选择、移动对象。
	static const int OP_ADD_PLANE = 1; //添加平台
	afx_msg void OnOpAddPlane();
	afx_msg void OnOpNormal();
	afx_msg void OnUpdateOpAddPlane(CCmdUI *pCmdUI);
	afx_msg void OnUpdateOpNormal(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnPlayStop();

protected:
    void Repaint(); //重画界面函数。
    void SetOpNormal();//设置为普通模式；
       
    void HandleAddPlaneEvent(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplicationView.cpp 中的调试版本
inline CMFCApplicationDoc* CMFCApplicationView::GetDocument() const
   { return reinterpret_cast<CMFCApplicationDoc*>(m_pDocument); }
#endif

