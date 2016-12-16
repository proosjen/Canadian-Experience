/**
 * \file Stinger.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "Stinger.h"
#include "BugActual.h"

 /// Stinger 1 image name
const std::wstring Stinger1ImageName = L"images/stinger1.png";

/// Stinger 2 image name
const std::wstring Stinger2ImageName = L"images/stinger2.png";


/**
 * Constructor
 * \param bug The bug we are using
 */
CStinger::CStinger(CBugActual *bug) : CBugPart(bug)
{
	const std::wstring filename = ChooseImage();
	LoadImage(filename);
}


/**
 * Destructor
 */
CStinger::~CStinger()
{
}


const std::wstring CStinger::ChooseImage()
{
	int random = GetBug()->GetRandom()->Random(1, 2);

	switch (random) {
	case 1:
		return Stinger1ImageName;
		break;
	case 2:
		return Stinger2ImageName;
		break;
	default:
		return Stinger1ImageName;
		break;
	}
}