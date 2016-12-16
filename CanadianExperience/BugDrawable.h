/**
 * \file BugDrawable.h
 *
 * \author Jenn Proos
 *
 * \brief Class for bugs in our drawings
 */

#pragma once

#include <memory>

#include "Drawable.h"

class CBug;
class CPicture;


/**
 * \brief Class for bug drawable elements of our picture.
 */
class CBugDrawable :
	public CDrawable
{
public:
	CBugDrawable(const std::wstring &name);
	virtual ~CBugDrawable();

	/** \brief Default constructor disabled */
	CBugDrawable() = delete;

	/** \brief Set the timeline
	* \param timeline The timeline we are setting*/
	virtual void SetTimeline(CTimeline* timeline);

	/** \brief Hit Test for this basket drawable
	* \param pos Position we are testing*/
	bool HitTest(Gdiplus::Point pos) override;

	/**
	* \brief Draw the bug image
	* \param graphics Graphics context to draw on
	*/
	void Draw(Gdiplus::Graphics *graphics) override;

	/**
	* Set the bug
	* \param bug Bug to set
	*/
	void SetBug(std::shared_ptr<CBug> bug) { mBug = bug; }

	/** \brief Get the bug 
	* \return Bug type bug*/
	std::shared_ptr<CBug> GetBug() { return mBug; }

	/** \brief Set the basket drawable position
	* \param pos The new basket drawable position*/
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

	/** \brief Show bug dialog box */
	void ShowDialogBox();

	void Save(std::shared_ptr<xmlnode::CXmlNode> root);

	void Load(std::shared_ptr<xmlnode::CXmlNode> root);

private:
	/// The position of this drawable relative to its parent
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// Pointer to  timeline object
	CTimeline* mTimeline;

	/// The bug object to draw
	std::shared_ptr<CBug> mBug = nullptr;

	/// This bug drawable seed
	int mSeed = 0;
};

