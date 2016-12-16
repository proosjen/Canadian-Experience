/**
 * \file RootSegment.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "RootSegment.h"
#include "BugHead.h"
#include "Stinger.h"
#include "BugActual.h"

#include <string>


/**
 * Constructor
 * \param bug The bug we are using*/
CRootSegment::CRootSegment(CBugActual *bug) : CSegment(bug)
{
}


/**
 * Destructor
 */
CRootSegment::~CRootSegment()
{
}


void CRootSegment::Grow(double delta)
{
	CSegment::Grow(delta);
}


void CRootSegment::SpawnPart()
{
	//int random = GetBug()->GetRandom()->Random(1, 4);

	if (!GetHasChild() && GetAge() > GetWhenSpawn())
	{
		float childX = (float)GetPartWidth() * 0.9f;

		// Grow a left segment
		auto leftpart = make_shared<CSegment>(GetBug());
		leftpart->SetPosition(PointF(0, 0));
		leftpart->SetAngle(IsLeft() ? GetRandom()->Random(-10, 30) : GetRandom()->Random(-10, 30));
		leftpart->SetLeft(true);
		leftpart->SetParent(this);
		AddChild(leftpart);

		// Grow a right segment
		auto rightpart = make_shared<CSegment>(GetBug());
		rightpart->SetPosition(PointF(childX, 0));
		rightpart->SetAngle(IsLeft() ? GetRandom()->Random(-10, 30) : GetRandom()->Random(-10, 30));
		rightpart->SetLeft(false);
		rightpart->SetParent(this);
		AddChild(rightpart);

		SetHasChild(true);
	}
}