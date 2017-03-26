/**
 * \file Apple.cpp
 *
 * \author Tianhang Sun
 */

#include "stdafx.h"
#include "Apple.h"
#include "ActualTree.h"
#include "TreeImage.h"
#include "ActualBasket.h"

/** constructor */
CApple::CApple()
{
	mType = L"Apple";
}

/** destructor */
CApple::~CApple()
{
}

/** draw apple, call draw in TreeImage
* \param graphics
* \param angle the current angle
* \param x starting x position
* \param y starting y position */
void CApple::Draw(Gdiplus::Graphics *graphics, double angle, double x, double y)
{
	mTree->GetFruit()->Draw(graphics, 3.14, mScale, (x - 100 / 2 * mScale), (y - 115 * mScale));
}

/** draw apple in basket, call draw
* \param graphics
* \param x location of basket
* \param y location of basket */
void CApple::DrawInBasket(Gdiplus::Graphics *graphics, int x, int y)
{
	/// only set location at the first time

	if (mX == 0)
	{
		mX = mBasket->GetRandom()->Random(20, 100);
		mY = mBasket->GetRandom()->Random(-20, 50);
	}
	Draw(graphics, 3.14, x + mX, y + mY);
}