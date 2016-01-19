#pragma once

#include "Ball.h"
#include "ObjView.h"

class CBallView : public CObjView
{
public:
	CBallView();
	~CBallView();

private:
	CBall m_ball;
};

