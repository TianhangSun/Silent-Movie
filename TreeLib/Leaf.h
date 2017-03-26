 /**
 * \file Leaf.h
 *
 * \author Tianhang Sun
 *
 * the leaf class
 */

#pragma once
#include "ImageComponent.h"

/**the leaf class*/
class CLeaf :
	public CImageComponent
{
public:
	CLeaf();
	virtual ~CLeaf();

	/** \brief Copy constructor disabled */
	CLeaf(const CLeaf &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CLeaf &) = delete;

	void Draw(Gdiplus::Graphics *graphics, double angle, double x, double y);

};

