/**
 * \file Leaf.cpp
 *
 * \author Tianhang Sun
 */

#include "stdafx.h"
#include "Leaf.h"
#include "ActualTree.h"
#include "TreeImage.h"

/** constructor */
CLeaf::CLeaf()
{
}

/** destructor */
CLeaf::~CLeaf()
{
}

/** draw leave, call draw in TreeImage class
* \param graphics Graphics object to draw on
* \param angle we're setting
* \param x the location
* \param y the location*/
void CLeaf::Draw(Gdiplus::Graphics *graphics, double angle, double x, double y)
{
	mTree->GetLeaf()->Draw(graphics, angle + 1.57, mScale, (x - 100 / 2 * mScale), (y - 93 * mScale));
}