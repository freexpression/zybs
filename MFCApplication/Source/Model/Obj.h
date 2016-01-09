#pragma once

#include <vector>
#include "Speed.h"
#include "Force.h"


/*
物理物体抽象类，具备基本的物理属性：质量、速度、加速度、重心、力等。所有的物理实体都继承该类。
*/
class CObj
{
public:
	CObj();
	~CObj();
public:
	float m_mass = 0;//质量
	CSpeed m_speed; //速度
	float m_acceleration = 0; //加速度
	CPoint m_centre; //重心
	std::vector<CForce> m_forces; //受力

public:
	bool hasForce(); //是否受力
};

