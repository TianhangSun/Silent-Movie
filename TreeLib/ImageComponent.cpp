/**
 * \file ImageComponent.cpp
 *
 * \author Tianhang Sun
 */

#include "stdafx.h"
#include "ImageComponent.h"
#include "ActualTree.h"
#include "TreeImage.h"

const int stopFrame = 100;		///< stop frame

/** constructor */
CImageComponent::CImageComponent()
{
}

/** destructor */
CImageComponent::~CImageComponent()
{
}

/** grow function */
void CImageComponent::Grow()
{
	mCurrentFrame++;
	if (mCurrentFrame <= stopFrame){
		mScale = (float)mCurrentFrame / 400;
	}
	else{
		mScale = 0.25;
	}
}
