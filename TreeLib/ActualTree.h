/**
 * \file ActualTree.h
 *
 * \author Tianhang Sun
 *
 * the tree class we actually use
 */

#pragma once
#include "Tree.h"
#include "PseudoRandom.h"
#include "Apple.h"
#include <memory>

class CFruit;
class CTreeComponent;
class CTreeImage;

/** the actual tree class*/
class CActualTree :
	public CTree
{
public:
	CActualTree();
	virtual ~CActualTree();
	/** \brief Copy constructor disabled */
	CActualTree(const CActualTree &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CActualTree &) = delete;

	void SetRootLocation(int x, int y);
	void DrawTree(Gdiplus::Graphics *graphics);
	void SetTreeFrame(int frame);
	void SetWindSpeed(double speed);
	void SetSeed(int seed);
	int GetSeed();
	std::vector<std::shared_ptr<CFruit>> Harvest();
	void SetRoot(std::shared_ptr<CTreeComponent> root);
	void Reset();

	/**getter for PseudoRandom
	* \returns random pointer*/
	std::shared_ptr<CPseudoRandom> GetRandom(){ return mRandom; }

	/**getter for leafImage
	* \returns the leaf image*/
	std::shared_ptr<CTreeImage> GetLeaf(){ return mLeafImage; }

	/**getter for the leaf image
	* \returns the fruit image*/
	std::shared_ptr<CTreeImage> GetFruit(){ return mFruitImage; }

	/**track apples in the tree
	* \param apple is the apple we want to add*/
	void AddApple(std::shared_ptr<CApple> apple){ mApples.push_back(apple); }

private:
	std::shared_ptr<CTreeComponent> mRoot;			///< The root drawable
	Gdiplus::Point mRootLocation;					///< the root location
	int mCurrentFrame = 0;							///< the current frame
	int mSeed = 9187;								///< seed we have
	std::shared_ptr<CPseudoRandom> mRandom;			///< random generator
	std::shared_ptr<CTreeImage> mLeafImage;			///< pointer of leaf image
	std::shared_ptr<CTreeImage> mFruitImage;		///< pointer of fruit image
	std::vector<std::shared_ptr<CApple>> mApples;	///< vector of apples in the tree
};

