#pragma once

class CForce
{
public:
	CForce();
	~CForce();
public:
	CString m_name; //名称，可选。
	float m_force = 0; //力，单位牛顿
	CPoint m_point; //受力点
	float m_direct = 0;//受力方向, 以X轴正半轴，逆时针方向形成的角度。 
};

