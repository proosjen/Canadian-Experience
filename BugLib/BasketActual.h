/**
 * \file BasketActual.h
 *
 * \author Jenn Proos
 *
 * Class that implements an actual basket
 */

#pragma once

#include "Basket.h"
#include "BugImage.h"
#include "Head.h"

/**
 * Class that describes an actual basket
 */
class CBasketActual :
	public CBasket
{
public:
	/// Constructor
	CBasketActual();

	/// Destructor
	virtual ~CBasketActual();

	/// Copy constructor/disabled
	CBasketActual(const CBasketActual &) = delete;

	/// Assignment operator/disabled
	void operator=(const CBasketActual &) = delete;

	/**
	* Draw the basket at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	void DrawBasket(Gdiplus::Graphics *graphics);

	/**
	* Add head to basket
	* \param head Head object
	*/
	void AddToBasket(std::shared_ptr<CHead> head);

	/**
	* Empty all fruit from the basket
	*/
	void EmptyBasket();

private:
	/// The basket standin object
	std::shared_ptr<CBasketStandin> mStandin;

	/// The image of the basket
	std::shared_ptr<CBugImage> mBasketImage1;

	/// The image of the front of the basket
	std::shared_ptr<CBugImage> mBasketImage2;

	/// Vector of heads to draw in basket
	std::vector<std::shared_ptr<CHead> > mHeads;
};

