#pragma once

class CSpeed
{
public:
	CSpeed();
	~CSpeed();
public:
	float m_speed = 0;//受力大小
	float m_direct = 0;//受力方向, 以X轴正半轴，逆时针方向形成的角度。 
};