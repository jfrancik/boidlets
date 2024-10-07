#pragma once

#include "FVector.h"

class CBoid : public CSprite
{
	CSpriteList *m_pBoids;

public:
	CBoid(Sint16 x, Sint16 y, Uint32 time, CSpriteList &boids);
	~CBoid(void);

	double Distance(CBoid *pBoid)		{ return GetPosition().Distance(pBoid->GetPosition()); }

	virtual void OnUpdate(Uint32 time, Uint32 deltaTime);
};
