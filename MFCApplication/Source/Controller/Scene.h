#pragma once
/*
 * 
*/
class CScene
{
public:
	CScene();
	~CScene();
	/*
	 *传入时间信息(以开始时间为基准，毫秒为单位），由该方法负责绘制动态图形。
	*/
	virtual int slice(CDC* pDc, long tick) = 0;
};

