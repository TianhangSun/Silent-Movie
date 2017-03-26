/**
 * \file Apple.h
 *
 * \author Tianhang Sun
 *
 * the apple class
 */

#pragma once
#include "ImageComponent.h"
#include "Fruit.h"

/**apple class*/
class CApple :
	public CImageComponent, public CFruit
{
public:
	CApple();
	virtual ~CApple();

	/** \brief Copy constructor disabled */
	CApple(const CApple &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CApple &) = delete;

	void Draw(Gdiplus::Graphics *graphics, double angle, double x, double y);

	/**function that set the basket position
	* \param x the location
	* \param y the location*/
	void SetBasketPosition(int x, int y){}
	void DrawInBasket(Gdiplus::Graphics *graphics, int x, int y);

};

