#pragma once

class CForce
{
public:
	CForce();
	~CForce();
public:
	CString m_name; //���ƣ���ѡ��
	float m_force = 0; //������λţ��
	CPoint m_point; //������
	float m_direct = 0;//��������, ��X�������ᣬ��ʱ�뷽���γɵĽǶȡ� 
};

