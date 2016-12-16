/**
 * \file Stinger.h
 *
 * \author Jenn Proos
 *
 * Class that implements a bug stinger
 */

#pragma once
#include "BugPart.h"

/**
 * Class that describes a bug stinger
 */
class CStinger :
	public CBugPart
{
public:
	/// Constructor
	CStinger(CBugActual *bug);

	/// Destructor
	virtual ~CStinger();

	/// Copy constructor/disabled
	CStinger(const CStinger &) = delete;

	/// Assignment operator/disabled
	void operator=(const CStinger &) = delete;

	/** \brief Choose a random image
	* \return Image filename*/
	const std::wstring ChooseImage();
};

