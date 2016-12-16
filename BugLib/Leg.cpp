/**
 * \file Leg.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "Leg.h"
#include "BugActual.h"

 /// Leg 1 image name
const std::wstring Leg1ImageName = L"images/leg1.png";

/// Leg 2 image name
const std::wstring Leg2ImageName = L"images/leg2.png";

/// Segment 3 image name
const std::wstring Leg3ImageName = L"images/leg3.png";


/**
 * Constructor
 * \param bug The bug we are using
 */
CLeg::CLeg(CBugActual *bug) : CBugPart(bug)
{
	const std::wstring filename = ChooseImage();
	LoadImage(filename);
}


/**
 * Destructor
 */
CLeg::~CLeg()
{
}


void CLeg::Grow(double delta)
{
	CBugPart::Grow(delta);
}


const std::wstring CLeg::ChooseImage()
{
	int random = GetBug()->GetRandom()->Random(1, 3);

	switch (random) {
	case 1:
		return Leg1ImageName;
		break;
	case 2:
		return Leg2ImageName;
		break;
	case 3:
		return Leg3ImageName;
		break;
	default:
		return Leg1ImageName;
		break;
	}
}
