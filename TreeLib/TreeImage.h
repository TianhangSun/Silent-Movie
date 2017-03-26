/**
 * \file TreeImage.h
 *
 * \author Tianhang Sun
 *
 * image class, create and draw an image
 */

#pragma once
#include <string>
#include <memory>

/** Class that represents an image used by our system. */
class CTreeImage
{
public:
	CTreeImage(const std::wstring name);

	/// Default constructor/disabled
	CTreeImage() = delete;

	/// Copy constructor/disabled
	CTreeImage(const CTreeImage &) = delete;

	/// Destructor
	virtual ~CTreeImage(){}

	/** \brief Draw the component
	* \param graphics Graphics object to draw on
	* \param angle we're setting
	* \param x the location
	* \param y the location*/
	void Draw(Gdiplus::Graphics *graphics, double angle, double scale, double x, double y);

private:
	std::shared_ptr<Gdiplus::Bitmap> mImage; ///< The part image

	/**rotate point function in drawable
	* \param point the point of rotation
	* \param angle the angle changes*/
	Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);

};

