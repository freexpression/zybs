#pragma once

#include "Obj.h"
/*
������ͼ�����࣬���е����嶼�̳и��ࡣ
*/
class CObjView
{
public:
	CObjView();
	~CObjView();

public:
	virtual void Paint(CDC* pDc);

	void SetObj(CObj& pObj);
	CObj& GetObj();
    void SetPostion(CPoint point);

protected:
	CObj* m_Obj;
    CPoint m_Postion;
};

