 /**
 * \file ImageComponent.h
 *
 * \author Tianhang Sun
 *
 * base class for leaf and apple
 */

#pragma once
#include "TreeComponent.h"

class CActualTree;

/**the tree component which requires an image*/
class CImageComponent :
	public CTreeComponent
{
public:
	CImageComponent();
	virtual ~CImageComponent();

	/** \brief Copy constructor disabled */
	CImageComponent(const CImageComponent &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CImageComponent &) = delete;

	void Grow();

	/** draw function, overide in derived class
	* \param graphics
	* \param angle the current angle
	* \param x the location
	* \param y the y location*/
	virtual void Draw(Gdiplus::Graphics *graphics, double angle, double x, double y){}

protected:
	int mCurrentFrame = 0;		///< the current frame
	double mScale = 0;			///< the scale
};

