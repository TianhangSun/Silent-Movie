/**
 * \file BasketDrawable.cpp
 *
 * \author Tianhang Sun
 */

#include "stdafx.h"
#include "BasketDrawable.h"
#include "TreeFactory.h"

/**constructor
* \param name the filename*/
CBasketDrawable::CBasketDrawable(const std::wstring &name) : CDrawable(name)
{
	CTreeFactory factory;
	mBasket = factory.CreateBasket();
}

/**destructor*/
CBasketDrawable::~CBasketDrawable()
{
}

/**the draw function
* \param graphics*/
void CBasketDrawable::Draw(Gdiplus::Graphics *graphics)
{
	Harvest();

	double scale = 0.8;
	auto state = graphics->Save();
	graphics->TranslateTransform((float)mPlacedPosition.X, (float)mPlacedPosition.Y);		// Where you want the tree
	graphics->ScaleTransform((float)scale, (float)scale);
	mBasket->SetBasketLocation(0, 0);
	mBasket->DrawBasket(graphics);
	graphics->Restore(state);

	SetTreeFrame(mPicture->GetTimeline()->GetCurrentFrame() - 100);
	mBasket->DrawBasket(graphics);
}

/**when time reaches some point, do harvest*/
void CBasketDrawable::Harvest()
{
	if (mCurrentFrame > mHarvestFrame && mHarvest == false)
	{
		for (auto t : mTrees)
		{
			auto harvest = t->Harvest();
			mBasket->AddToBasket(harvest);
		}
		mHarvest = true;
	}

	else if (mCurrentFrame <= mHarvestFrame)
	{
		mBasket->EmptyBasket();
		mHarvest = false;
	}
}