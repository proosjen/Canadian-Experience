/**
 * \file BugPart.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "BugPart.h"
#include "BugActual.h"

using namespace std;
using namespace Gdiplus;

 /// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

/// Min size of this bug part
const double MinSize = 0.1f;

/// Max size of this bug part
const double MaxSize = 1.0f;


void CBugPart::Accept(CBugVisitor * visitor)
{
	for (auto child : mChildren)
	{
		child->Accept(visitor);
	}
}

void CBugPart::RemoveHead(std::shared_ptr<CBugPart> head)
{
	auto it = find(mChildren.begin(), mChildren.end(), head);
	if (it != mChildren.end())
	{
		mChildren.erase(it);
	}

	for (auto child : mChildren)
	{
		child->RemoveHead(head);
	}
}

/**
 * \brief Constructor
 * \param bug The actual bug 
 */
CBugPart::CBugPart(CBugActual *bug) : mBug(bug)
{
	mPartImage = std::make_shared<CBugImage>();
}


CBugPart::~CBugPart()
{
}


void CBugPart::SetBug(CBugActual *bug)
{
	mBug = bug;
}

void CBugPart::SetLeft(bool left) 
{ 
	mLeft = left;
}

void CBugPart::Draw(Gdiplus::Graphics *graphics)
{
	double useScale = mScale;

	auto save = graphics->Save();
	graphics->TranslateTransform(mPosition.X, mPosition.Y);
	graphics->ScaleTransform(useScale, useScale);
	graphics->RotateTransform(mAngle);

	mPartImage->Draw(graphics, mLeft);

	for (auto child : mChildren) {
		child->Draw(graphics);
	}

	graphics->Restore(save);
}

std::shared_ptr<CPseudoRandom> CBugPart::GetRandom()
{
	return mBug->GetRandom();
}

void CBugPart::AddChild(std::shared_ptr<CBugPart> child)
{
	mChildren.push_back(child);
	child->SetParent(this);
}


void CBugPart::Grow(double delta)
{
	mAge += delta;

	if (mAge < mAgeGrown)
	{
		mScale = MinSize + mAge / mAgeGrown * (MaxSize - MinSize);
	}
	else
	{
		mScale = MaxSize;
	}

	for (auto child : mChildren)
	{
		child->Grow(delta);
	}
}


