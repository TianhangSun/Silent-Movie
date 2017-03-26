/**
 * \file ActualBasket.cpp
 *
 * \author Tianhang Sun
 */

#include "stdafx.h"
#include "ActualBasket.h"
#include <memory>

using namespace Gdiplus;

/** constructor */
CActualBasket::CActualBasket()
{
	mBasketImage1 = std::make_shared<CTreeImage>(L"images/basket.png");
	mBasketImage2 = std::make_shared<CTreeImage>(L"images/basket-front.png");
	mRandom = std::make_shared<CPseudoRandom>();
}

/** destructor */
CActualBasket::~CActualBasket()
{
}

/**
* Set the position for the basket.
* \param x X location (pixels)
* \param y Y location (pixels)
*/
void CActualBasket::SetBasketLocation(int x, int y)
{
	mBasketLocation = Point(x, y);
}

/**
* Draw the tree at the currently specified location
* \param graphics GDI+ Graphics object
*/
void CActualBasket::DrawBasket(Gdiplus::Graphics *graphics)
{
	mBasketImage1->Draw(graphics, 0, 1, (int)mBasketLocation.X, (int)mBasketLocation.Y - 120);
	for (auto fruit : mFruit)
	{
		fruit->DrawInBasket(graphics, mBasketLocation.X, mBasketLocation.Y - 100);
	}
	mBasketImage2->Draw(graphics, 0, 1, (int)mBasketLocation.X, (int)mBasketLocation.Y - 120);
}

/**
* Add fruit to the basket
* \param fruit Vector of fruit objects
*/
void CActualBasket::AddToBasket(std::vector < std::shared_ptr<CFruit>> fruit)
{
	for (auto f : fruit)
	{
		f->SetBasket(this);
		mFruit.push_back(f);
	}
}

/**
* Empty all fruit from the basket
*/
void CActualBasket::EmptyBasket()
{
	mFruit.clear();
}