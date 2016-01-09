#pragma once

#include "Speed.h"

/*
 定义带有重力的物体类，此类物体会受重力作用。
*/
class CWeightObject
{
public:
	CWeightObject();
	~CWeightObject();

private:
	float m_mass = 0;//质量
	float m_frict = 0;//摩擦系数
	CSpeed m_speed; //受力
};

