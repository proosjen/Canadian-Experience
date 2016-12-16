/**
 * \file BugImage.h
 *
 * \author Jenn Proos
 *
 * Class that holds and loads our bug images
 */

#pragma once
#include <memory>
#include <string>

using namespace std;

class CBasketActual;
class CBugActual;

/**
 * Class to hold and load bug images
 */
class CBugImage
{
public:
	CBugImage();
	virtual ~CBugImage();

	/** The X location of the item
	* \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/** The width of the item image
	* \returns Image width */
	double GetWidth() const { return mItemImage->GetWidth(); }

	/** The height of the item image
	* \returns Image height */
	double GetHeight() const { return mItemImage->GetHeight(); }

	/**
	* Set the mirror status
	* \param m Status of the mirror
	*/
	void SetMirror(bool m) { mMirror = m; }

	/**
	* \brief Draw the bug image
	* \param graphics Graphics context to draw on
	*\ \param leftChild The left child status*/
	void Draw(Gdiplus::Graphics *graphics, bool leftChild);

	/**
	* Load bug image
	* \param filename Image file to load
	*/
	void LoadImage(const std::wstring &filename);

private:
	/// The basket this item is contained in
	CBasketActual *mBasketActual;

	/// The image of this bug
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	// Item location in the picture
	double mX = 0;		///< X location for the center of the item
	double mY = 0;		///< Y location for the center of the item

	bool mMirror = false;	///< True mirrors the bug image
};

