/**
* \file Basket.cpp
*
* \author Jenn Proos
*
* This is a simple adapter class that routes all of the
* operations to the class CBasketStandin, which is a standin
* for an actual basket in the system.
*/

#include "stdafx.h"
#include "BasketActual.h"
#include "BasketStandin.h"

using namespace Gdiplus;
using namespace std;

const wstring BasketImage = L"images/basket.png";
const wstring BasketFrontImage = L"images/basket-front.png";

/**
 * Constructor
 */
CBasketActual::CBasketActual()
{
	mBasketImage1 = std::make_shared<CBugImage>();
	mBasketImage2 = std::make_shared<CBugImage>();

	mBasketImage1->LoadImage(BasketImage);
	mBasketImage2->LoadImage(BasketFrontImage);
}


/**
 * Destructor
 */
CBasketActual::~CBasketActual()
{
}

void CBasketActual::DrawBasket(Gdiplus::Graphics *graphics)
{
	mBasketImage1->Draw(graphics, false);

	for (auto head : mHeads)
	{
		head->DrawInBasket(graphics);
	}

	mBasketImage2->Draw(graphics, false);
}


void CBasketActual::AddToBasket(std::shared_ptr<CHead> head)
{
	mHeads.push_back(head);
}


void CBasketActual::EmptyBasket()
{
	mHeads.clear();
}
