#pragma once
/*
 * ����ʵ���г��õ�ֱ��б�£��ײ�ˮƽ���ã���ֱ������ࡣ
 *
*/
class CSlopeView
{
public:
	CSlopeView();
	~CSlopeView();

private:
	int m_x = 0; //���½�λ��X
	int m_y = 100; //���½�λ��Y
	float m_theta = 30; //б�½Ƕ�
	int m_width = 300; //�ױ߿�� 
	float m_frict = 0;//Ħ��ϵ��
};

