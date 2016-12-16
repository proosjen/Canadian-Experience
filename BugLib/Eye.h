/**
 * \file Eye.h
 *
 * \author Jenn Proos
 *
 * Class that implements a bug eye
 */

#pragma once
#include "BugPart.h"

class BugHead;


/**
 * Class that describes a bug eye
 */
class CEye :
	public CBugPart
{
public:
	/// Constructor
	CEye(CBugActual *bug, int seed);

	/// Default constructor (disabled)
	CEye() = delete;

	/// Destructor
	virtual ~CEye();

	/** \brief Get an eye image to use
	* \param seed Seed to use for random image
	* \return Image filename*/
	const std::wstring ChooseImage(int seed);

};

