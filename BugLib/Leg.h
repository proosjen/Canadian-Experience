/**
 * \file Leg.h
 *
 * \author Jenn Proos
 *
 * Class that implements a bug leg
 */

#pragma once
#include "BugPart.h"


/**
 * Class that describes a bug leg
 */
class CLeg :
	public CBugPart
{
public:
	CLeg(CBugActual *bug);
	virtual ~CLeg();

	/** \brief Grow leg
	* \param delta The value to use for calculations*/
	void Grow(double delta);

	/** \brief Choose a random image
	* \return Image filename*/
	const std::wstring ChooseImage();
};

