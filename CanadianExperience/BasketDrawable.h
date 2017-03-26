/**
 * \file BasketDrawable.h
 *
 * \author Tianhang Sun
 *
 * adaptor for basket in treelib
 */

#pragma once
#include "Drawable.h"
#include "Basket.h"
#include "Picture.h"
#include "Tree.h"
#include "TreeDrawable.h"
#include <vector>

/**the basket drawable class*/
class CBasketDrawable :
	public CDrawable
{
public:
	CBasketDrawable(const std::wstring &name);
	virtual ~CBasketDrawable();

	/** \brief Default constructor disabled */
	CBasketDrawable() = delete;
	/** \brief Copy constructor disabled */
	CBasketDrawable(const CBasketDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CBasketDrawable &) = delete;

	/**the hit test, false all the time
	* \param pos the position
	* \returns false*/
	bool HitTest(Gdiplus::Point pos){ return false; }
	void Draw(Gdiplus::Graphics *graphics);

	/**set the frame for basket
	* \param frame the current frame*/
	void SetTreeFrame(int frame){ mCurrentFrame = frame; }

	/**set the picture
	* \param p the picture class*/
	void SetPicture(std::shared_ptr<CPicture> p){ mPicture = p; }
	void Harvest();

	/**link to the tree
	* \param t the tree*/
	void SetBasket(std::shared_ptr<CTreeDrawable> t){ mTrees.push_back(t); }

	/**set harvest frame
	* \param frame the frame to set*/
	void SetHarvestFrame(int frame){ mHarvestFrame = frame - 100; }

	/**get harvest frame
	* \returns harvest frame*/
	int GetHarvestFrame(){ return mHarvestFrame; }

private:
	std::shared_ptr<CBasket> mBasket;						///< the real basket
	int mCurrentFrame = 0;									///< the current frame
	std::shared_ptr<CPicture> mPicture;						///< link to the picture
	std::vector<std::shared_ptr<CTreeDrawable>> mTrees;		///< keep track of trees
	bool mHarvest = false;									///< harvested?
	int mHarvestFrame = 130;								///< frame to do harvest
};

