#pragma once

#include "Obj.h"
/*
����ƽ�������࣬����������нǶȺ�Ħ��ϵ����
*/
class CPlane : public CObj
{
public:
	CPlane();
	~CPlane();

private:
	float m_theta = 0;//б��Ƕȣ���X��ļнǣ�
	float m_frict = 0;//Ħ��ϵ��
};

