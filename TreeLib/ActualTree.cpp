/**
 * \file ActualTree.cpp
 *
 * \author Tianhang Sun
 */

#include "stdafx.h"
#include "ActualTree.h"
#include "TreeComponent.h"
#include "Limb.h"
#include "Fruit.h"
#include "TreeImage.h"
#include <memory>

using namespace std;
using namespace Gdiplus;

const double pi = 3.1415926535;		///< you know

/** constructor */
CActualTree::CActualTree()
{
	Reset();
	mLeafImage = std::make_shared<CTreeImage>(L"images/leaf.png");
	mFruitImage = std::make_shared<CTreeImage>(L"images/fruit.png");
}

/**desctructor*/
CActualTree::~CActualTree()
{
}

/**
* Set the position for the root of the tree
* \param x X location (pixels)
* \param y Y location (pixels)
*/
void CActualTree::SetRootLocation(int x, int y)
{
	mRootLocation = Point(x, y);
}

/**
* Draw the tree at the currently specified location
* \param graphics GDI+ Graphics object
*/
void CActualTree::DrawTree(Gdiplus::Graphics *graphics)
{
	mRoot->Draw(graphics, -pi/2, mRootLocation.X, mRootLocation.Y);
}

/**
* Set the current tree frame
* \param frame Frame number
*/
void CActualTree::SetTreeFrame(int frame)
{
	if (frame < mCurrentFrame)
	{
		Reset();
	}

	while (mCurrentFrame < frame) {
		mCurrentFrame++;
		mRoot->Grow();
	}
}

/**
* Set  the wind speed
* \param speed Wind speed in miles per hour
*/
void CActualTree::SetWindSpeed(double speed)
{
	mRoot->SetWindSpeed(speed);
}

/**
* Set the tree seed
* \param seed An integer number. Each number makes a different tree
*/
void CActualTree::SetSeed(int seed)
{
	CTree::SetSeed(seed);
	mSeed = seed;
	mRandom->Seed(mSeed);
}

/**
* Get the current tree seed
* \return Tree seed integer
*/
int CActualTree::GetSeed()
{
	return CTree::GetSeed();
}

/**
* Harvest all of the fruit
* \return Vector of objects of type CFruit
*/
std::vector<std::shared_ptr<CFruit>> CActualTree::Harvest()
{
	std::vector<std::shared_ptr<CFruit>> fruit;
	for (auto apple : mApples)
	{
		fruit.push_back(apple);
	}
	mApples.clear();
	mRoot->ClearApple();
	return fruit;
}

/** \brief Set the root component
* \param root Pointer to root component */
void CActualTree::SetRoot(std::shared_ptr<CTreeComponent> root)
{
	mRoot = root;
}

/** reset function, call in constructor*/
void CActualTree::Reset()
{
	mCurrentFrame = 0;
	mRandom = make_shared<CPseudoRandom>();
	SetSeed(mSeed);
	auto limb = make_shared<CLimb>();
	limb->SetFrame(mCurrentFrame);
	this->SetRoot(limb);
	limb->SetTree(this);
	mApples.clear();
}