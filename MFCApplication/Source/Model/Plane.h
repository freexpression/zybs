#pragma once

#include "Obj.h"
/*
定义平面物体类，此类物体具有角度和摩擦系数。
*/
class CPlane : public CObj
{
public:
	CPlane();
	~CPlane();

private:
	float m_theta = 0;//斜面角度（与X轴的夹角）
	float m_frict = 0;//摩擦系数
};

