#pragma once
#include "Obj.h"

class CBall : public CObj
{
public:
	CBall();
	~CBall();

public:
	int m_x = 0; //���Ͻ�λ��X
	int m_y = 0; //���Ͻ�λ��Y
	float m_scale = 0; //�뾶
};