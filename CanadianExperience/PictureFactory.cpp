/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "stdafx.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "BugDrawable.h"
#include "BasketDrawable.h"
#include "BugFactory.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/*! \brief Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(550, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(300, 500));
    picture->AddActor(sparty);

	// Create and add bug1
	CBugFactory bugfactory;
	auto bug = bugfactory.CreateBug();

	std::shared_ptr<CBugDrawable> bug1 = make_shared<CBugDrawable>(L"bug1");
	picture->SetBugDrawable(bug1);
	
	bug1->SetBug(bug);
	bug1->SetTimeline(picture->GetTimeline());
	bug1->SetPosition(Point(250, 400));

	std::shared_ptr<CActor> bugActor = make_shared<CActor>(L"bug1actor");
	bugActor->AddDrawable(bug1);
	picture->AddActor(bugActor);

	// Create and add bug2
	CBugFactory bug2factory;
	auto otherbug = bug2factory.CreateBug();

	std::shared_ptr<CBugDrawable> bug2 = make_shared<CBugDrawable>(L"bug2");
	picture->SetOtherBugDrawable(bug2);

	bug2->SetBug(otherbug);
	bug2->SetTimeline(picture->GetTimeline());
	bug2->SetPosition(Point(650, 400));

	std::shared_ptr<CActor> bug2Actor = make_shared<CActor>(L"bug2actor");
	bug2Actor->AddDrawable(bug2);
	picture->AddActor(bug2Actor);

	// Create and add basket
	CBugFactory basketfactory;
	auto basket = basketfactory.CreateBasket();

	std::shared_ptr<CBasketDrawable> basket1 = make_shared<CBasketDrawable>(L"basket");
	basket1->SetBug(basket);
	basket1->SetPosition(Point(850, 300));

	std::shared_ptr<CActor> basketActor = make_shared<CActor>(L"basketactor");
	basketActor->AddDrawable(basket1);
	picture->AddActor(basketActor);

    return picture;
}
