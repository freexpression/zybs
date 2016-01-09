#pragma once
class CEngine
{
public:
	CEngine();
	~CEngine();
	/*
	*传入时间信息(以开始时间为基准，毫秒为单位），由该方法负责对物体的位置、状态等属性进行计算更新。
	*/
	int slice(long tick);
};

