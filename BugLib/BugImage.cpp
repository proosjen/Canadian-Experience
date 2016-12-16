/**
 * \file BugImage.cpp
 *
 * \author Jenn Proos
 */

#include "stdafx.h"
#include "BugImage.h"
#include "BasketActual.h"
#include "BugActual.h"

using namespace std;
using namespace Gdiplus;


/**
 * Constructor
 */
CBugImage::CBugImage()
{

}


/**
 * Destructor
 */
CBugImage::~CBugImage()
{
}


void CBugImage::Draw(Gdiplus::Graphics *graphics, bool leftChild)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	if (leftChild)
	{
		graphics->DrawImage(mItemImage.get(), 0.0, (float)(-hit / 2),
			-(float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
		//SetMirror(true);
	}
	else
	{
		graphics->DrawImage(mItemImage.get(), 0.0, -float(hit / 2),
			(float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
		//SetMirror(false);
	}
}


void CBugImage::LoadImage(const std::wstring &filename)
{
	mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mItemImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}