/**
 * \file BugVisitor.h
 *
 * \author Jenn Proos
 *
 * Bug visitor for harvesting heads
 */

#pragma once

#include <vector>
#include <memory>

using namespace std;

class CBugHead;


/**
 * Bug visitor class
 */
class CBugVisitor
{
public:
	CBugVisitor();
	virtual ~CBugVisitor();

	/** Visit a CBugHead object
	* \param bughead Bug head we are visiting*/
	virtual void VisitBugHead(CBugHead* bughead);

	/** \brief Get the bug head we are visiting
	* \return The bug head*/
	std::shared_ptr<CBugHead> GetBugHead() { return mBugHead; }

private:
	/// The bug head we are visiting
	std::shared_ptr<CBugHead> mBugHead;
};

