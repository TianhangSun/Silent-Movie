/**
 * \file ActualBasket.h
 *
 * \author Tianhang Sun
 *
 * the basket class we actually use
 */

#pragma once
#include "Basket.h"
#include "Fruit.h"
#include "TreeImage.h"
#include "ActualTree.h"
#include <memory>

/** the actual basket class */
class CActualBasket :
	public CBasket
{
public:
	CActualBasket();
	virtual ~CActualBasket();

	/** \brief Copy constructor disabled */
	CActualBasket(const CActualBasket &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CActualBasket &) = delete;

	void SetBasketLocation(int x, int y);
	void DrawBasket(Gdiplus::Graphics *graphics);
	void AddToBasket(std::vector < std::shared_ptr<CFruit>> fruit);
	void EmptyBasket();

	/**getter for random pointer
	* \returns the random*/
	std::shared_ptr<CPseudoRandom> GetRandom(){ return mRandom; }

private:
	Gdiplus::Point mBasketLocation;					///< the basket location

	std::shared_ptr<CTreeImage> mBasketImage1;		///< pointer to basket image
	std::shared_ptr<CTreeImage> mBasketImage2;		///< pointer to front of basket image
	std::vector<std::shared_ptr<CFruit>> mFruit;	///< collected fruit
	std::shared_ptr<CPseudoRandom> mRandom;			///< PseudoRandom
};

