/**
 * \file Segment.h
 *
 * \author Jenn Proos
 *
 * Class that implements a bug segment
 */

#pragma once

#include "BugPart.h"
#include "Stinger.h"
#include "BugHead.h"

#include <vector>
#include <memory>

using namespace std;

/**
 * Class that describes a bug segment
 */
class CSegment : public CBugPart
{
public:
	/// Constructor
	CSegment(CBugActual *bug);

	/// Destructor
	virtual ~CSegment();

	/// Copy constructor/disabled
	CSegment(const CSegment &) = delete;

	/// Assignment operator/disabled
	void operator=(const CSegment &) = delete;

	/** \brief Add bug part child to vector of bug parts
	* \param child Child bug part to add*/
	void AddChild(std::shared_ptr<CBugPart> child);

	/** \brief Grow bug part
	* \param delta The value to use for calculations*/
	void Grow(double delta);

	/** \brief Choose a random image
	* \return Image filename*/
	const std::wstring ChooseImage();

	/** \brief Spawn a segment, head, or stinger */
	virtual void SpawnPart();

	/** Does this segment have a child?
	* \returns True if it has a child */
	bool GetHasChild() { return mHasChild; }

	/**
	* Set the "has child" status
	* \param hasChild The "has child" status we are setting
	*/
	void SetHasChild(bool hasChild) { mHasChild = hasChild; }

	/** Set the parent segment
	* \param parent The parent to set*/
	void SetParent(CSegment *parent) { mParent = parent; }

private:
	/// The parent segment
	CSegment *mParent = nullptr;

	/// The image of this segment
	std::shared_ptr<CBugImage> mSegmentImage;

	/// Does this part have a child?
	bool mHasChild = false;
};

