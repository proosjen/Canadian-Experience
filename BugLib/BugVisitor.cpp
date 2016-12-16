/**
 * \file BugVisitor.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "BugVisitor.h"
#include "BugHead.h"

/**
 * Constructor
 */
CBugVisitor::CBugVisitor()
{
}


/**
 * Destructor
 */
CBugVisitor::~CBugVisitor()
{
}


void CBugVisitor::VisitBugHead(CBugHead* bughead)
{
	mBugHead = bughead->GetSelf();
	bughead->GetParent()->SetParent(false);
	bughead->SetBasketPosition(1, 1);
}
