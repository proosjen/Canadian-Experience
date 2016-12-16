/**
 * \file BasketDrawable.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "BasketDrawable.h"
#include "Basket.h"

 /**
 * \brief Constructor
 * \param name The basket drawable name
 */
CBasketDrawable::CBasketDrawable(const std::wstring &name) :CDrawable(name)
{
}


/**
* Destructor
*/
CBasketDrawable::~CBasketDrawable()
{
}

/**
* \brief Test to see if we clicked on this basket drawable
* \param pos Position we clicked
* \returns True if we clicked on it
*/
bool CBasketDrawable::HitTest(Gdiplus::Point pos)
{
	return false;
}

/**
* \brief Draw the basket drawable
* \param graphics Graphics context to draw on
*/
void CBasketDrawable::Draw(Gdiplus::Graphics * graphics)
{
	double useScale = 0.3;

	auto save = graphics->Save();
	graphics->TranslateTransform(mPosition.X, mPosition.Y);
	graphics->ScaleTransform(useScale, useScale);

	mBasket->DrawBasket(graphics);

	graphics->Restore(save);
}
