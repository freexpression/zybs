#include "stdafx.h"
#include "ObjView.h"


CObjView::CObjView()
{
}


CObjView::~CObjView()
{
}

void CObjView::Paint(CDC* pDc)
{
}

void CObjView::SetObj(CObj& pObj)
{
	m_Obj = &pObj;
}

CObj& CObjView::GetObj()
{
	return *m_Obj;
}

void CObjView::SetPostion(CPoint point)
{
    m_Postion = point;
}