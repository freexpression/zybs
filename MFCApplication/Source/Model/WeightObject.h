#pragma once

#include "Speed.h"

/*
 ������������������࣬������������������á�
*/
class CWeightObject
{
public:
	CWeightObject();
	~CWeightObject();

private:
	float m_mass = 0;//����
	float m_frict = 0;//Ħ��ϵ��
	CSpeed m_speed; //����
};

