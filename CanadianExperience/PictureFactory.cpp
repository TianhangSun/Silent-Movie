/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "stdafx.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "TreeFactory.h"
#include "TreeDrawable.h"
#include "BasketDrawable.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/*! \brief Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);
	
	// trees
	auto trees = make_shared<CActor>(L"trees");
	trees->SetClickable(false);
	trees->SetPosition(Point(800, 500));
	auto tree1 = make_shared<CTreeDrawable>(L"tree1");
	tree1->SetPicture(picture);
	trees->AddDrawable(tree1);
	trees->SetRoot(tree1);
	picture->AddActor(trees);

	auto trees0 = make_shared<CActor>(L"trees0");
	trees0->SetClickable(false);
	trees0->SetPosition(Point(150, 400));
	auto tree2 = make_shared<CTreeDrawable>(L"tree2");
	tree2->SetPicture(picture);
	tree2->SetSeed(2);
	tree2->SetScale(0.6);
	trees0->AddDrawable(tree2);
	trees0->SetRoot(tree2);
	picture->AddActor(trees0);

	// basket
	auto basket = make_shared<CActor>(L"basket");
	basket->SetClickable(false);
	basket->SetPosition(Point(600, 500));
	auto b = make_shared<CBasketDrawable>(L"b");
	b->SetPicture(picture);
	b->SetBasket(tree1);
	b->SetBasket(tree2);
	basket->AddDrawable(b);
	basket->SetRoot(b);
	picture->AddActor(basket);
	
    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(200, 500));
    picture->AddActor(sparty);

    return picture;
}
