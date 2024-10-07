#include "stdafx.h"
#include "Boid.h"

CBoid::CBoid(Sint16 x, Sint16 y, Uint32 time, CSpriteList &boids)
	: CSprite(x, y, "ant.gif", time)
{
	m_pBoids = &boids;
}

CBoid::~CBoid()
{
}

void CBoid::OnUpdate(Uint32 time, Uint32 deltaTime)
{
	double radius = 25;
	int countSep = 0, countAli = 0, countCoh = 0;
	CFVector sep, ali, coh;

	// sep
	for each (CBoid *pBoid in *m_pBoids)
	{
		if (pBoid != this && Distance(pBoid) <= radius && Distance(pBoid) > 0)
		{
			CFVector d = GetPosition() - pBoid->GetPosition();
			d *= 150 / sqrt(d.GetX() * d.GetX() + d.GetY() * d.GetY());
			sep += d;
			countSep++;
		}
		// ali
		if (pBoid != this && Distance(pBoid) <= radius*2 && Distance(pBoid) > 0)
		{
			ali += CFVector(pBoid->GetXVelocity(), pBoid->GetYVelocity());
			countAli++;
		}
		// coh
		if (pBoid != this && Distance(pBoid) <= radius*2 && Distance(pBoid) > 0)
		{
			coh += CFVector(pBoid->GetX(), pBoid->GetY());
			countCoh++;
		}
	}

	if (countSep) sep /= countSep;
	if (countAli) ali /= countAli;
	if (countCoh) coh /= countCoh;
	CFVector vec = sep + ali + coh;

	SetMotion(GetXVelocity() + vec.GetX() - GetX(), GetYVelocity() + vec.GetY() - GetY());

	if (GetSpeed() > 100)
		SetSpeed(100);

	SetRotation(GetDirection() - 90.0);
	CSprite::OnUpdate(time, deltaTime);
}
