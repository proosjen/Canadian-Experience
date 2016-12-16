/**
 * \file Eye.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "Eye.h"
#include "BugActual.h"
#include "BugHead.h"

 /// Eye 1 image name
const std::wstring Eye1ImageName = L"images/eye1.png";

/// Eye 2 image name
const std::wstring Eye2ImageName = L"images/eye2.png";

/// Eye 3 image name
const std::wstring Eye3ImageName = L"images/eye3.png";

/// Eye 4 image name
const std::wstring Eye4ImageName = L"images/eye4.png";


/**
 * Constructor
 * \param bug The bug we are using 
 * \param seed The seed to use for random
 */

CEye::CEye(CBugActual *bug, int seed) : CBugPart(bug)
{
	const std::wstring filename = ChooseImage(seed);
	LoadImage(filename);
}


/**
 * Destructor
 */
CEye::~CEye()
{
}

const std::wstring CEye::ChooseImage(int seed)
{
	switch (seed) {
	case 1:
		return Eye1ImageName;
		break;
	case 2:
		return Eye2ImageName;
		break;
	case 3:
		return Eye3ImageName;
		break;
	case 4:
		return Eye4ImageName;
		break;
	default:
		return Eye1ImageName;
		break;
	}
}



