/**
 * \file BugHead.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "BugHead.h"
#include "BugActual.h"
#include "BugPart.h"
#include "BugVisitor.h"
#include "Eye.h"

 /// Head 1 image name
const std::wstring Head1ImageName = L"images/head1.png";

/// Head 2 image name
const std::wstring Head2ImageName = L"images/head2.png";

/// Head 3 image name
const std::wstring Head3ImageName = L"images/head3.png";


/**
 * Constructor
 * \param bug 
 */
CBugHead::CBugHead(CBugActual *bug) : CBugPart(bug)
{
	const std::wstring filename = ChooseImage();
	LoadImage(filename);
	mNumEyes = GetRandom()->Random(1, 5);
	mRandom = GetRandom()->Random(0, 4);
}


/**
 * Destructor
 */
CBugHead::~CBugHead()
{
}

void CBugHead::SetBasketPosition(int x, int y)
{
}

void CBugHead::DrawInBasket(Gdiplus::Graphics * graphics)
{
	CBugPart::Draw(graphics);
}

const std::wstring CBugHead::ChooseImage()
{
	int random = GetBug()->GetRandom()->Random(1, 3);

	switch (random) {
	case 1:
		return Head1ImageName;
		break;
	case 2:
		return Head2ImageName;
		break;
	case 3:
		return Head3ImageName;
		break;
	default:
		return Head1ImageName;
		break;
	}
}

void CBugHead::AddChild(std::shared_ptr<CBugPart> part)
{
	CBugPart::AddChild(part);
	part->SetParent(this);
}

void CBugHead::SpawnPart()
{
	if (mNumEyes <= mMaxEyes)
	{
		auto eye = make_shared<CEye>(GetBug(), mRandom);
		eye->SetParent(this);
		eye->SetPosition(PointF((GetRandom()->Random(-30.0, 30.0)),
			(GetRandom()->Random(-30.0, 30.0))));
		AddChild(eye);
		mNumEyes++;
	}
}

void CBugHead::Grow(double delta)
{
	CBugPart::Grow(delta);
	SpawnPart();
}


void CBugHead::Accept(CBugVisitor * visitor)
{
	visitor->VisitBugHead(this);
}


