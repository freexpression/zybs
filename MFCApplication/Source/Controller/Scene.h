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
	 *����ʱ����Ϣ(�Կ�ʼʱ��Ϊ��׼������Ϊ��λ�����ɸ÷���������ƶ�̬ͼ�Ρ�
	*/
	virtual int slice(CDC* pDc, long tick) = 0;
};

