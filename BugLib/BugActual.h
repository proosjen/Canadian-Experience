/**
 * \file BugActual.h
 *
 * \author Jenn Proos
 *
 * Class that implements an actual bug
 */

#pragma once
#include "Bug.h"
#include "RootSegment.h"
#include "PseudoRandom.h"


/**
 * Class that describes an actual bug
 */
class CBugActual :
	public CBug
{
public:
	/// Constructor
	CBugActual();

	/// Destructor
	virtual ~CBugActual();

	/// Copy constructor/disabled
	CBugActual(const CBugActual &) = delete;

	/// Assignment operator/disabled
	void operator=(const CBugActual &) = delete;

	/**
	* Set the bug root
	* \param root The bug root
	*/
	void SetRoot(std::shared_ptr<CBugPart> root);

	/**
	* Draw the bug at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	void DrawBug(Gdiplus::Graphics *graphics);

	/**
	* Set the current bug animation frame
	* \param frame Frame number
	*/
	void SetBugFrame(int frame);

	/**
	* Set  the bend angle
	* \param bend Bend angle in radians
	*/
	void SetBend(double bend);

	/**
	* Set the bug seed
	* \param seed An integer number. Each number makes a different bug
	*/
	void SetSeed(int seed);

	/**
	* Get the current bug seed
	* \return Bug seed integer
	*/
	int GetSeed();

	/**
	* Get the random generator object
	* \return PseudoRandom object
	*/
	std::shared_ptr<CPseudoRandom> GetRandom() { return mRandomGenerator; }

	/**
	* Harvest the head
	* \return Pointer to a CHead object or null if none to harvest.
	*/
	std::shared_ptr<CHead> Harvest();

	/**
	* Reset stuff
	*/
	void Reset();

private:
	/// The bug standing object
	std::shared_ptr<CBugStandin> mStandin;

	/// The actual bug's root segment
	std::shared_ptr<CBugPart> mRoot;

	/// The current frame
	int mCurrentFrame = 0;

	/// The frame rate
	double mFrameRate = 30;

	/// The PseudoRandom generator object
	std::shared_ptr<CPseudoRandom> mRandomGenerator;

	/// Initial seed set to 0
	int mSeed = 0;
};

