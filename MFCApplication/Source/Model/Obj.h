#pragma once

#include <vector>
#include "Speed.h"
#include "Force.h"


/*
������������࣬�߱��������������ԣ��������ٶȡ����ٶȡ����ġ����ȡ����е�����ʵ�嶼�̳и��ࡣ
*/
class CObj
{
public:
	CObj();
	~CObj();
public:
	float m_mass = 0;//����
	CSpeed m_speed; //�ٶ�
	float m_acceleration = 0; //���ٶ�
	CPoint m_centre; //����
	std::vector<CForce> m_forces; //����

public:
	bool hasForce(); //�Ƿ�����
};

