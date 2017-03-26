/**
 * \file Limb.h
 *
 * \author Tianhang Sun
 *
 * the limb class
 */

#pragma once
#include "TreeComponent.h"

class CActualTree;

/**the limb class*/
class CLimb :
	public CTreeComponent
{
public:
	CLimb();
	virtual ~CLimb();
	/** \brief Copy constructor disabled */
	CLimb(const CLimb &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CLimb &) = delete;

	void Draw(Gdiplus::Graphics *graphics, double angle, double x, double y);
	void Grow();
	void Spawn();

	/**set the depth of the limb
	* \param depth the depth we're setting*/
	void SetDepth(int depth){ mDepth = depth; mSpawnFrame =(int)(mSpawnFrame * pow(0.9, mDepth)); }

private:
	double mWidth = 0;			///< the current width of limb
	double mHeight = 0;			///< the current height of limb
	int mDepth = 0;				///< the depth of the limb
	int mSpawnFrame = 100;		///< default frame to spawn, changes when set depth

};

