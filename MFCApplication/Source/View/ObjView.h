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

protected:
	CObj* m_Obj;
};

