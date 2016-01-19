#pragma once
#include "Obj.h"

class CBlock : public CObj
{
public:
	CBlock();
	~CBlock();

public:
	int m_x = 0; //左上角位置X
	int m_y = 0; //左上角位置Y
	int m_width = 0; //宽度
	int m_heigh = 0; //高度
};

