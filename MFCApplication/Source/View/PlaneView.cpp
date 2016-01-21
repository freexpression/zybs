#include "stdafx.h"
#include "PlaneView.h"

CPlaneView::CPlaneView()
{
	m_Size.left = 100;
	m_Size.right = 200;
	m_Size.top = 400;
	m_Size.bottom = 350;
}


CPlaneView::~CPlaneView()
{
}

void CPlaneView::Paint(CDC* pDC)
{
    COLORREF bColor = RGB(192, 192, 192);;
    CPen Pen;
    Pen.CreatePen(PS_SOLID, 1, bColor);
    pDC->SelectObject(&Pen);

    CRect rect;
    rect.left = m_Postion.x;
    rect.top = m_Postion.y;
    rect.right = m_Postion.x + m_Size.left - m_Size.right;
    rect.bottom = m_Postion.y + m_Size.top - m_Size.bottom;

    pDC->RoundRect(&rect, CPoint(5, 5));   //»­Ô²½Ç¾ØÐÎ
//    pDC->DrawEdge(&m_Size, EDGE_RAISED, BF_ADJUST | BF_BOTTOMLEFT | BF_TOPRIGHT);
}
