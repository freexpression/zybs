#pragma once
#include "Obj.h"

class CBlock : public CObj
{
public:
	CBlock();
	~CBlock();

public:
	int m_x = 0; //���Ͻ�λ��X
	int m_y = 0; //���Ͻ�λ��Y
	int m_width = 0; //���
	int m_heigh = 0; //�߶�
};

