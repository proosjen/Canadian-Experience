/**
 * \file RootSegment.h
 *
 * \author Jenn Proos
 *
 * Class that implements a root segment
 */

#pragma once
#include "Segment.h"


/**
 * Class that describes a root segment
 */
class CRootSegment :
	public CSegment
{
public:
	CRootSegment(CBugActual *bug);

	/// Destructor
	virtual ~CRootSegment();

	/// Copy constructor/disabled
	CRootSegment(const CRootSegment &) = delete;

	/// Assignment operator/disabled
	void operator=(const CRootSegment &) = delete;

	/** \brief Spawn a segment, head, or stinger */
	void SpawnPart();

	/** \brief Grow bug part
	* \param delta The value to use for calculations*/
	void Grow(double delta);
};

