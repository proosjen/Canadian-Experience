/**
 * \file BasketDrawable.h
 *
 * \author Jenn Proos
 *
 * \brief Class for basket in our drawings
 */

#pragma once
#include "Drawable.h"

class CBasket;

/**
* \brief Class for basket drawable elements of our picture.
*/
class CBasketDrawable :
	public CDrawable
{
public:
	CBasketDrawable(const std::wstring &name);
	virtual ~CBasketDrawable();

	/** \brief Default constructor disabled */
	CBasketDrawable() = delete;

	/** \brief Hit Test for this basket drawable
	* \param pos Position we are testing*/
	bool HitTest(Gdiplus::Point pos) override;

	/**
	* \brief Draw the bug image
	* \param graphics Graphics context to draw on
	*/
	void Draw(Gdiplus::Graphics *graphics) override;
	
	/**
	* Set the basket 
	* \param basket Basket to set
	*/
	void SetBug(std::shared_ptr<CBasket> basket) { mBasket = basket; }

	/** \brief Set the basket drawable position
	* \param pos The new basket drawable position*/
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

private:
	/// The position of this drawable relative to its parent
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// The basket object to draw
	std::shared_ptr<CBasket> mBasket;
};



