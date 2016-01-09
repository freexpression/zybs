#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
{
}


CObj::~CObj()
{
}

bool CObj::hasForce() {
	for (unsigned int i = 0; i < m_forces.size(); i++) {
		if (m_forces[i].m_force > 0) {
			return true;
		}
	}

	return false;
}