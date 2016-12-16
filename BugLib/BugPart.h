/**
 * \file BugPart.h
 *
 * \author Jenn Proos
 *
 * Abstract base class for bug parts
 */

#pragma once

#include <memory>
#include <string>
#include <vector>
#include "BugImage.h"
#include "PseudoRandom.h"
#include "BugVisitor.h"

class CBugActual;

using namespace Gdiplus;

/**
 * \brief Abstract base class for bug parts of our bug.
 * 
 * A bug part is one part of a bug
 */
class CBugPart
{
public:
	/// Destructor
	virtual ~CBugPart();

	/** \brief Copy constructor disabled */
	CBugPart(const CBugPart &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CBugPart &) = delete;

	/**
	* Set our bug 
	* \param bug Bug to set
	*/
	virtual void SetBug(CBugActual *bug);

	/**
	* Get the bug
	* \return The bug
	*/
	CBugActual* GetBug() { return mBug; }	

	/**
	* Add children parts to vector of bug parts
	* \param child Child bug part to add
	*/
	void AddChild(std::shared_ptr<CBugPart> child);

	/** \brief Set the bug part parent
	* \param parent New parent pointer */
	void SetParent(CBugPart *parent) { mParent = parent; }

	/** \brief Get the bug part parent
	* \returns Parent pointer */
	CBugPart *GetParent() { return mParent; }

	/** \brief Get the bug part age
	* \returns Part age */
	double GetAge() { return mAge; }

	/** \brief Set the bug part position
	* \param pos The new bug part position*/
	void SetPosition(Gdiplus::PointF pos) { mPosition = pos; }

	/** \brief Get the bug part position
	* \returns The bug part position*/
	Gdiplus::PointF GetPosition() const { return mPosition; }

	/** The width of the item image
	* \returns Image width */
	double GetPartWidth() const { return mPartImage->GetWidth(); }

	/** The height of the item image
	* \returns Image height */
	double GetPartHeight() const { return mPartImage->GetHeight(); }

	/** \brief Set the bug part angle
	* \param angle The new bug part angle*/
	void SetAngle(double angle) { mAngle = angle; }

	/** \brief Set the left status
	* \param left Boolean left to set*/
	void SetLeft(bool left);

	/** The left status
	* \returns Left status*/
	bool GetLeft() { return mLeft; }

	//bool HitTest(Gdiplus::Point pos);

	/** \brief Is this a left child?
	* \return Left if true*/
	bool IsLeft() { return mLeft; }

	/** \brief Grow bug part
	* \param delta The value to use for calculations*/
	virtual void Grow(double delta);

	/**
	* Load bug image
	* \param filename Image file to load
	*/
	void LoadImage(const std::wstring &filename) { mPartImage->LoadImage(filename); }

	/**
	* \brief Draw the bug part image
	* \param graphics Graphics context to draw on
	*/
	void Draw(Gdiplus::Graphics *graphics);

	/** \brief Get the random generator
	* \return PseudoRandom generator object*/
	std::shared_ptr<CPseudoRandom> GetRandom();

	/** When was this segment spawned?
	* \returns When the segment was spawned */
	int GetWhenSpawn() { return mWhenSpawn; }

	/** Accept a visitor
	* \param visitor The visitor we accept*/
	virtual void Accept(CBugVisitor* visitor);

	/** \brief Remove a bug head after harvested
	* \param head Head to remove*/
	void RemoveHead(std::shared_ptr<CBugPart> head);

protected:
	CBugPart(CBugActual *bug);

	/// The actual postion in the drawing
	Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);

	/// The actual rotation in the drawing
	double mPlacedR = 0;

	/// The center of the image
	Gdiplus::Point mCenter = Gdiplus::Point(0, 0);

	/// The image of the bug part
	std::shared_ptr<CBugImage> mPartImage;

private:
	/// The bug using this bug part
	CBugActual *mBug = nullptr;

	/// The bug part name
	std::wstring mName;

	/// The position of this bug part relative to its parent
	Gdiplus::PointF mPosition = Gdiplus::PointF(0, 0);

	/// The rotation of this bug part relative to its parent
	double mRotation = 0;

	/// The angle of this bug part relative to its root
	double mAngle = 0;

	/// The parent bug part
	CBugPart *mParent = nullptr;

	/// The child bug parts
	std::vector<std::shared_ptr<CBugPart>> mChildren;

	/// Has an image been loaded?
	bool mLoaded = false;

	/// Does this part have a left child?
	bool mLeft = false;

	/// The image mirror status
	bool mMirror;

	/// Time when part is spawn
	int mWhenSpawn = 0;

	double mAge = 0;			///< The age of this bug part
	double mAgeGrown = 1.0;		///< The age that this bug part has grown 
	double mScale = 0.1f;		///< The scale of this bug part image
};

