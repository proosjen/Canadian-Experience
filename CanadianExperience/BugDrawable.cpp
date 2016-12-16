/**
 * \file BugDrawable.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "BugDrawable.h"
#include "BugSeedDlg.h"
#include "Bug.h"
#include "Timeline.h"
#include "Picture.h"
#include "BugFactory.h"

using namespace xmlnode;

 /**
 * \brief Constructor
 * \param name The bug drawable name
 */
CBugDrawable::CBugDrawable(const std::wstring &name) : CDrawable(name)
{
}


/**
 * Destructor
 */
CBugDrawable::~CBugDrawable()
{
}

void CBugDrawable::SetTimeline(CTimeline * timeline)
{
	mTimeline = timeline;
	CDrawable::SetTimeline(timeline);
}

/**
* \brief Test to see if we clicked on this bug drawable
* \param pos Position we clicked
* \returns True if we clicked on it
*/
bool CBugDrawable::HitTest(Gdiplus::Point pos)
{
	return false;
}


/**
* \brief Draw the bug drawable
* \param graphics Graphics context to draw on
*/
void CBugDrawable::Draw(Gdiplus::Graphics * graphics)
{
	double useScale = 0.3;

	auto save = graphics->Save();
	graphics->TranslateTransform(mPosition.X, mPosition.Y);
	graphics->ScaleTransform(useScale, useScale);

	mBug->DrawBug(graphics);

	mBug->SetBugFrame(mTimeline->GetCurrentFrame());

	graphics->Restore(save);
}


void CBugDrawable::ShowDialogBox()
{
	CBugSeedDlg dlg(mBug);

	if (dlg.DoModal() == IDOK)
	{
		// a new seed has been set
	}
}

/**
* \brief Save the timeline animation to a file
* \param root File to save to.
*/
void CBugDrawable::Save(std::shared_ptr<xmlnode::CXmlNode> root)
{
	mSeed = mBug->GetSeed();
	root->SetAttribute(L"seed", mSeed);
}


/**
* \brief Load a timeline animation from a file
* \param root file to load from
*/
void CBugDrawable::Load(std::shared_ptr<xmlnode::CXmlNode> root)
{
	// Get the attributes
	mSeed = root->GetAttributeIntValue(L"seed", 0);
}
