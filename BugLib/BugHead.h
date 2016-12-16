/**
 * \file BugHead.h
 *
 * \author Jenn Proos
 *
 * Class that implements a bug head
 */

#pragma once
#include "BugPart.h"
#include "Head.h"


class CBugVisitor;
class CSegment;

/**
* Class that describes a bug head
*/
class CBugHead :
	public CBugPart, public CHead
{
public:
	/// Constructor
	CBugHead(CBugActual *bug);

	/// Destructor
	virtual ~CBugHead();

	/// Copy constructor/disabled
	CBugHead(const CBugHead &) = delete;

	/// Assignment operator/disabled
	void operator=(const CBugHead &) = delete;

	/**
	* Set the position of the head in the basket
	*
	* This position is relative to the basket, so
	* it will be added to the basket location passed
	* to DrawInBasket when we draw it
	* \param x X position in pixels
	* \param y Y position in pixels
	*/
	void SetBasketPosition(int x, int y) override;

	/**
	* Draw the head in the basket
	* \param graphics The graphics object to draw on
	*/
	virtual void DrawInBasket(Gdiplus::Graphics *graphics) override;

	/** \brief Choose a random image
	* \return Image filename*/
	const std::wstring ChooseImage();

	/** \brief Grow bug part
	* \param delta The value to use for calculations*/
	virtual void Grow(double delta);

	/** Accept a visitor 
	* \param visitor The visitor we accept*/
	virtual void Accept(CBugVisitor* visitor) override;

	/** Set this bug head to itself
	* \param self The head to set*/
	void SetSelf(std::shared_ptr<CBugHead> self) { mSelf = self; }

	/** Get this bug head
	* \return the self*/
	std::shared_ptr<CBugHead> GetSelf() { return mSelf.lock(); }

	/**
	* Add children parts to vector of bug parts
	* \param part Child bug part to add
	*/
	virtual void AddChild(std::shared_ptr<CBugPart> part);

	/** \brief Spawn eyes on head*/
	virtual void SpawnPart();


private:
	/// number of eyes
	int mNumEyes = 0;

	/// when this bug head spawned
	double mWhenSpawn = 1.5;

	/// max number of eyes
	int mMaxEyes = 5;

	/// initialized random variable to use
	int mRandom = 0;

	/// The position of the basket
	Gdiplus::Point mBasketPosition = Gdiplus::Point(0, 0);

	/// its self
	std::weak_ptr<CBugHead> mSelf;
	
};

