#pragma once
/*
 * 重力实验中常用的直角斜坡，底部水平放置，竖直面在左侧。
 *
*/
class CSlopeView
{
public:
	CSlopeView();
	~CSlopeView();

private:
	int m_x = 0; //左下角位置X
	int m_y = 100; //左下角位置Y
	float m_theta = 30; //斜坡角度
	int m_width = 300; //底边宽度 
	float m_frict = 0;//摩擦系数
};