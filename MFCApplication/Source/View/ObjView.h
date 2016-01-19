#pragma once

#include "Obj.h"
/*
物体视图抽象类，所有的物体都继承该类。
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

