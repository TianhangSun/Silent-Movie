/**
 * \file TreeImage.cpp
 *
 * \author Tianhang Sun
 */

#include "stdafx.h"
#include "TreeImage.h"
#include <memory>
#include <cmath>

using namespace std;
using namespace Gdiplus;

/**constructor
* \param name the filename*/
CTreeImage::CTreeImage(const std::wstring name)
{
	/// load image
	mImage = unique_ptr<Bitmap>(Bitmap::FromFile(name.c_str()));
	if (mImage->GetLastStatus() != Ok){
		wstring msg(L"Failed to open ");
		msg += name;
		AfxMessageBox(msg.c_str());
	}
}

/**draw function
* \param graphics
* \param angle the current angle
* \param scale the size of image
* \param x the location
* \param y the location*/
void CTreeImage::Draw(Gdiplus::Graphics *graphics, double angle, double scale, double x, double y)
{
	// center of rotation, middle bottom point of image
	Point center = Point(x + scale * mImage->GetWidth() / 2, y + scale * mImage->GetHeight());

	Point destinationPoints[] = {
		RotatePoint(Point(-scale * mImage->GetWidth() / 2, -scale * mImage->GetHeight()), angle) + center,
		RotatePoint(Point(scale * mImage->GetWidth() / 2, -scale * mImage->GetHeight()), angle) + center,
		RotatePoint(Point(-scale * mImage->GetWidth() / 2, 0), angle) + center };
	// line1 -- destination for upper-left point of original
	// line2 -- destination for upper-right point of original
	// line3 -- destination for lower-left point of original
	
	graphics->DrawImage(mImage.get(), destinationPoints, 3);
}

/** \brief Rotate a point by a given angle.
* \param point The point to rotate
* \param angle An angle in radians
* \returns Rotated point */
Gdiplus::Point CTreeImage::RotatePoint(Gdiplus::Point point, double angle)
{
	double cosA = cos(angle);
	double sinA = sin(angle);

	return Gdiplus::Point(int(cosA * point.X + sinA * point.Y),
		int(-sinA * point.X + cosA * point.Y));
}
