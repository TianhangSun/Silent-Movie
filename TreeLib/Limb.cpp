/**
 * \file Limb.cpp
 *
 * \author Tianhang Sun
 */

#include "stdafx.h"
#include "Limb.h"
#include "ActualTree.h"
#include "TreeImage.h"
#include "ImageComponent.h"
#include "Leaf.h"
#include "Apple.h"
#include <memory>

using namespace Gdiplus;
using namespace std;

const double initWidth = 2.5;		///< initial width
const double initHeight = 2;		///< initial height
const double growWidth = 1.025;		///< width growth rate
const double growHeight = 1.045;	///< height growth rate

/** constructor */
CLimb::CLimb()
{
}

/** destructor */
CLimb::~CLimb()
{
}

/** draw a limb, call draw for children
* \param graphics
* \param angle the current angle
* \param x location of limb
* \param y location of limb*/
void CLimb::Draw(Gdiplus::Graphics *graphics, double angle, double x, double y)
{
	double dx = cos(angle) * mHeight;
	double dy = sin(angle) * mHeight;

	Pen pen(Color(139, 69, 19), (REAL)mWidth);
	pen.SetEndCap(LineCapRound);
	graphics->DrawLine(&pen, (REAL)x, (REAL)y,
		(REAL)(x + dx), (REAL)(y + dy));

	/// change wind direction f needed
	if (sin(angle) > 0)
		mWindSpeed = -mWindSpeed;

	/// pass to children
	for (auto i : mChildren)
	{
		i->Draw(graphics, angle + i->GetAngle() + mWindSpeed / 500, x+dx, y+dy);
	}
}

/** grow the limb, call grow for all children */
void CLimb::Grow()
{
	mCurrentFrame++;

	/// actually grow
	if (mCurrentFrame <= mSpawnFrame){
		mWidth = initWidth * pow(growWidth, mCurrentFrame) / (float)pow(mDepth + 1, 0.5);
		mHeight = initHeight * pow(growHeight, mCurrentFrame);
	}

	/// stop growing
	else{
		mWidth = initWidth * pow(growWidth, mSpawnFrame) / (float)pow(mDepth + 1, 0.5);
		mHeight = initHeight * pow(growHeight, mSpawnFrame);
	}

	/// spawn
	Spawn();

	/// pass to children
	for (auto i : mChildren)
	{
		i->Grow();
	}
}

/** spawn function, used in the grow function*/
void CLimb::Spawn()
{
	if (mCurrentFrame == (int)(mSpawnFrame / 10.0) && mDepth < 9){

		/// first leave or limb
		if ((mDepth > 7 && mTree->GetRandom()->Random(0.0, 1.0) < 0.7) || mDepth == 8)
		{
			auto leaf = make_shared<CLeaf>();
			leaf->SetAngle(mTree->GetRandom()->Random(-0.2, 0.2));
			AddChild(leaf);
			leaf->SetTree(mTree);
		}
		else
		{
			auto limb = make_shared<CLimb>();
			limb->SetAngle(mTree->GetRandom()->Random(-0.3, 0.3));
			AddChild(limb);
			limb->SetDepth(mDepth + 1);
			limb->SetTree(mTree);
		}

		/// second apple or limb
		if (mDepth > 7 && mTree->GetRandom()->Random(0.0, 1.0) < 0.1)
		{
			auto apple = make_shared<CApple>();
			apple->SetAngle(mTree->GetRandom()->Random(-0.2, 0.2));
			AddChild(apple);
			apple->SetTree(mTree);
			mTree->AddApple(apple);
		}
		else if (mDepth != 8)
		{
			auto limb = make_shared<CLimb>();
			limb->SetAngle(mTree->GetRandom()->Random(-1.5, 1.5));
			AddChild(limb);
			limb->SetDepth(mDepth + 1);
			limb->SetTree(mTree);
		}
	}
}
