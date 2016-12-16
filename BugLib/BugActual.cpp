/**
 * \file BugActual.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "BugActual.h"
#include "BugVisitor.h"


using namespace Gdiplus;
using namespace std;


CBugActual::CBugActual()
{
	Reset();
}


CBugActual::~CBugActual()
{
}


void CBugActual::SetRoot(std::shared_ptr<CBugPart> root)
{
	mRoot = root;
}

void CBugActual::DrawBug(Gdiplus::Graphics *graphics)
{
	if (mRoot != nullptr)
	{
		mRoot->Draw(graphics);
		mRoot->SetBug(this);
	}
}


/**
* Set the current bug frame
* \param frame Frame number
*/
void CBugActual::SetBugFrame(int frame)
{
	if (frame < mCurrentFrame)
	{
		Reset();
	}

	while (mCurrentFrame < frame) {
		mCurrentFrame++;
		mRoot->Grow(1.0 / mFrameRate);
	}

}


void CBugActual::SetBend(double bend)
{
	//mStandin->SetBendAngle(bend);
}


void CBugActual::SetSeed(int seed)
{
	mRandomGenerator->Seed(seed);
	mSeed = seed;
}

int CBugActual::GetSeed()
{
	return mSeed;
}

std::shared_ptr<CHead> CBugActual::Harvest()
{
	auto bugVisitor = CBugVisitor();
	mRoot->Accept(&bugVisitor);
	mRoot->RemoveHead(bugVisitor.GetBugHead());
	return bugVisitor.GetBugHead();
	
}

void CBugActual::Reset()
{
	mCurrentFrame = 0;

	mRandomGenerator = make_shared<CPseudoRandom>(mSeed);
	mRoot = make_shared<CRootSegment>(this);

	mRandomGenerator->Reset();

	SetRoot(mRoot);
	//SetSeed(mSeed);
}


