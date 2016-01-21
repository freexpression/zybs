#pragma once
#include "Obj.h"

class CBall : public CObj
{
public:
	CBall();
	~CBall();

public:
	int m_x = 0; //左上角位置X
	int m_y = 0; //左上角位置Y
	float m_scale = 0; //半径
};