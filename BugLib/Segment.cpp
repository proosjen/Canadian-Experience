/**
 * \file Segment.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "Segment.h"
#include "BugActual.h"
#include "PseudoRandom.h"

#include <string>

using namespace Gdiplus;

/// Segment 1 image name
const std::wstring Segment1ImageName = L"images/segment1.png";

/// Segment 2 image name
const std::wstring Segment2ImageName = L"images/segment2.png";

/// Segment 3 image name
const std::wstring Segment3ImageName = L"images/segment3.png";

/// Segment 4 image name
const std::wstring Segment4ImageName = L"images/segment4.png";

/// Segment 5 image name
const std::wstring Segment5ImageName = L"images/segment5.png";



/**
 * Constructor
 * \param bug Bug we are using
 */
CSegment::CSegment(CBugActual *bug) : CBugPart(bug)
{
	const std::wstring filename = ChooseImage();
	LoadImage(filename);
}


/**
 * Destructor
 */
CSegment::~CSegment()
{
}


void CSegment::AddChild(std::shared_ptr<CBugPart> child)
{
	CBugPart::AddChild(child);
}


const std::wstring CSegment::ChooseImage()
{
	int random = GetBug()->GetRandom()->Random(1, 5);

	switch (random) {
	case 1:
		return Segment1ImageName;
		break;
	case 2:
		return Segment2ImageName;
		break;
	case 3:
		return Segment3ImageName;
		break;
	case 4:
		return Segment4ImageName;
		break;
	case 5:
		return Segment5ImageName;
		break;
	default:
		return Segment1ImageName;
		break;
	}
}

void CSegment::Grow(double delta)
{
	CBugPart::Grow(delta);

	SpawnPart();
}

void CSegment::SpawnPart()
{
	/*
	* Spawning child segments, heads, or stingers
	*/
	if (!mHasChild && GetAge() > GetWhenSpawn())
	{
		float childX = (float)(IsLeft() ?
			-GetPartWidth() * 0.9f : GetPartWidth() * 0.9f);

		double rand = GetRandom()->Random(0.0, 1.1);

		if (rand < 0.4)
		{
			if (IsLeft())
			{
				// Grow a head
				auto head = make_shared<CBugHead>(GetBug());
				head->SetSelf(head);
				head->SetPosition(PointF(childX - 125, 0));
				head->SetAngle(-GetRandom()->Random(-30, 30));

				AddChild(head);
				mHasChild = true;
			}
			else
			{
				// Grow a stinger
				auto part = make_shared<CStinger>(GetBug());

				part->SetPosition(PointF(childX, 0));
				part->SetAngle(-GetRandom()->Random(-30, 30));

				AddChild(part);
				mHasChild = true;
			}
		}
		else
		{
			// Grow a segment
			auto part = make_shared<CSegment>(GetBug());

			part->SetPosition(PointF(childX, 0));
			part->SetAngle(IsLeft() ? GetRandom()->Random(-10, 30) : GetRandom()->Random(-10, 30));
			part->SetLeft(IsLeft());
			
			AddChild(part);
			mHasChild = true;
		}

	}
}