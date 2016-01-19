#pragma once

#include "Block.h"
#include "ObjView.h"
class CBlockView : public CObjView
{
public:
	CBlockView();
	~CBlockView();

public:
	CBlock m_block;
};

