#pragma once
#include "ObjView.h"
class CPlaneView : public CObjView
{
public:
	CPlaneView();
	~CPlaneView();

	virtual void Paint(CDC* pDc);

protected:
	CRect m_Size;
};
